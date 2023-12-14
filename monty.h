#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: Integer value stored in the node
 * @prev: Points to the previous element in the stack (or queue)
 * @next: Points to the next element in the stack (or queue)
 *
 * Description: Doubly linked list node structure for implementing
 * stack, queue, LIFO, and FIFO operations.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: The opcode (a string representing the operation)
 * @f: Pointer to a function that implements the opcode
 *
 * Description: Opcode and its associated function for implementing
 * stack, queue, LIFO, and FIFO operations.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Keep track of line */
extern unsigned int line_count; 

/* Function prototypes */

/* Converts a command string into a valid opcode */
char *cmdstr(char *);

/* Converts a command string into a valid integer value */
int cmdval(char *, unsigned int);

/* Retrieves the function associated with a given opcode */
void (*get_command(char *op, unsigned int line_number))(stack_t **, unsigned int);

/* Frees the memory allocated for the stack */
void free_stack(stack_t *head);

/* Handles the case when a file is not found */
void null_file(char *);

/* Handles the case when an integer value is not found */
void null_int(unsigned int);

/* Reports an error related to the line count */
void count_error(void);

/* Handles the case when a command is not found */
void null_command(char *, unsigned int);

/* Handles the 'pint' opcode error */
void pint_err(unsigned int);

/* Handles the 'pop' opcode error */
void pop_err(unsigned int);

/* Handles the 'swap' opcode error */
void swap_err(unsigned int);

/* Handles the 'add' opcode error */
void add_err(unsigned int);

/* Implements the 'push' opcode */
void push_m(stack_t **stack, unsigned int line_number);

/* Implements the 'pall' opcode */
void pall_m(stack_t **stack, unsigned int line_number);

/* Implements the 'pint' opcode */
void pint_m(stack_t **stack, unsigned int line_number);

/* Implements the 'pop' opcode */
void pop_m(stack_t **stack, unsigned int line_number);

/* Implements the 'swap' opcode */
void swap_m(stack_t **stack, unsigned int line_number);

/* Implements the 'add' opcode */
void add_m(stack_t **stack, unsigned int line_number);

/* Implements the 'nop' opcode */
void nop(stack_t **stack, unsigned int line_number);

/* Is that all ?! */

#endif
