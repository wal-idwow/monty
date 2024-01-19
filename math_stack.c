#include "monty.h"
/**
* nil - this nil do nothing.
* @escalier: a pointer to another pointer who pointing
*     to the top node of the stack.
* @lnb_opc: the interger who representing the line num of the operationcode.
*/
void nil(stack_t **escalier, unsigned int lnb_opc)
{
	(void)escalier;
	(void)lnb_opc;
}

/**
* exch_elm - exchange two elements of the stack two.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc: the interger who representing the line num of the operationcode.
*/
void exch_elm(stack_t **escalier, unsigned int lnb_opc)
{
	stack_t *tmp;

	if (escalier == NULL || *escalier == NULL || (*escalier)->next == NULL)
		more_err(8, lnb_opc, "swap");
		tmp = (*escalier)->next;
		(*escalier)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *escalier;
		tmp->next = *escalier;
		(*escalier)->prev = tmp;
		tmp->prev = NULL;
		*escalier = tmp;
}



/**
* aug_elem - Append two elements of the stack top.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc: the interger who representing the line num of the operationcode.
*/
void aug_elem(stack_t **escalier, unsigned int lnb_opc)
{
	int tot;

	if (escalier == NULL || *escalier == NULL || (*escalier)->next == NULL)
		more_err(8, lnb_opc, "add");
	(*escalier) = (*escalier)->next;
	tot = (*escalier)->n + (*escalier)->prev->n;
	(*escalier)->n = tot;
		free((*escalier)->prev);
	(*escalier)->prev = NULL;
}

/**
* red_ele - subtract two elements of the stack top.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc: the interger who representing the line num of the operationcode.
*/

void red_ele(stack_t **escalier, unsigned int lnb_opc)

{
	int tot;

	if (escalier == NULL || *escalier == NULL || (*escalier)->next == NULL)
		more_err(8, lnb_opc, "sub");
		(*escalier) = (*escalier)->next;
		tot = (*escalier)->n - (*escalier)->prev->n;
		(*escalier)->n = tot;
		free((*escalier)->prev);
		(*escalier)->prev = NULL;
}

/**
* dis_nod - divide two elements of the stack top.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc: the interger who representing the line num of the operationcode.
*/

void dis_nod(stack_t **escalier, unsigned int lnb_opc)
{
	int tot;

		if (escalier == NULL || *escalier == NULL || (*escalier)->next == NULL)
			more_err(8, lnb_opc, "div");
		if ((*escalier)->n == 0)
			more_err(9, lnb_opc);
		(*escalier) = (*escalier)->next;
		tot = (*escalier)->n / (*escalier)->prev->n;
		(*escalier)->n = tot;
		free((*escalier)->prev);
		(*escalier)->prev = NULL;
}
