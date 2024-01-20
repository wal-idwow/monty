#include "monty.h"
/**
 * push_cmd - pushes to stack
 * @head: head of linked list
 * @cline: line number
 * Return: no return
 */
void push_cmd(stack_t **head, unsigned int cline)
{
	int n, j;

	if (!glob_v.secin)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		glob_v_free();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glob_v.secin[j] != '\0'; j++)
	{
		if (!isdigit(glob_v.secin[j]) && glob_v.secin[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			glob_v_free();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glob_v.secin);

	if (glob_v.st_qu == 1)
		add_node_top(head, n);
	else
		add_node_end(head, n);
}

/**
 * pall_cmd - prints all values on the stack
 *
 * @head: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void pall_cmd(stack_t **head, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * pt_cmd_top - prints the value at the top of the stack
 *
 * @head: head of the linked list
 * @cline: line number
 * Return: no return
 */
void pt_cmd_top(stack_t **head, unsigned int cline)
{
	(void)cline;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		glob_v_free();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * rm_top_elem - removes the top element of the stack
 *
 * @head: head of the linked list
 * @cline: line number
 * Return: no return
 */
void rm_top_elem(stack_t **head, unsigned int cline)
{
	stack_t *aux;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		glob_v_free();
		exit(EXIT_FAILURE);
	}
	aux = *head;
	*head = (*head)->next;
	free(aux);
}

/**
 * swap_stack - swaps the top two elements of the stack
 *
 * @head: head of the linked list
 * @cline: line number
 * Return: no return
 */
void swap_stack(stack_t **head, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		glob_v_free();
		exit(EXIT_FAILURE);
	}

	aux = *head;
	*head = (*head)->next;
	aux->next = (*head)->next;
	aux->prev = *head;
	(*head)->next = aux;
	(*head)->prev = NULL;
}

