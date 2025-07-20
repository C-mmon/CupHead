#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRINTS 100         /* how many times each thread should print */

static int countState = 1;    /* shared counter */
static int turn       = 0;    /* 0 = T1, 1 = T2, 2 = T3 */

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  cv  = PTHREAD_COND_INITIALIZER;

/* ---------- worker ----------------------------------------------- */
static void *worker(void *arg)
{
    int id = *(int *)arg;     /* 0, 1 or 2 */
    free(arg);

    for (int i = 0; i < NUM_PRINTS; ++i) {
        pthread_mutex_lock(&mtx);

        /* wait until it is *our* turn */
        while (turn != id)
            pthread_cond_wait(&cv, &mtx);

        /* --- critical section: produce output -------------------- */
        if (countState & 1)               /* odd => print 0 */
            printf("%d", 0);
        else                              /* even => print n / 2 */
            printf("%d", countState / 2);

        countState++;                     /* advance state        */
        turn = (turn + 1) % 3;            /* next thread's turn   */

        pthread_cond_broadcast(&cv);      /* wake everyone        */
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

/* ---------- main -------------------------------------------------- */
int main(void)
{
    pthread_t tid[3];

    for (int i = 0; i < 3; ++i) {
        int *arg = malloc(sizeof *arg);
        *arg = i;                         /* pass thread ID 0/1/2 */
        pthread_create(&tid[i], NULL, worker, arg);
    }

    for (int i = 0; i < 3; ++i)
        pthread_join(tid[i], NULL);

    putchar('\n');
    return 0;
}
