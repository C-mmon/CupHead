#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_READERS 3
#define BUFFER_SIZE 5
#define NUM_READERS 5
#define NUM_WRITERS 2
#define LOOPS 5

typedef struct {
    int data[BUFFER_SIZE];
    int front;
    int rear;
    int count;
} Buffer;

// Shared resources
Buffer buffer = {.front = 0, .rear = 0, .count = 0};
pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
sem_t reader_slots;

void buffer_push(int item) {
    buffer.data[buffer.rear] = item;
    buffer.rear = (buffer.rear + 1) % BUFFER_SIZE;
    buffer.count++;
}

int buffer_pop() {
    int item = buffer.data[buffer.front];
    buffer.front = (buffer.front + 1) % BUFFER_SIZE;
    buffer.count--;
    return item;
}

void* reader(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < LOOPS; ++i) {
        sem_wait(&reader_slots); // acquire a reader slot

        pthread_mutex_lock(&buffer_mutex);
        while (buffer.count == 0) {
            printf("Reader %d waiting: buffer empty.\n", id);
            pthread_cond_wait(&not_empty, &buffer_mutex);
        }
        int item = buffer_pop();
        printf("Reader %d consumed: %d\n", id, item);
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&buffer_mutex);

        sem_post(&reader_slots); // release the slot

        usleep((rand() % 400 + 100) * 1000); // sleep 100-500ms
    }
    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < LOOPS; ++i) {
        int item = id * 100 + i;

        pthread_mutex_lock(&buffer_mutex);
        while (buffer.count == BUFFER_SIZE) {
            printf("Writer %d waiting: buffer full.\n", id);
            pthread_cond_wait(&not_full, &buffer_mutex);
        }
        buffer_push(item);
        printf("Writer %d produced: %d\n", id, item);
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&buffer_mutex);

        usleep((rand() % 400 + 100) * 1000); // sleep 100-500ms
    }
    return NULL;
}

int main() {
    pthread_t r_threads[NUM_READERS], w_threads[NUM_WRITERS];
    int r_ids[NUM_READERS], w_ids[NUM_WRITERS];

    srand(time(NULL));
    sem_init(&reader_slots, 0, MAX_READERS);

    for (int i = 0; i < NUM_WRITERS; ++i) {
        w_ids[i] = i + 1;
        pthread_create(&w_threads[i], NULL, writer, &w_ids[i]);
    }
    for (int i = 0; i < NUM_READERS; ++i) {
        r_ids[i] = i + 1;
        pthread_create(&r_threads[i], NULL, reader, &r_ids[i]);
    }

    for (int i = 0; i < NUM_WRITERS; ++i) {
        pthread_join(w_threads[i], NULL);
    }
    for (int i = 0; i < NUM_READERS; ++i) {
        pthread_join(r_threads[i], NULL);
    }

    sem_destroy(&reader_slots);
    pthread_mutex_destroy(&buffer_mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);

    return 0;
}
