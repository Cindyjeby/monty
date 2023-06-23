#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#define INSTRUCTIONS \
{ \
	{"push", push}, \
	{"pall", pall}, \
	{"pint", pint}, \
	{"pop", pop}, \
	{"swap", swap}, \
	{"nop", nop}, \
	{"div", _div}, \
	{"mul", _mul}, \
	{"add", _add}, \
	{"sub", _sub}, \
	{"mod", mod}, \
	{"pchar", pchar}, \
	{"pstr", pstr}, \
	{"rotr", rotr}, \
	{"rot1", rot1}, \
	{ \
		NULL, NULL \
	} \
}
/**
 * struct stack_s _ doubly linked list rep of a stack or queue
 * @n: integer
 * @prev: points to a previous element of stack or queue
 * @next: points to next element of stack or queue
 * Description: doubly linked list node structure for
 * stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to hanle the opcode
 * Description: opcode and its function for stack,
 * queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **s, unsigned int line);
} instruction_t;
/**
 * stuct help - argument for the current opcode
 * @data_stuct: stack mode, deafult and queue
 * @argument: the arg of the string
 * Description: global structure used to psaa data around thefunctions
 */
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

void push(stack_t **s, unsigned int line);
void pint(stack_t **s, unsigned int line);
void pop(stack_t **s, unsigned int line);
void pall(stack_t **s, unsigned int line __attribute__((unused)));

void _add(stack_t **s, unsigned int line);
void _sub(stack_t **s, unsigned int line);
void _mul(stack_t **s, unsigned int line);
void _div(stack_t **s, unsigned int line);
void mod(stack_t **s, unsigned int line);

void pchar(stack_t **s, unsigned int line);
void pstr(stack_t **s, unsigned int line __attribute__((unused)));

int is_digit(char *s);
int is_number(char *s);

stack_t *queue(stack_t **s, const int n);
stack_t *add_node(stack_t **s, const int n);
size_t print_stack(const stack_t *s);
void free_stack(stack_t *s);

void rotr(stack_t **s, unsigned int line);
void rot1(stack_t **s, unsigned int line);

void swap(stack_t **s, unsigned int line);
void nop(stack_t **s, unsigned int line);

void opcode(stack_t **s, char *str, unsigned int line);

int main(int argc, char **argv);
void file_error(char *argv);
void error_usage(void);

#endif
