#include "monty.h"
/**
* add_top_stack - adds the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void add_top_stack(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;

	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
	h = NULL;
}

/**
 * mul_top_stack - Multiplies the top two elements of the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void mul_top_stack(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_length = 0, result;

	current = *head;

	/* Calculate the length of the stack */
	while (current)
	{
		current = current->next;
		stack_length++;
	}

	/* Check if the stack has at least two elements */
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;

	result = current->next->n * current->n;
	current->next->n = result;

	/* Update the head to the next element */
	*head = current->next;

	/* Free the current element */
	free(current);
}

/**
 * mod_top_stack - Computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void mod_top_stack(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_length = 0, result;

	current = *head;

	/* Calculate the length of the stack */
	while (current)
	{
		current = current->next;
		stack_length++;
	}

	/* Check if the stack has at least two elements */
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;

	/* Check for division by zero */
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = current->next->n % current->n;
	current->next->n = result;

	/* Update the head to the next element */
	*head = current->next;

	/* Free the current element */
	free(current);
}

/**
 * div_top_stack - Divides the top two elements of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 * Return: No return.
 */
void div_top_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *temp;
	int len = 0, result;

	current = *stack;

	/* Count elements number in the stack */
	while (current)
	{
		current = current->next;
		len++;
	}

	/* Check if the stack has at least two elements */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	/* Check for division by zero */
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = current->next->n / current->n;
	/* Update the next element's value with the result */
	current->next->n = result;

	/* Update the head to the next element */
	temp = current->next;
	current->next = temp->next;
	if (temp->next)
		temp->next->prev = current;

	/* Free the current element */
	free(temp);
}

/**
 * sub_top_stack - subtracts top element of stack from second top element.
 * @stack: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void sub_top_stack(stack_t **stack, unsigned int counter)
{
	stack_t *current;
	int difference, node_count;

	current = *stack;
	for (node_count = 0; current != NULL; node_count++)
		current = current->next;

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	difference = current->next->n - current->n;
	current->next->n = difference;
	*stack = current->next;
	free(current);
}
