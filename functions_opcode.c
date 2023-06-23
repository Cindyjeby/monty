#include "monty.h"
/**
 * pchar - function that prints the int at the top of the stck as char
 * @s: given by main
 * @line: the amount of lines
 * Return: void
 */
void pchar(stack_t **s, unsigned int line)
{
	if (!s || !(*s))
	{
		fprintf(stderr, "L%d: can not pchar, stck empty\n", line);
		exit(EXIT_FAILURE);
		return;
	}
	if ((*s)->n < 0 || (*s)->n > 127)
	{
		fprintf(stderr, "L%d: cannot pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*s)->n);
}
/**
 * pstr - function that prints the contents of a stack_t stack as a string
 * @stack: stack given by main
 * @line: amount of error messages
 * Return: void
 */
void pstr(stack_t **s, unsigned int line __attribute__((unused)))
{
	stack_t *now = *s;

	while (now)
	{
		if (now->n <= 0 || now->n > 127)
			break;
		putchar((char) now->n);
		now = now->next;
	}
	putchar('\n');
}
