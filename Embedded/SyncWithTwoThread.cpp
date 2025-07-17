#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int ready = 0;

void* thread1_func(void* arg)
{
    printf("Thread 1: Doing some work...\n");
    sleep(1);  // Simulate work

    pthread_mutex_lock(&lock);
    ready = 1;
    printf("Thread 1: Work done, signaling Thread 2\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);

    return NULL;
}

void* thread2_func(void* arg)
{
    pthread_mutex_lock(&lock);
    while (!ready)
    {
        printf("Thread 2: Waiting for signal from Thread 1...\n");
        pthread_cond_wait(&cond, &lock);  // Wait until signaled
    }
    printf("Thread 2: Received signal, continuing work.\n");
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1_func, NULL);
    pthread_create(&t2, NULL, thread2_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}
