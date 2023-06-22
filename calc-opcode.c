#include "monty.h"
/**
 * add - function that adds the first two nodes of a stack
 * @s: the given stack by main
 * @line: amount od lines
 * Return: void
 */
void add(stack_t **s, unsigned int line)
{
	int amount;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: can not add, stack tooshort\n", line);
		exit (EXIT_FAILURE);
	}
	amount = ((*s)->next->n) + ((*s)->n);
	pop(s, line);
	(*s)->n = amount;
}
/**
 * sub - function that subtracts the first two nodes of the stack
 * @s: stack given by main
 * @line: amount of lines in the stack
 * Return: void
 */
void sub(stack_t **s, unsigned int line)
{
	int amount;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: cannot sub , stack is too short\n", line);
		exit(EXIT_FAILURE);
	}
	amount = ((*s)->next->n) - ((*s)->n);
	pop(s, line);
	(*s)->n = amount;
}
/**
 * mul - function that multiplies the top stacks
 * @s: stack given by main
 * @line: amount of lines
 * Return: void
 */
void mul(stack_t **s, unsigned int line)
{
	int amount;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: can not multiply, stack too short\n", line);
		exit(EXIT_FAILURE);
		return;
	}
	amount = ((*s)->next->n) * ((*s)->n);
	pop(s, line):
		(*s)->n = amount;
}
/**
 * div - function that divides the next top values
 * @s: stack given by main
 * @line: amount of line
 * Return: void
 */
void div(stack_t **s, unsigned int line)
{
	int amount;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: can not divide, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (((*s)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
		;
		return;
	}
	amount = ((*s)->next->n) / ((*s)->n);
	pop(s, line);
	(*s)->n = amount;
}
/**
 * mod - function that computes the reminder of the division
 * @s: stack given to main
 * @line: amount of lines
 * Return: void
 */
void mod(stack_t **s, unsigned int line)
{
	int amount;
	if (!s || !**s || !((*s)->next))
	{
		fprintf(stderr, "L%d: cannot mod, satck too short\n", line);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*s)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
		return;
	}
	amount = ((*s)->next->n) % ((*s)->n);
	pop(s, line);
	(*s)-> = amount;
}
