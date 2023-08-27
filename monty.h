#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue).
 *
 * @n: Integer value stored in the node.
 * @prev: Pointer to the previous element of the stack (or queue).
 * @next: Pointer to the next element of the stack (or queue).
 *
 * Description: This structure defines a node in a doubly linked list,
 *              commonly used to implement stacks (LIFO) or queues (FIFO).
 */

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its associated function.
 *
 * @opcode: The opcode.
 * @f: The function that handles the opcode.
 *
 * Description: This structure represents an opcode along with the
 *              function that should be called to perform the associated operation.
 *              It is commonly used for implementing stack, queues, LIFO, and FIFO
 *              operations.
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*
 * File Operations
 *
 * This section of the code encompasses functions and
 * logic for performing
 * operations related to files. It includes tasks such
 * as opening, reading,
 * writing, and manipulating files as needed for the
 * program's functionality.
 */

void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*
 * Stack Operations
 *
 * This section of the code contains functions and logic
 * for performing various
 * operations on a stack data structure. It includes
 * operations such as push,
 * pop, peek, and other stack-specific functions for
 * managing and manipulating
 * data in a Last-In-First-Out (LIFO) fashion.
 */

stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);

/*
 * Mathematical Operations with Nodes
 *
 * This section of the code contains functions and logic 
 * for performing various
 * mathematical operations using data stored in nodes.
 * It includes operations
 * such as addition, subtraction, multiplication, or other
 * mathematical computations
 * that involve the values stored in linked list nodes.
 */

void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*
 * String Operations
 *
 * This section of the code is dedicated to performing various operations
 * on strings. It includes functions and logic for manipulating, processing,
 * or analyzing strings as needed for the program's functionality.
 */

void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*
 * Error Handling
 *
 * This section of the code is responsible for managing
 * and handling errors that
 * may occur during program execution. It includes functions
 * and logic to
 * detect, report, and handle various types of errors to ensure robust and
 * reliable program behavior.
 */

void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
