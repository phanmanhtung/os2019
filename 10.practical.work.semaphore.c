#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#define BUFFER_SIZE 10

typedef struct {
	char type; 
	int amount; 
	char unit; 
} item;

item buffer[BUFFER_SIZE];
sem_t v;
int first = 0;
int last = 0;

void print(){
	printf("first = %d ; last = %d\n", first, last);
	return;
}

item* consume(){
	item* i = malloc(sizeof(item));
	while (first == last){
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	print();
	return i;
}

void produce(item *i){
	while ((first + 1) % BUFFER_SIZE == last){
	}

	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
	print();
}

item* init(char type, int amount, char unit){
	item* i = malloc(sizeof(item));
	i->type = type;
	i->amount = amount;
	i->unit = unit;
	return i;
}

void *producerThread(void* par) {
	sem_wait(&v);
	item *chicken1=init('0',3,'0');
	item *chicken2=init('0',4,'1');
	item *chicken3=init('0',2,'1');
	produce(chicken1);
	produce(chicken2);
	produce(chicken3);
	sem_post(&v);
	pthread_exit(NULL);
}

void *consumerThread(void* par) {
	printf("Consume 2 chicken wings!\n");
	sem_wait(&v);
	consume();
	consume();
	sem_post(&v);
	pthread_exit(NULL);
}

int main() {
	pthread_t tid;
	sem_init(&v,0,1);
	printf("Main thread here\n");

	pthread_create(&tid, NULL, producerThread, NULL);
	printf("producing Consumer Thread \n");
	pthread_create(&tid, NULL, consumerThread, NULL);
	pthread_join(tid, NULL);
	pthread_join(tid, NULL);
	pthread_exit(NULL);

}

