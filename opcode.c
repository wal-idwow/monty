#include "monty.h"

/**
 * opcode_select - selects the correct opcode to perform
 * @opc: opcode passed
 * Return: pointer to the function that executes the opcode
 */
void (*opcode_select(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push_cmd},
		{"pall", pall_cmd},
		{"pint", pt_cmd_top},
		{"pop", rm_top_elem},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", nop_stack},
		{"sub", sub_stack},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{"pchar", print_fs},
		{"pstr", print_st},
		{"rotl", rotate_st},
		{"rotr", reverse_st},
		{"stack", take_to_stack},
		{"queue", take_to_queu},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (compr_str(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}

/**
 * free_db - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_db(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}

/**
* tokenize - function that cut a string into tokens depending of the delimit
* @str: string to cut in parts
* @delim: delimiters
* Return: first partition
*/
char *tokenize(char *str, char *delim)
{
	static char *s;

	int n = 0, j = 0;

	if (!str)
		str = s;
	while (str[n] != '\0')
	{
		if (check_char(delim, str[n]) == 0 && str[n + 1] == '\0')
		{
			s = str + n + 1;
			*s = '\0';
			str = str + j;
			return (str);
		}
		else if (check_char(delim, str[n]) == 0 &&
				check_char(delim, str[n + 1]) == 0)
			n++;
		else if (check_char(delim, str[n]) == 0 &&
				check_char(delim, str[n + 1]) == 1)
		{
			s = str + n + 1;
			*s = '\0';
			s++;
			str = str + j;
			return (str);
		}
		else if (check_char(delim, str[n]) == 1)
		{
			j++;
			n++;
		}
	}
	return (NULL);
}

/**
 * glob_v_free - free global variables
 *
 * Return: no return
 */
void glob_v_free(void)
{
	free_db(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * init_v_var - initializes the global variables
 *
 * @file: file descriptor
 * Return: no return
 */
void init_v_var(FILE *file)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = file;
	vglo.buffer = NULL;
}
