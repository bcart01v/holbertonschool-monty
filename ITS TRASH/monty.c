#include "monty.h"

/**
 * main - Program entry point
 * @argc: Count of arguments
 * @argv: Array of arguments given to the program (should contain the filename)
 * 
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	char *getline_string = NULL, *token;
	instruction_t obj;
	stack_t *head = NULL;
	int flag = 0;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* Read lines from the file and store in getline_string */
	getline_string = getline_a(argv[1]); 
	if (!getline_string)
	{
		/* Handle memory allocation failure */
		fprintf(stderr, "Error: Unable to read file\n");
		return (EXIT_FAILURE);
	}

	/* Tokenize and process instructions */
	token = strtok(getline_string, " ");
	while (token)
	{
		obj.f = get_function(token, flag);
		if (obj.f == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
			free(getline_string);
			exit(EXIT_FAILURE);
		}
		obj.f(&head, line_number);
		line_number++;
		flag = 1;
		token = strtok(NULL, " ");
	}

	/* Clean up and free allocated memory */
	free_list(head);
	free(getline_string);

	return (EXIT_SUCCESS);
}
