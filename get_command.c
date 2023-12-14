#include "monty.h"

/**
 * get_command - Fetches the function associated with a valid command.
 * @op: The command to be fetched.
 * @count: The current line number of the file, for error handling.
 *
 * Return: A function pointer to the requested command if it is valid.
 */
void (*get_command(char *op, unsigned int count))(stack_t **, unsigned int)
{
	int i = 0;
	int comparison;
	instruction_t list[] = {
		{"pall", pall_m},
		{"pint", pint_m},
		{"pop", pop_m},
		{"swap", swap_m},
		{"add", add_m},
		{"nop", nop},
		{NULL, NULL}
	};

	while (list[i].opcode != NULL)
	{
		comparison = strcmp(op, list[i].opcode);
		if (comparison == 0)
			return (list[i].f);
		i++;
	}

	// If the command is not found, raise an error and exit
	null_command(op, count);
	exit(EXIT_FAILURE);
}
