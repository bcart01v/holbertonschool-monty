#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: The count of arguments passed to the program
 * @argv: The list of arguments passed to the program
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	size_t buffsize = 512;
	unsigned int data = 0, line_count = 0;
	char *buffer = malloc(buffsize * sizeof(char)), *temp = NULL, *cmd;
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");
	void (*op_func)(stack_t **, unsigned int);

	if (argc != 2)
		count_error();
	if (file == NULL)
		null_file(argv[1]);

	while (getline(&buffer, &buffsize, file) != -1)
	{
		line_count += 1;
		cmd = cmdstr(strtok(buffer, " \n"));
		if (strcmp(cmd, "empty") == 0)
			continue;
		if (strcmp(cmd, "push") == 0)
		{
			temp = strtok(0, " \n");
			if (temp == NULL)
				null_int(line_count);
			data = cmdval(temp, line_count);
			push_m(&stack, data);
			continue;
		}
		op_func = get_command(cmd, line_count);
		op_func(&stack, line_count);
	}
	free_stack(stack);
	free(buffer);
	fclose(file);
	return (EXIT_SUCCESS);
}
