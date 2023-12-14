#include "monty.h"
/**
 * cmdstr - Checks if a passed string is empty
 * @str: The checked string
 *
 * Return: The string "empty" to inform the loop to skip the current iteration
 */
char *cmdstr(char *str)
{
	if (str == NULL)
		return ("empty");
	return (str);
}

/**
 * cmdval - Checks if a passed string can be converted into a valid integer
 * @str: The checked string
 * @line: The current line count, for error handling purposes
 *
 * Return: If the checked string was a valid number, return it as an integer.
 * Otherwise, throw an error.
 */
int cmdval(char *str, unsigned int line)
{
	int i = 0;
	int valcheck = strcmp(str, "");

	if (str == NULL || valcheck == 0)
		null_int(line);
	while (str[i] != '\0')
	{
		if (str[i] < '-' || str[i] > '9')
			null_int(line);
		i++;
	}
	return (atoi(str));
}
