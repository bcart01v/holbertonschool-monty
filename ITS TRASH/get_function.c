#include "monty.h"

/**
 * get_func - Get the corresponding function for a given token
 * @token: The token to match against opcodes
 * @flag: A flag indicating whether to tokenize or not (1 for tokenization)
 * 
 * Return: A pointer to the corresponding function, or NULL if not found
 */
void (*get_function(char *token, int flag))(stack_t **head, unsigned int line_number)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	/* Tokenize the input if flag is set to 1 */
	if (flag == 1)
		token = strtok(NULL, " ");

	/* Check if token is NULL (no opcode) */
	if (token == NULL)
		return (NULL);

	/* Compare the token to known opcodes */
	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, token) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}

	return (NULL);
}
