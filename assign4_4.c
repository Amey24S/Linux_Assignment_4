#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *function(void *thread)
{
 int tid = (int)(thread);
 printf("Thread ID: %u\n", tid);
}

int main()
{
 pthread_t tid;
 struct sched_param data;
 int priority, policy, i;

 pthread_create(&tid, NULL, function, tid);
 pthread_join(tid, NULL);
 
 i = pthread_getschedparam (pthread_self(), &policy, &data);
 
 printf("Getting default policy & priorities\n");
 printf("Policy: %d\n", policy);
 printf("Priority: %d\n", data.sched_priority);

 policy = SCHED_FIFO;
 data.sched_priority = 50;

 pthread_setschedparam (pthread_self(), policy, &data);
 pthread_getschedparam (pthread_self(), &policy, &data);

 printf("Setting FIFO policy\n");
 printf("Policy: %d\n", policy);
 printf("Priority: %d\n", data.sched_priority);

 return 0;
}

