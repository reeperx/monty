#include "monty.h"
/**
 * main - add_to_stack is for adding a node to the stack.
 * @new_node: displays a pointer to the new node.
 * @ln: this is an interger representing the line number of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * main - print_stack is for adding a node to the stack.
 * @stack: displays a pointer pointing to top node of the stack.
 * @line_number: prints a line number of the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * main - pop_top is for adding a node to the stack.
 * @stack: displays a pointer pointing to top node of the stack.
 * @line_number: displays an interger representing the line number of opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * main  - print_top is for printing the top node of the stack.
 * @stack: displays a pointer pointing to the top node of the stack.
 * @line_number: displays an interger representing the line number of opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
