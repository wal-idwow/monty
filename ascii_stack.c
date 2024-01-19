#include "monty.h"

/**
* output_ascval - this one prints the ascii table value.
* @escalier: the pointer to a pointer that pointing
* to a top of a node of the stack.
* @lnb_opc: the interger who representing a line number of opcode.
*/

void output_ascval(stack_t **escalier, unsigned int lnb_opc)
{
	int asc_table;

		if (escalier == NULL || *escalier == NULL)
			string_err(11, lnb_opc);
			asc_table = (*escalier)->n;

		if (asc_table < 0 || asc_table > 127)
			string_err(10, lnb_opc);
			printf("%c\n", asc_table);
}

/**
* output_strg - this one prints string.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc: the interger who representing the line num of the opcode.
*/
void output_strg(stack_t **escalier,
	__attribute__((unused))unsigned int lnb_opc)
{
	int asc_table;

	stack_t *tmp;

		if (escalier == NULL || *escalier == NULL)
		{
			printf("\n");
				return;
		}
		tmp = *escalier;

		while (tmp != NULL)
		{
			asc_table = tmp->n;
			if (asc_table <= 0 || asc_table > 127)
				break;

			printf("%c", asc_table);
			tmp = tmp->next;

		}
		printf("\n");
}

/**
* rt_fnsbm - this one revolve the first node of a stack to the bottom.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc: the interger who representing the line num of the opcode.
*/

void rt_fnsbm(stack_t **escalier, __attribute__((unused))unsigned int lnb_opc)
{
	stack_t *tmp;
		if (escalier == NULL || *escalier == NULL || (*escalier)->next == NULL)
		{
			return;
		}
			tmp = *escalier;
			while (tmp->next != NULL)
				tmp = tmp->next;
				tmp->next = *escalier;
					(*escalier)->prev = tmp;
					*escalier = (*escalier)->next;
					(*escalier)->prev->next = NULL;
					(*escalier)->prev = NULL;

}

/**
* rt_lnstop - this one revolve the last node of the stack to the top.
* @escalier: a pointer to another pointer who pointing
* to the top node of the stack.
* @lnb_opc: the interger who representing the line num of the opcode.
*/

void rt_lnstop(stack_t **escalier, __attribute__((unused))unsigned int lnb_opc)
{
	stack_t *tmp;
		if (escalier == NULL || *escalier == NULL || (*escalier)->next == NULL)
			return;
		tmp = *escalier;
			while (tmp->next != NULL)
				tmp = tmp->next;
				tmp->next = *escalier;
				tmp->prev->next = NULL;
				tmp->prev = NULL;
					(*escalier)->prev = tmp;
					(*escalier) = tmp;
}
