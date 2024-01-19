#include "monty.h"
/**
 *add_node_top - add node at begining of doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a db linked list
 */
stack_t *add_node_top(stack_t **head, const int n)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		glob_v_free();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 *add_node_end - add node at end of db link list
 *@head: head of linked list
 *@n: data to store
 *Return: (db linked list)
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *auxil, *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		glob_v_free();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	auxil = *head;
	while (auxil->next)
		auxil = auxil->next;
	tmp->next = auxil->next;
	tmp->prev = auxil;
	auxil->next = tmp;
	return (auxil->next);
}

/**
 * check_char- search if a char is inside a string
 * @str: string to review
 * @chr: char to find
 * Return: 1 if success 0 if not
 */
int check_char(char *str, char chr)
{
	int cont = 0;

	while (str[cont] != '\0')
	{
		if (str[cont] == chr)
		{
			break;
		}
		cont++;
	}
	if (str[cont] == chr)
		return (1);
	else
		return (0);
}

/**
 * compr_str - compare two strings.
 * @str1: type str compared
 * @str2: type str compared
 * Return: 0 nf str1 and str2 are equals.
 *         another value if they are different
 */
int compr_str(char *str1, char *str2)
{
	int n;

	for (n = 0; str1[n] == str2[n] && str1[n]; n++)
		;
	if (str1[n] > str2[n])
		return (1);
	if (str1[n] < str2[n])
		return (-1);
	return (0);
}

/**
 * check_op_file - checks if file exists + if file can
 * able to be opened
 * @ac: argument count
 * @av: argument vector
 * Return: file struct
 */
FILE *check_op_file(int ac, char *av[])
{
	FILE *fd;

	if (ac == 1 || ac > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
