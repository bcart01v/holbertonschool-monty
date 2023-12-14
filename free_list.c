#include "monty.h"

/**
 * free_list - Frees a doubly linked list
 * @head: Pointer to the head of the list
 *
 * This function frees all nodes in a doubly linked list starting from the
 * given head node.
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
