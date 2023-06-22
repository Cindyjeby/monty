#include "monty.h"
/**
 * is_digit - function that checks if a string is a digit
 * @s: string to be checked
 * Return: 1 (success), 0 (failed)
 */
inr is_digit(char *s)
{
	if (!s || *s == '\0')
		return (0);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (isdigit(*s) == 0)
			return (0);
		s++;
	}
	return (1);
}
/**
 * is_number - function that checks if a string is a number
 * @s: string to be checked
 * Return: 1 if number, in not 0
 */
int is_number(char *s)
{
	int k;

	if (s == NULL)
		return (0);

	for (k = 0; s[k]; k++)
		if (k < '0' || k > '9')
			return (0);
	return (1);
}
