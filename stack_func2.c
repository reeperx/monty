#include "monty.h"

/**
 * mian - nop is a function that does nothing.
 * @stack: displays a pointer pointing to the top node of the stack.
 * @line_number: prints an interger representing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * ain - swap_nodes is for swapping the top two elements of the stack.
 * @stack: displays a pointer pointing to the top node of the stack.
 * @line_number: prints an interger representing the line number of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * main - add_nodes is for adding the top two elements of the stack.
 * @stack: displays a pointer pointing to the top node of the stack.
 * @line_number: prints an interger representing the line number of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * main - sub_nodes is for adding the top two elements of the stack.
 * @stack: displays a pointer pointing to the top node of the stack.
 * @line_number: prints an interger representing the line number of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * main - div_nodes is for adding the top two elements of the stack.
 * @stack: displays a pointer pointing to the top node of the stack.
 * @line_number: prints an interger representing the line number of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
