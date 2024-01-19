#include "monty.h"

/**
* inp_stack - this fun adds two elements of the stack top.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc: the interger who representing the line num of the operationcode.
*/
void inp_stack(stack_t **escalier, unsigned int lnb_opc)
{
	int tot;

	if (escalier == NULL || *escalier == NULL || (*escalier)->next == NULL)
		more_err(8, lnb_opc, "mul");
	(*escalier) = (*escalier)->next;

	tot = (*escalier)->n * (*escalier)->prev->n;
	(*escalier)->n = tot;
	free((*escalier)->prev);
	(*escalier)->prev = NULL;

}

/**
* elem_stck - this fun adds two elements of the stack top.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc: the interger who representing the line num of the operationcode.
*/
void elem_stck(stack_t **escalier, unsigned int lnb_opc)
{
	int tot;

	if (escalier == NULL || *escalier == NULL || (*escalier)->next == NULL)
		more_err(8, lnb_opc, "mod");
	if ((*escalier)->n == 0)
		more_err(9, lnb_opc);
	(*escalier) = (*escalier)->next;
	tot = (*escalier)->n % (*escalier)->prev->n;
	(*escalier)->n = tot;
	free((*escalier)->prev);
	(*escalier)->prev = NULL;

}

