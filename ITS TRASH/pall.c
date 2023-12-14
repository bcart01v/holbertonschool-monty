#include "monty.h"

/**
 * pall - Print all elements of a stack
 * @head: Pointer to the head of the stack
 * @line_number: Line number of the command in the input file
 *
 * This function prints all elements of the stack starting from the top (head).
 * It prints each element followed by a newline character.
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*head == NULL || line_number <= 0)
		return;

	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
