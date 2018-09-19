#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sched.h>


#define BUFFER_SIZE 3
static int buf[BUFFER_SIZE];
static int current = 0;

static int producer_thread_sleeps = 0;
static int consumer_thread_sleeps = 0;

void suspend(int* flag){
	*flag = 1;
	while(*flag){
		sched_yield();
	};
};

void wakeup(int* flag){
	*flag = 0;
};


void* producer_thread(void* arg){
	int value;
	while(1){
		value = 1; /* it would be better to receive this value from user but the statemant of the exercise recommends to avoid any IO actions */
		if(current == BUFFER_SIZE){
			suspend(&producer_thread_sleeps);
		};
		buf[current++] = value;
		if(current == 1){
			wakeup(&consumer_thread_sleeps);
		};
		usleep(rand() % 10 * 1000);
	};
};

void* consumer_thread(void* arg){
	int value;
	while(1){
		if(!current){
			suspend(&consumer_thread_sleeps);
		};
		value = buf[current--]; /* it would be better to print this value but the statemant of the exercise recommends to avoid any IO actions */
		if(current == BUFFER_SIZE - 1){
			wakeup(&producer_thread_sleeps);
		};
		usleep(rand() % 10 * 1000);
	};
};

void* observer_thread(void* arg){
	while(1){
		printf("current = %d,\tproducer_thread_sleeps = %d,\tconsumer_thread_sleeps = %d\n", current, producer_thread_sleeps, consumer_thread_sleeps);
		if(producer_thread_sleeps && consumer_thread_sleeps){
			puts("Race condition happend!");
			return NULL;
		}
		sleep(1); /* the statement of the exercise recommends to sleep for a minute but this is not confortable to wait the whole minute */
	};
};

int main(){
	pthread_t producer, consumer, observer;
	pthread_create(&producer, NULL, producer_thread, NULL);
	pthread_create(&consumer, NULL, consumer_thread, NULL);
	pthread_create(&observer, NULL, observer_thread, NULL);
	pthread_join(observer, NULL);
	return 0;
}
