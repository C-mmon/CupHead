#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_THREADS 5
#define MAX_IMAGES 20

char* url_queue[MAX_IMAGES];
int queue_size = 0;
int next_index = 0;
int completed = 0;

pthread_mutex_t queue_lock = PTHREAD_MUTEX_INITIALIZER;

void download_image(const char* url, int tid) {
    printf("[Thread %d] Downloading %s\n", tid, url);
    sleep(rand() % 3 + 1);  // Simulate variable network delay
    printf("[Thread %d] Done with %s\n", tid, url);
}

// Worker thread function
void* worker_func(void* arg) {
    int tid = *(int*)arg;
    free(arg);  // Free memory after retrieving the ID

    while (1) {
        pthread_mutex_lock(&queue_lock);

        if (next_index >= queue_size) {
            pthread_mutex_unlock(&queue_lock);
            break;  // All jobs assigned
        }

        char* url = url_queue[next_index++];
        pthread_mutex_unlock(&queue_lock);

        download_image(url, tid);

        pthread_mutex_lock(&queue_lock);
        completed++;
        pthread_mutex_unlock(&queue_lock);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    // Fill the job queue
    for (int i = 0; i < MAX_IMAGES; i++) {
        url_queue[i] = malloc(64);
        snprintf(url_queue[i], 64, "http://example.com/image_%d.jpg", i);
    }
    queue_size = MAX_IMAGES;

    pthread_t threads[MAX_THREADS];

    // Launch worker threads
    for (int i = 0; i < MAX_THREADS; i++) {
        int* tid = malloc(sizeof(int));
        *tid = i;
        pthread_create(&threads[i], NULL, worker_func, tid);
    }

    // Join all threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    for (int i = 0; i < MAX_IMAGES; i++) {
        free(url_queue[i]);
    }

    pthread_mutex_destroy(&queue_lock);

    printf("Main: All downloads complete (%d images).\n", completed);
    return 0;
}
