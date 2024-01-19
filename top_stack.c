#include "monty.h"
/**
* inclu_st - this one adds a node to the stack.
* @novl_node: a pointer to la nouvelle node.
* @lnb_opc: the interger who representing the line num of the operationcode.
*/
void inclu_st(stack_t **novl_node, __attribute__((unused))unsigned int lnb_opc)
{
	stack_t *tmp;

	if (novl_node == NULL || *novl_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *novl_node;
		return;
	}
		tmp = head;
		head = *novl_node;
		head->next = tmp;
		tmp->prev = head;
}

/**
* oput_stck - this adds a node to the stack.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc: the line num of the operationcode.
*/

void oput_stck(stack_t **escalier, unsigned int lnb_opc)
{

	stack_t *tmp;
(void) lnb_opc;

	if (escalier == NULL)

	exit(EXIT_FAILURE);
	tmp = *escalier;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
* out_hight - Adds a node to the stack.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc:the interger who representing the line num of the operationcode.
*/

void out_hight(stack_t **escalier, unsigned int lnb_opc)
{
	stack_t *tmp;

	if (escalier == NULL || *escalier == NULL)
		more_err(7, lnb_opc);
			tmp = *escalier;
			*escalier = tmp->next;

	if (*escalier != NULL)

	(*escalier)->prev = NULL;
	free(tmp);
}

/**
* oput_hight - Prints the top node of the stack.
* @escalier: a pointer to another pointer who pointing
*   to the top node of the stack.
* @lnb_opc:the interger who representing the line num of the operationcode.
*/

void oput_hight(stack_t **escalier, unsigned int lnb_opc)
{
if (escalier == NULL || *escalier == NULL)
	more_err(6, lnb_opc);
	printf("%d\n", (*escalier)->n);
}
