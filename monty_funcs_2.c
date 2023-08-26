#include "monty.h"
void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
/**
 * monty_add - it adds the top two values of a stack iin a
 * linked list.
 * @stack: this is a pointer to the top mode node of the
 * stack in a linked list.
 * @line_number: The current working line number of a
 * Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "add"));
return;
}
(*stack)->next->next->n += (*stack)->next->n;
monty_pop(stack, line_number);
}
/**
 * monty_sub - it subtracts the second value from the top of
 *             a stack of the linked list by the top value.
 * @stack: this is a pointer to the top mode node of the
 * stack linked list.
 * @line_number: this ist the current working line number of a
 * Monty bytecode file.
 *
 * Description: the result of the function is stored in
 * the second value node
 * from the top and the top value is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "sub"));
return;
}
(*stack)->next->next->n -= (*stack)->next->n;
monty_pop(stack, line_number);
}
/**
 * monty_div - it divides the second value from the top of
 *             the stack linked list by the top value.
 * @stack: this is a pointer to the top mode node of the
 * stack linked list.
 * @line_number: this is the current working line number of a
 * Monty bytecode file.
 *
 * Description: The result of the function is stored in the second
 * value node
 *  from the top and the top value is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "div"));
return;
}
if ((*stack)->next->n == 0)
{
set_op_tok_error(div_error(line_number));
return;
}
(*stack)->next->next->n /= (*stack)->next->n;
monty_pop(stack, line_number);
}
/**
 * monty_mul - it multiplies the second value from the
 * top of
 *             the stack linked list by the top value.
 * @stack: this is a pointer to the top mode node of the stack
 * linked list.
 * @line_number: this is the current working line number of a
 * Monty bytecode file.
 *
 * Description: The result of the function is stored in the
 * second value node
 * from the top and the top value is removed.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "mul"));
return;
}
(*stack)->next->next->n *= (*stack)->next->n;
monty_pop(stack, line_number);
}
/**
 * monty_mod - it computes the modulus of the second value
 * from the
 *             top of the stack linked list  by the top value.
 * @stack: this is a pointer to the top mode node of the stack
 * linked list.
 * @line_number: this is the current working line number of a
 * Monty bytecode file.
 *
 * Description: The result of the function is stored in the
 * second value node
 * from the top and the top value is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "mod"));
return;
}
if ((*stack)->next->n == 0)
{
set_op_tok_error(div_error(line_number));
return;
}
(*stack)->next->next->n %= (*stack)->next->n;
monty_pop(stack, line_number);
}
