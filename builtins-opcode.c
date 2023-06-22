#include "monty.h"
/**
 * op_code - function in charge of running builtins
 * @s: given by main
 * @s: string to compare
 * @line: amount of lines
 * Return: void
 */
void op_code(stack_t **s, char *s, unsigned int line)
{
	int k = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(s, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(s, "queue"))
	{
		global.data_struct = 0;
		return;
	}
	while (op[k].opcode)
	{
		if (strcmp(op[k].opcode, s) == 0)
		{
			op[k].f(stack, line);
			return;
		}
		k++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, s);
	exit(EXIT_FAILURE);
}
