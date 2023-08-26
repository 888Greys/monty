#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - Deallocates memory used by a `stack_t` stack..
 * @stack: A reference (pointer) to either the top (for a stack)
 * or the bottom (for a queue) of a `stack_t` structure.
 */
void free_stack(stack_t **stack)
{
stack_t *tmp = *stack;

while (*stack)
{
tmp = (*stack)->next;
free(*stack);
*stack = tmp;
}
}

/**
 * init_stack - Sets up a `stack_t` stack with both a
 * starting stack node and an ending queue node.
 * @stack: A reference (pointer) to a `stack_t` stack that has
 * not yet been initialized or given any initial values.
 *
 * Return: If an error occurs, the program returns
 * the status code `EXIT_FAILURE`.
 * Otherwise, if everything is successful, it returns `EXIT_SUCCESS`.
 */
int init_stack(stack_t **stack)
{
stack_t *s;

s = malloc(sizeof(stack_t));
if (s == NULL)
return (malloc_error());

s->n = STACK;
s->prev = NULL;
s->next = NULL;

*stack = s;

return (EXIT_SUCCESS);
}

/**
 * check_mode - Verifies whether a `stack_t` linked list is
 * operating in stack or queue mode.
 * @stack: A reference (pointer) to either the top
 * (for stack mode) or the bottom (for queue mode) of
 * a `stack_t` linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
if (stack->n == STACK)
return (STACK);
else if (stack->n == QUEUE)
return (QUEUE);
return (2);
}
