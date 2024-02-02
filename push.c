#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, "\n\t\r ");
	int n;
	stack_t *new_node;  /* Declare new_node here */

	if (arg == NULL || isdigit(arg))
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}

	n = atoi(arg);
	/* Allocate memory for new_node here */
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	/* if stack is not empty, set the prev of top to new node */
	if (*stack != NULL)
	{
	new_node->next = *stack;
	(*stack)->prev = new_node;
	}
	/* set stack top to new node */
	*stack = new_node;
}
