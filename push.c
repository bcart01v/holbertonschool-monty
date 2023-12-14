#include "monty.h"

/**
 * push - Push a new node at the top of the stack
 * @head: Pointer to the head of the stack
 * @line_number: Line number of the command in the input file
 *
 * This function pushes a new node with the specified integer value onto the top
 * of the stack pointed to by 'head'.
 */
void push(stack_t **head, unsigned int line_number)
{
	const char *token = NULL;
	int n;
	stack_t *new_node;

	if (line_number <= 0)
		return;

	token = strtok(NULL, " ");
	if (!token)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return;
	}

	n = atoi(token);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;
}
