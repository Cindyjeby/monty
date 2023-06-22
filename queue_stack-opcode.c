#include "monty.h"
/**
 * queue - function that adds a node to a stack
 * @s: stack
 * @n: no of nodes
 * Return: new node, memory allocation fails, or NULL
 */
stack_t *queue(stack_t **s, const int n)
{
	stack_t *mpya = malloc(sizeof(stack_t));
	stack_t *cur = *s;

	if (mpya == NULL)
	{
		free(mpya);
		return (NULL);
	}
	mpya->n = n;

	if (*s == NULL)
	{
		mpya->next = NULL;
		mpya->prev = NULL;
		*s = mpya;
		return (mpya);
	}
	while (cur)
	{
		if (!cur->next)
		{
			mpya->next = NULL;
			mpya->prev = cur;
			cur->next = mpya;
			break;
		}
		cur = cur->next;
	}
	return (mpya);
}
/**
 * add_node - function that adds a node at the start of a stack
 * @s: stack
 * @n: number of new node
 * Return: new node
 */
stack_t *add_node(stack_t **s, const int n)
{
	stack_t *mpya = malloc(sizeof(stack_t));

	if (mpya == NULL)
	{
		fprintf(stderr, "error: malloc failed\n");
		free(mpya);
		return (NULL);
	}
	mpya-> = n;
	mpya->next = *s;
	mpya->prev = NULL;

	if (*s)
		(*s)->prev = mpya;
	*s = mpya;
	return (mpya);
}
/**
 * print_stack - function that prints the contents of a stack_t stack
 * @s: stack
 * Return: number of element of the lst
 */
size_t print_stack(const stack_t *s)
{
	size_t i = 0;

	while (s)
	{
		printf("%d\n", s->n);
		s = s->next;
		i++;
	}
	return (k);
}
/**
 * free_stack - function that frees a linked list
 * @s: stack
 * Return: void
 */
void free_stack(stack_t *s)
{
	stack_t *cur = s;
	stack_t *next;

	if (s)
	{
		next = s->next;
		while (cur)
		{
			free(cur);
			cur = next;
			if (next)
				next = next->next;
		}
	}
}
