#include "monty.h"
/**
 * free_stack - Frees a stack if the program closes with remaining nodes
 * @head: The top of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}