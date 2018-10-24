#ifndef TERM_H
#define TERM_H

typedef enum { OPERATOR, OPERAND, } Type;

typedef struct{
	Type type;
	union
	{
		double operand;
		char operator;
	}
}Term;

#endif
