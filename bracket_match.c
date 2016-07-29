#include <stdio.h>
#include <string.h>
#include "stack.h"

int MatchBracket(char ch1, char ch2);

int main(void)
{
	STACK s;
	char element[NUM] = { 0 };
	char buffer;
	int i;

	InitStack(&s);

	printf("input brackets:\n");
	fscanf(stdin, "%s", element);

	for (i = 0; element[i] != 0; i++) {
		switch (element[i]) {
		case '(':
		case '[':
		case '{':
		case '<':
			PushStack(&s, element[i]);
			break;

		case ')':
		case ']':
		case '}':
		case '>':
		default:
			if (IsEmpty(&s)) {
				printf("\nnot match\n");
				return 0;
			} else
			{
				if (MatchBracket(s.array[s.top], element[i]))
					PopStack(&s, &buffer);
				else {
					printf("\nnot match\n");
					return 0;
				}
			}
		}
	}
	if (IsEmpty(&s)) {
		printf("\nleft and right brackets are matched");
	} else {
		printf("\nnot match");
	}
	printf("\n");
	return 0;
}


int MatchBracket(char ch1, char ch2)
{
	if (ch1 == '(' && ch2 == ')') {
		return 1;
	}
	if (ch1 == '[' && ch2 == ']') {
		return 1;
	}
	if (ch1 == '{' && ch2 == '}') {
		return 1;
	}
	if (ch1 == '<' && ch2 == '>') {
		return 1;
	}
	return 0;
}
