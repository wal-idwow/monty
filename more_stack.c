#include "monty.h"
/**
* node_add - add node to the head stack
* @head: head of the stack
* @n: new_value
* Return: no return
*/
void node_add(stack_t **head, int n)
{

	stack_t *new_node;

	/* Allocate memory for the new node*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory for new node\n");
		exit(EXIT_FAILURE);
	}

	/* Set values for the new node*/
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	/* If stack not empty, update previous current head pointer*/
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	/* Set the next pointer of the new node to the current head*/
	new_node->next = *head;

	/* Update the head pointer to the new node*/
	*head = new_node;
}

/**
 * Nothing - Does nothing.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void Nothing(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
}

/**
 * print_char - Prints the character at the top of the stack,
 *  followed by a newline.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 * Return: No return.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}

/**
 * print_top - Prints the top element of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 * Return: No return.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * print_ele - Prints the elements of the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number (not used).
 * Return: No return.
 */
void print_ele(stack_t **head, unsigned int counter)
{
	stack_t *current;

	(void)counter;

	current = *head;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
