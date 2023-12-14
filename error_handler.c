#include "monty.h"

/**
 * null_file - Prints an error message for a missing or inaccessible file.
 * @str: The name of the file that couldn't be opened.
 */
void null_file(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	exit(EXIT_FAILURE);
}

/**
 * count_error - Prints an error message for an incorrect number of arguments.
 */
void count_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * null_command - Prints an error message for an invalid command.
 * @command: The string passed as a command.
 * @line: The line number where the invalid command appears.
 */
void null_command(char *command, unsigned int line)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, command);
	exit(EXIT_FAILURE);
}

/**
 * null_int - Prints an error message for invalid data (non-integer).
 * @line: The line number where the error occurs.
 */
void null_int(unsigned int line)
{
	fprintf(stderr, "L%d: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}

/**
 * pint_err - Prints an error message for attempting to pint an empty stack.
 * @line: The line number where the error occurs.
 */
void pint_err(unsigned int line)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line);
	exit(EXIT_FAILURE);
}

/**
 * pop_err - Prints an error message for an invalid pop command.
 * @line: The line number where the error occurs.
 */
void pop_err(unsigned int line)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line);
	exit(EXIT_FAILURE);
}

/**
 * swap_err - Prints an error message for an invalid swap command.
 * @line: The line number where the error occurs.
 */
void swap_err(unsigned int line)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * add_err - Prints an error message for an invalid add command.
 * @line: The line number where the error occurs.
 */
void add_err(unsigned int line)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line);
	exit(EXIT_FAILURE);
}