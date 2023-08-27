#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: Always returns 0.
 */


int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
open_file(argv[1]);
free_nodes();
return (0);
}

/**
 * create_node - Creates a node with a given number.
 * @n: The number to be stored inside the node.
 * Return: If successful, returns a pointer to the created node;
 * otherwise, returns NULL.
 */

stack_t *create_node(int n)
{
stack_t *node;

node = malloc(sizeof(stack_t));
if (node == NULL)
err(4);
node->next = NULL;
node->prev = NULL;
node->n = n;
return (node);
}

/**
 * free_nodes - Frees memory allocated for nodes in the stack.
 *
 * This function is responsible for releasing the memory
 * used by nodes in a stack.
 * It doesn't take any arguments and doesn't return a value.
 */

void free_nodes(void)
{
stack_t *tmp;

if (head == NULL)
return;

while (head != NULL)
{
tmp = head;
head = head->next;
free(tmp);
}
}


/**
 * add_to_queue - Adds a new node to the queue.
 *
 * @new_node: Pointer to the new node to be added.
 * @ln: Line number corresponding to the opcode.
 *
 * This function is responsible for inserting a new node
 * at the end of a queue.
 * It takes a pointer to the new node and the line number
 * where the opcode
 * was encountered as arguments.
 */

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
while (tmp->next != NULL)
tmp = tmp->next;

tmp->next = *new_node;
(*new_node)->prev = tmp;

}
