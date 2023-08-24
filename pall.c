#include "monty.h"
/**
 * f_pall - prints the whole of the stack
 * @head: head of the stack
 * @counter: not used
 * Return: no return value
*/
void f_pall(stack_t **head, unsigned int counter)
{
stack_t *h;
(void)counter;
h = *head;
if (h == NULL)
return;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}

