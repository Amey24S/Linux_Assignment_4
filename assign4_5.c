#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

pthread_spinlock_t spin1;

void *function(void *i)
{
int ret;

printf("Thread %d trying to get spinlock\n",(int *)i);
ret = pthread_spin_lock(&spin1);

sleep(3);
printf("Thread %d acquired spinlock now\n", (int *)i);
printf("Thread %d unlock the spinlock\n", (int *)i);
ret = pthread_spin_unlock(&spin1);

printf("Thread %d done\n", (int *)i);
return NULL;
}

int main()
{
int ret=0;
pthread_t t1;

pthread_spin_init(&spin1, PTHREAD_PROCESS_SHARED);

printf("Process acquire lock\n");
ret = pthread_spin_lock(&spin1);

printf("Process create a lock thread\n");
ret = pthread_create(&t1, NULL, function, (int *)1);
sleep(6);

printf("Process unlock now\n");
ret = pthread_spin_unlock(&spin1);
//sleep(2);

ret = pthread_join(t1, NULL);

printf("Complete\n");
return 0;
}
