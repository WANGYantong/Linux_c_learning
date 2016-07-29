#ifndef STACK_H
#define STACK_H

#define NUM		20
typedef struct stack {
	char array[NUM];
	int top;
} STACK;

void InitStack(STACK *s)
{
	s->top = -1;
}

/* remember to check the stack is full or not */
int PushStack(STACK *s, char ch)
{
	if (s->top < NUM) {
		s->top++;
		s->array[s->top] = ch;

		return 1;
	} else
		return 0;
}

/* remember to check the stack is empty or not */
/* besides, ch should be point type if you want to keep the change when go back */
int PopStack(STACK *s, char *ch)
{
	if (s->top >= 0) {
		*ch = s->array[s->top];
		s->top--;

		return 1;
	} else
		return 0;
}

int IsEmpty(STACK *s)
{
	if (s->top < 0)
		return 1;
	else
		return 0;
}

#endif
