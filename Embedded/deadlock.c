#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // For sleep()
pthread_mutex_t resource_a;
pthread_mutex_t resource_b;

void* thread_one_logic(void* arg) {
    """
    This function represents the logic for the first thread.
    It will lock resource_a and then try to lock resource_b.
    """
    printf("Thread 1: Starting.\n");

    printf("Thread 1: Attempting to lock resource A...\n");
    pthread_mutex_lock(&resource_a);
    printf("Thread 1: Locked resource A.\n");

    // We add a small sleep here to make it more likely that the OS
    // schedules the other thread to run, ensuring the deadlock.
    sleep(1);

    printf("Thread 1: Attempting to lock resource B...\n");
    // This next line is where Thread 1 will get stuck.
    // It's waiting for resource_b, which will be held by Thread 2.
    pthread_mutex_lock(&resource_b);
    printf("Thread 1: Locked resource B.\n");

    // --- This part of the code will never be reached ---
    printf("Thread 1: Releasing resources.\n");
    pthread_mutex_unlock(&resource_a);
    pthread_mutex_unlock(&resource_b);

    printf("Thread 1: Finished.\n");
    return NULL;
}

void* thread_two_logic(void* arg) {
    """
    This function represents the logic for the second thread.
    It will lock resource_b and then try to lock resource_a,
    creating the circular wait condition for the deadlock.
    """
    printf("Thread 2: Starting.\n");

    printf("Thread 2: Attempting to lock resource B...\n");
    pthread_mutex_lock(&resource_b);
    printf("Thread 2: Locked resource B.\n");

    // We add a small sleep here as well.
    sleep(1);

    printf("Thread 2: Attempting to lock resource A...\n");
    // This next line is where Thread 2 will get stuck.
    // It's waiting for resource_a, which is held by Thread 1.
    pthread_mutex_lock(&resource_a);
    printf("Thread 2: Locked resource A.\n");

    // --- This part of the code will never be reached ---
    printf("Thread 2: Releasing resources.\n");
    pthread_mutex_unlock(&resource_b);
    pthread_mutex_unlock(&resource_a);

    printf("Thread 2: Finished.\n");
    return NULL;
}

int main() {
    // Declare thread identifiers
    pthread_t t1, t2;

    printf("Main: Starting deadlock demonstration.\n");

    // Initialize the mutexes. This must be done before they are used.
    if (pthread_mutex_init(&resource_a, NULL) != 0 || pthread_mutex_init(&resource_b, NULL) != 0) {
        printf("\n mutex init failed\n");
        return 1;
    }

    // Create the two threads, passing their respective logic functions
    pthread_create(&t1, NULL, thread_one_logic, NULL);
    pthread_create(&t2, NULL, thread_two_logic, NULL);

    // Wait for the threads to complete. In this case, they never will,
    // and the main function will be blocked here forever.
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // --- This part of the code will also never be reached ---
    // Clean up the mutexes
    pthread_mutex_destroy(&resource_a);
    pthread_mutex_destroy(&resource_b);
    
    printf("Main: Finished.\n");

    return 0;
}
