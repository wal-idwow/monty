#include "monty.h"

/**
 * pop_op - removes top element of stack.
 * @stack: Pointer to stack head.
 * @line_number: line number.
 * Return: no return.
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = current->next;
	free(current);
}

/**
 * push_op - adds node to stack.
 * @stack: pointer to stack head.
 * @line_number: line number.
 * Return: no return.
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	int value, index = 0, negative = 0, non_digit = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			negative++;

		for (; bus.arg[index] != '\0'; index++)
		{
			if (bus.arg[index] > '9' || bus.arg[index] < '0')
				non_digit = 1;
		}

		if (non_digit == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(stack, value);
	else
		addqueue(stack, value);
}

/**
 * print_str - prints string starting at top of stack.
 * @stack: pointer to the stack head.
 * @line_number: line number.
 * Return: no return.
 */
void print_str(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void) line_number;

	current = *stack;
	while (current && current->n > 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

/**
 * queue_st - sets the stack behavior to queue.
 * @stack: pointer to the stack head.
 * @line_number: line number.
 * Return: no return.
 */
void queue_st(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifi = 1;
}

/**
 * add_stack - add node to tail of stack.
 * @stack: pointer to the stack head.
 * @value: new value.
 * Return: no return.
 */
void add_stack(stack_t **stack, int value)
{
	stack_t *new_node, *current;

	current = *stack;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = NULL;

	if (current)
	{
		while (current->next)
			current = current->next;
	}

	if (!current)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current->next = new_node;
		new_node->prev = current;
	}
}
