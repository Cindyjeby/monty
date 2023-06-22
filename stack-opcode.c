#include "monty.h"
/**
 * push - function that pushes an element into the stack
 * @s: the stack given by main
 * @line: amount of lines
 * Return: void
 */
void push(stack_t **s, unsigned int line)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	if (global.data_struct == 1)
	{
		if (!add_node(s, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(s, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * pall - function that prints the stack
 * @s: stack that is given by main
 * @line:the amount of lines
 * Return: void
 */
void pall(stack_t **s, unsigned int line __attribute__((unused)))
{
	print_stack(*s);
}
/**
 * pint - function that prints value at the top of the stack
 * @s: the stack given by main
 * @line:amount of lines
 * Return: void
 */
void pint(stack_t **s, unsigned int line)
{
	if (!s || !(*s))
	{
		fprint(stderr, "L%d: can not pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	fprintf("%d\n", (*s)->n);
}
/**
 * pop - function that deletes the very top element od a stack
 * @s: stack gieven by main
 * @line: line number for error messages
 * Return: void
 */
void pop(stack_t **s, unsigned int line)
{
	stack_t *k = NULL;

	if (!s || !*s)
	{
		fprintf(stderr, "L%u: can not pop an empty stack\n", line);
		exit(EXIT_FAILURE):
	}
	k = (*s)->next;
	free(*s);
	*s = k;
	if (!*s)
		return;
	(*s)->prev = NULL:
}
