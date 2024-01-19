#include "monty.h"

/**
* unlock_fichier - this opens a file.
* @fichier_nam: the file namepath.
* Return: void.
*/

void unlock_fichier(char *fichier_nam)
{
	FILE *fd = fopen(fichier_nam, "r");
		if (fichier_nam == NULL || fd == NULL)
			err(2, fichier_nam);
					per_fich(fd);
					fclose(fd);
}

/**
* per_fich - peruse a file.
* @fd: a pointer to the file descriptor.
* Return: void.
*/

void per_fich(FILE *fd)
{
	int ln_num, shape = 0;

	char *buff = NULL;

	size_t len = 0;

	for (ln_num = 1; getline(&buff, &len, fd) != -1; ln_num++)
	{
		shape = sep_line(buff, ln_num, shape);
	}
	free(buff);
}

/**
* sep_line - this one separates each line into tokens to determine
* which fun to call.
* @buff: the line from the file.
* @ln_num: the line num.
* @shape: the storage shape if 0 nodes will be entered as a stack.
* if 1 nodes will be entered as a queue.
* Return: Returns 0 if the opercode is stack. 1 if queue.
*/

int sep_line(char *buff, int ln_num, int shape)
{
	char *opcode, *value;

	const char *delim = "\n ";

	if (buff == NULL)
		err(4);
		opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (shape);
		value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	lock_for(opcode, value, ln_num, shape);
		return (shape);
}

/**
* lock_for - this find the appropriate fun for the operationcode.
* @opercode: operationcode.
* @value: the argument of an operationcode.
* @shape: the storage shape if 0 nodes will be entered as a stack.
* @ln: a line num.
* if 1 nodes will be entered as a queue.
* Return: void.
*/

void lock_for(char *opercode, char *value, int ln, int shape)
{
	int i;

	int res;

	instruction_t func_list[] = {

		{"push", inclu_st},
		{"pall", oput_stck},
		{"pint", out_hight},
	    {"pop", oput_hight},
		{"nop", nil},
		{"swap", exch_elm},
		{"add", aug_elem},
		{"sub", red_ele},
		{"div", dis_nod},
		{"mul", inp_stack},
		{"mod", elem_stck},
		{"pchar", output_ascval},
		{"pstr", output_strg},
		{"rotl", rt_fnsbm},
		{"rotr", rt_lnstop},
		{NULL, NULL}
	};
		if (opercode[0] == '#')
			return;
		for (res = 1, i = 0; func_list[i].opcode != NULL; i++)
		{
			if (strcmp(opercode, func_list[i].opcode) == 0)
			{
				call_fun(func_list[i].f, opercode, value, ln, shape);
				res = 0;
			}
		}
		if (res == 1)
			err(3, ln, opercode);
}

/**
* call_fun - this one calls the required func.
* @func: the pointer to the func that is going to be called.
* @operationc: the str that representing the operationcode.
* @val: the str representing a numeric value.
* @ln: the line num for the instruction.
* @shape: shape specifier if 0 Nodes will be entered as a stack.
* if 1 nodes will be entered as a queue.
*/

void call_fun(op_func func, char *operationc, char *val, int ln, int shape)
{
	stack_t *node;
	int res;

	int clfn;

	res = 1;

	if (strcmp(operationc, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			res = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (clfn = 0; val[clfn] != '\0'; clfn++)
		{
			if (isdigit(val[clfn]) == 0)
			err(5, ln);
		}
		node = create_node(atoi(val) * res);
		if (shape == 0)
		func(&node, ln);

		if (shape == 1)
			add_to_queue(&node, ln);
	}
	else
	func(&head, ln);
}
