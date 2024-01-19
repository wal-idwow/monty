#include "monty.h"

/**
 * take_to_queu - sets format of data to queue(FIFI/LILO)
 * @doubly: head of linked list
 * @cline: line number
 */
void take_to_queu(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * take_to_stack - sets format of data to stack (LIFO/FILO)
 * @doubly: linked list head
 * @cline: line number
 */
void take_to_stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

/**
 * rotate_st - rotates 1st element to the bottom and 2nd to the top
 * @doubly: linked list head
 * @cline: line nummber
 */
void rotate_st(stack_t **doubly, unsigned int cline)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux1 = (*doubly)->next;
	aux2 = *doubly;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = aux2;
	*doubly = aux1;
}

/**
 * reverse_st - reverse stack
 * @doubly: linked list head
 * @cline: line number
 */
void reverse_st(stack_t **doubly, unsigned int cline)
{
	stack_t *aux = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux = *doubly;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *doubly;
	aux->prev = NULL;
	(*doubly)->prev = aux;
	*doubly = aux;
}
