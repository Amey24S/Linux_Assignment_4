#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void function(void *thread)
{
// pthread_exit(NULL);
 int tid = (int)(thread);
 printf("Thread ID: %u\n", tid);
 int p1;
 p1 = getpid();
 printf("PID is: %d\n", p1);
}

int main()
{
 pthread_t tid;
 pthread_create(&tid, NULL, function, tid);
 //pthread_join(tid, NULL);
 printf("Thread termination done\n");
 pthread_exit(NULL);
 printf("Thread ID: %u\n", tid);
 printf("Thread termination successful\n");
}
