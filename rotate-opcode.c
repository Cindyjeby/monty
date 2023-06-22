#include "monty.h"
/**
 * rotr - function that rotates the last node of a stack_t stack
 * @s: stack given by main
 * @line: amount of line
 * Return: void
 */
void rotr(stack_t **s, unsigned int line)
{
	stack_t *down;
	stack_t *prev;

	(void) line;
	if (!s || !*s || !(*s)->next)
		return;
	down = *s;

	while (down->next)
		down = down->next;

	prev = down->prev;
	down->next = *s;
	down->prev = NULL;
	(*s)->prev = down;
	*s = down;
}
/**
 * rot1 - function that rotates the first element of the stack
 * @s: stack given by main
 * @line: amount of line
 * Return: void
 */
void rot1(stack_t **s, unsigned int line)
{
	stack_t *front;
	stack_t *back;

	(void) line;
	if (!s || !*s || !(*s)->next)
		return;

	front = back = *s;

	while (back->next)
		back = back->next;
	back->next = front;
	front->prev = back;
	*s = front->next;
	(*s)->prev->next = NULL;
	(*s)->prev = NULL;
}
