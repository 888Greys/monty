#include "monty.h"

/**
 * err - Displays error messages based on their corresponding error
 * codes.
 * @error_code: The error codes and their meanings are as follows:
 * (1) => The user did not provide any file or provided more than one
 * file to the program.
 * (2) => The provided file cannot be opened or read.
 * (3) => The provided file contains an invalid instruction.
 * (4) => The program is unable to allocate more memory using malloc.
 * (5) => The parameter passed to the "push" instruction is not an integer.
 * (6) => The "pint" instruction is called on an empty stack.
 * (7) => The "pop" instruction is called on an empty stack.
 * (8) => The stack does not have enough elements for the operation.
 */

void err(int error_code, ...)
{
va_list ag;
char *op;
int l_num;

va_start(ag, error_code);
switch (error_code)
{
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n",
va_arg(ag, char *));
break;
case 3:
l_num = va_arg(ag, int);
op = va_arg(ag, char *);
fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}

/**
 * more_err - Manages and handles various types of errors.
 * @error_code: The error codes and their meanings are as follows:
 * (6) => Error: Attempted "pint" operation on an empty stack.
 * (7) => Error: Attempted "pop" operation on an empty stack.
 * (8) => Error: Stack size is insufficient for the requested operation.
 * (9) => Error: Division by zero detected.
 */

void more_err(int error_code, ...)
{
va_list ag;
char *op;
int l_num;

va_start(ag, error_code);
switch (error_code)
{
case 6:
fprintf(stderr, "L%d: can't pint, stack empty\n",
va_arg(ag, int));
break;
case 7:
fprintf(stderr, "L%d: can't pop an empty stack\n",
va_arg(ag, int));
break;
case 8:
l_num = va_arg(ag, unsigned int);
op = va_arg(ag, char *);
fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
break;
case 9:
fprintf(stderr, "L%d: division by zero\n",
va_arg(ag, unsigned int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}

/**
 * string_err - Manages and handles errors related to strings.
 * @error_code: The error codes and their meanings are as follows:
 * (10) => Error: The number inside a node is outside the bounds of
 * valid ASCII characters.
 * (11) => Error: The stack is empty, and an operation requiring string
 * handling was attempted.
 */

void string_err(int error_code, ...)
{
va_list ag;
int l_num;

va_start(ag, error_code);
l_num = va_arg(ag, int);
switch (error_code)
{
case 10:
fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
break;
case 11:
fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}
