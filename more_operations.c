#include "monty.h"

/**
 * mod_stack - computes the rest of the division of the second element
 * by the top element of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 * info:The result is stored in 2nd value node from the top
 * and top value removed.
 */
void mod_stack(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		glob_v_free();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		glob_v_free();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	rm_top_elem(doubly, cline);
}

/**
 * print_st - prints the string of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void print_st(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}

/**
 * print_fs - print the char value of the first element
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void print_fs(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		glob_v_free();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		glob_v_free();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}
