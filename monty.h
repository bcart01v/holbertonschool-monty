#ifndef MONTY_H
#define MONTY_H

/* Include necessary system libraries */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/**
* struct stack_s - Doubly linked list representation of a stack (or queue)
* @n: Integer value stored in the node
* @prev: Points to the previous element of the stack (or queue)
* @next: Points to the next element of the stack (or queue)
*
* Description: Doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
* struct instruction_s - Opcode and its corresponding function
* @opcode: The opcode (e.g., "push", "pall", etc.)
* @f: Function pointer to handle the opcode
*
* Description: Represents an opcode and its associated function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void pall(stack_t **head, unsigned int line_number);
void push(stack_t **head, unsigned int line_number);
char *getline_a(char *file);
void free_list(stack_t *head);
char *string_clean(char *getline_string);
void (*get_func(char *token, int flag))(stack_t **head, unsigned int line_number);

#endif
