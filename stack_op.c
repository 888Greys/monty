#include "monty.h"

/**
 * mul_nodes - Multiplies the top two elements of the stack.
 *
 * @stack: Pointer to a pointer pointing to the top
 * node of the stack.
 * @line_number: Integer representing the line number
 * of the opcode.
 *
 * Description: This function is responsible for multiplying
 * the top element
 *  of the stack by the element just below it. It takes a pointer
 *   to the top node of the stack and the line number where the
 *  opcode was encountered as arguments.
 */

void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Computes the modulo (remainder) of the top
 * two elements of the stack.
 *
 * @stack: Pointer to a pointer pointing to the top node
 * of the stack.
 * @line_number: Integer representing the line number of
 * the opcode.
 *
 * Description: This function is responsible for computing the modulo
 * (remainder)
 *  when dividing the top element of the stack by the element just
 *  below it. It takes a pointer to the top node of the stack and
 *  the line number where the opcode was encountered as arguments.
 */

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
