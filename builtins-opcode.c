#include "monty.h"
/**
 * opcode - function in charge of running builtins
 * @s: given by main
 * @str: string to compare
 * @line: amount of lines
 * Return: void
 */
void opcode(stack_t **s, char *str, unsigned int line)
{
	int k = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}
	while (op[k].opcode)
	{
		if (strcmp(op[k].opcode, str) == 0)
		{
			op[k].f(s, line);
			return;
		}
		k++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, str);
	exit(EXIT_FAILURE);
}
