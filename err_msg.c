#include "monty.h"

/**
* erreur - this prints an appropiate error mesgs determined by their errcode.
* @erreur_code: the error codes are:
* (1) => The user not give any file or more than one file to the program.
* (2) => The file provided is not a file that can be opened or read.
* (3) => The file provided contains an invalid instruc.
* (4) => When the prog is unable to memory allocation more memory.
* (5) => When the param passed to the instruction the push is not an integ.
* (6) => When the stack is empty for pint.
* (7) => When the stack is empty for pop.
* (8) => When stack is too short for the operation.
*/
void erreur(int erreur_code, ...)
{
	va_list ag;

	char *operation;

	int line_nmb;

	va_start(ag, erreur_code);

	switch (erreur_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));

			break;
		case 3:
			line_nmb = va_arg(ag, int);
			operation = va_arg(ag, char *);

			fprintf(stderr, "L%d: unknown instruction %s\n", line_nmb, operation);
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
* plus_erreur - handling errors.
* @erreur_code: The error codes are:
* (6) => When the stack is empty for pint.
* (7) => When the stack is empty for pop.
* (8) => When stack is too short for an operation.
* (9) => division by zero.
*/

void plus_erreur(int erreur_code, ...)
{
	va_list ag;

	char *operation;

	int line_nmb;

	va_start(ag, erreur_code);

	switch (erreur_code)
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
			line_nmb = va_arg(ag, unsigned int);

			operation = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_nmb, operation);
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
* mang_erreur - this one handl errors.
* @erreur_code: The error codes are:
* (10) ~> num inside a node is outside ascii bounds.
* (11) ~> stack is empty.
*/
void mang_erreur(int erreur_code, ...)
{
	va_list ag;
	int line_nmb;

	va_start(ag, erreur_code);

	line_nmb = va_arg(ag, int);

	switch (erreur_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_nmb);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_nmb);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
