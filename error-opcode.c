#define _POSIX_C_SOURCE 200809L
#include "monty.h"
void file_error(char *argv);
void error_usage(void);
int status = 0;

/**
 * main - function entry point
 * @argv: list of arguments
 * @argc: amount of arguments
 * Return: void
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buf = NULL;
	char *str = NULL;
	stack_t *str = NULL;
	unsigned int line = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (file == NULL)
		file_error(argv[1]);
	while ((getline(&buf, &buf_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buf == '\n')
		{
			line++;
			continue;
		}
		str = strtok(buf, " \t\n");
		if (!str || *str == '#')
		{
			line++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&s, str, line);
		line++;
	}
	fee(buf);
	free_stack(s);
	fclose(file);
	exit(EXIT_SUCCESS);
}
/**
 * file_error - function that prints file error message and exits
 * @argv: argv given by main()
 * DEscription: print msg if not possible to open the file
 * Return: void
 */
void file_error(char *argv)
{
	fprintf(stderr, "error: cannot open file %s\n", argv);
	exit(EXIT_FAILURE);
}
/**
 * error_usage - function that prints usage message and exits
 * Description: if the user does not give ant file of more than one argument
 * Return: void
 */
void error_usage(void)
{
	fprintf(stderr, "usage: monty file\n");
	exit(EXIT_FAILURE);
}
