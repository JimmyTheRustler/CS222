#ifndef STACK_H
#define STACK_H



typedef struct
{
	double* values;
	int size;
	int capacity;
}stack;

void push(Stack* stack, double value);
double pop(Stack* stack);
double top(Stack* stack);


#endif
