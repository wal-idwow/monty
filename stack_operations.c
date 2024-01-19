#include "monty.h"

/**
 * rot_top - Rotates the stack to the top.
 * @stack: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void rot_top(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *current = *stack, *new_head;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	new_head = (*stack)->next;
	new_head->prev = NULL;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = current;
	(*stack) = new_head;
}

/**
 * rot_bot - Rotates the stack to the bottom.
 * @stack: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void rot_bot(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *tail;

	tail = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	while (tail->next)
	{
		tail = tail->next;
	}

	tail->next = *stack;
	tail->prev->next = NULL;
	tail->prev = NULL;
	(*stack)->prev = tail;
	(*stack) = tail;
}

/**
 * set_data_stack - Sets the format of the data to a stack (LIFO).
 * @stack: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void set_data_stack(stack_t **stack, unsigned int counter)
{
	(void)stack;
	(void)counter;
	bus.lifi = 0;
}

/**
 * swap_top_stack - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void swap_top_stack(stack_t **stack, unsigned int counter)
{
	stack_t *current;
	int node_count, temp;

	current = *stack;
	for (node_count = 0; current != NULL; node_count++)
		current = current->next;

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
