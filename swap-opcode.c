#include "monty.h"
/**
 * swap - function that swaps data from top to prev
 * @s: given bymain
 * @line: amount of lines
 * Return: void
 */
void swap(stack_t **s, unsigned int line)
{
	stack_t *k = NULL;
	int j = 0;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: can not swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	k = *s;
	j = k->n;
	k->n = j;

	k->n = k->next->n;
	k->next->n = j;
}
/**
 * nop - function that does nothing
 * @s: is not acounted for
 * @line: nothing
 * Return: void
 */
void nop(stack_t **s, unsigned int line)
{
	(void) s;
	(void) line;
}
