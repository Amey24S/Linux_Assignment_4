#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

pthread_once_t one = PTHREAD_ONCE_INIT;
void *function(void)
{
 printf("Function initializing once\n");
}

void *function1(void *thread)
{
 /*int t1 = (int)(thread);
 printf("Value: %ld\n",pthread_self());
 printf("Thread 1: %u\n", t1);
 pthread_once(&one, (void *)function);
 //printf("Value: %ld\n",pthread_self());
 int t2 = (int)(thread);
 printf("Value: %ld\n",pthread_self());
 printf("Thread2: %u\n", t2);*/

 int t1 = (int)(thread);
 printf("Value of thread: %u\n", t1);
 pthread_once(&one, (void *)function);
 printf("Exit from the thread\n");
}

int main()
{
 pthread_t t1, t2;

 pthread_create(&t1, NULL, function1, (void *)t1);
 pthread_create(&t2, NULL, function1, (void *)t2);

 pthread_join(t1, NULL);
 pthread_join(t2, NULL);

 //pthread_exit(NULL);
}
