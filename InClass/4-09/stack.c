#include <stdio.h>
#include "stack.h"

void push(Stack* stack, double value){
	if(stack -> size == stack -> capacity)
	{
		stack->capcity *= 2;
		stack->values = (double*)realloc(stack->values, sizeof(double)*stack->capacity);
	}
	
	stack->values[stack->size] = value;
	stack->size++;
}
double pop(Stack* stack){
	stack->size--;
	return stack->values[stack->size];
}
double top(Stack* stack){
	return stack->values(stack->size-1);
}


