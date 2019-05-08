#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 10

typedef struct {
	char type; 
	int amount; 
	char unit; 
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void print(){
	printf("first = %d\t last = %d\n", first, last);
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

int main(){
	item* number1 = init('4',0,'6');
	item* number2 = init('3',7,'1');
	produce(number1);
	produce(number2);
	consume();
	return 0;
}
