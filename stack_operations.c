#include "monty.h"

/**
* add_stack - add top two values in stack_t linked list.
* @doubly: linked list head
* @cline: line number
* Description: top value removed and result is stored in the second value node
* from the top .
* return: no return
*/
void add_stack(stack_t **doubly, unsigned int cline)
{
	int m = 0;

	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		glob_v_free();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	rm_top_elem(doubly, cline);
}

/**
* nop_stack - anything to do
* @doubly: linked list head
* @cline: line number
*/
void nop_stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
* sub_stack - Subtracts 2nd value from top
* of stack_t linked list by top value.
* @doubly: node head
* @cline:  line number
* Description: top value is removed, result is stored in
* second value node from top.
* Return: No return
*/
void sub_stack(stack_t **doubly, unsigned int cline)
{
	int m = 0;

	stack_t *current;

	current = *doubly;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		glob_v_free();
		exit(EXIT_FAILURE);
	}

	current = (*doubly)->next;
	current->n -= (*doubly)->n;
	rm_top_elem(doubly, cline);
}

/**
* div_stack -divides 2nd value from the top
* of stack_t linkedlist by the top value.
* @doubly: linked list head
* @cline: line number;
* Return: no return
*/
void div_stack(stack_t **doubly, unsigned int cline)
{
	int m = 0;

	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
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
	aux->n /= (*doubly)->n;
	rm_top_elem(doubly, cline);
}

/**
* mul_stack -multiplies 2nd value from the top
* of stack_t linked list by top value.
* @doubly: node head
* @cline: line number
* Description: top value removed, result is stored in 2nd value node
* from the top
* Return: no return
*/
void mul_stack(stack_t **doubly, unsigned int cline)
{
	int m = 0;

	stack_t *current;

	current = *doubly;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		glob_v_free();
		exit(EXIT_FAILURE);
	}

	current = (*doubly)->next;
	current->n *= (*doubly)->n;
	rm_top_elem(doubly, cline);
}
