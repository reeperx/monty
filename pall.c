#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	print_stack(stack, line_number);
}
