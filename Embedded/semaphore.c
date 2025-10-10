#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int shared_data = 0;

pthread_mutex_t lock;

void* criticalSection(void *arg)
{
	sem_wait(&semaphore); //semaphore based
	
	pthread_mutex_lock(&lock);
	
	shared_data +=1;
	
	pthread_mutex_unlock(&lock);
	
	//IF USING SEMAPHORE BASED
	// sem_pos(&semaphore); //critical section
	return NULL;
}

int main()
{
	pthread_t t1, t2;
	pthread_mutex_init(&lock, NULL);
	
	pthread_create(&t1, NULL, criticalSection, NULL);
	pthread_create(&t2, NULL, criticalSection, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
}
