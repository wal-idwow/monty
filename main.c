#include "monty.h"

stack_t *head = NULL;

/**
* main - the entry point
* @argv: the list of arguments
* @argc: the arguments count
* Return: always 0
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
* create_node - creates the node.
* @nnode: the num to go inside the node.
* Return: upon success a pointer to the node, otherwise NULL.
*/

stack_t *create_node(int nnode)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = nnode;
	return (node);
}

/**
* free_nodes - this one frees nodes in the stack.
*/

void free_nodes(void)

{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;

		free(tmp);
	}
}



/**
* add_to_queue - adds a node to the queue.
* @new_node: a pointer to nouvelle node.
* @linn: the line num of the opercode.
*/
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int linn)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
