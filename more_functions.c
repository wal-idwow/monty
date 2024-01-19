#include "monty.h"

/**
* read_line - Reads a line from the standard input.
* @lineptr: Pointer to the buffer where the line is stored.
* @file: File descriptor (ignored in this version).
* Return: Number of bytes read, or -1 on failure.
*/
ssize_t read_line(char **lineptr, int file __attribute__((unused)))
{
	size_t bufsize = 0;

	return (getline(lineptr, &bufsize, stdin));
}

/**
* line_cl - Removes trailing newline characters from a string.
* @content: The string to be cleaned.
* Return: Pointer to the cleaned string.
*/
char *line_cl(char *content)
{
	size_t len = strlen(content);

	while (len > 0 && (content[len - 1] == '\n' || content[len - 1] == '\r'))
	{
		content[len - 1] = '\0';
		len--;
	}
	return (content);
}

/**
* stack_free - frees a doubly linked list
* @head: head of the stack
*/
void stack_free(stack_t *head)
{
	stack_t *current, *next_node;

	current = head;

	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

/**
* reall - Reallocates a memory block.
* @ptr: Pointer to the old memory block.
* @old_size: Size of the old memory block.
* @new_size: Size of the new memory block.
* Return: Pointer to the newly allocated memory block.
*/
char *reall(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = ptr[i];

	free(ptr);

	return (new_ptr);
}

/**
 * opcode_exec - Executes the opcode.
 * @line: Line content.
 * @stack: Pointer to the stack head.
 * @line_number: Line counter.
 * @monty_file: Pointer to the Monty file.
 * @bus: pointer to a structure of type
 * Return: 0 if successful, 1 otherwise.
 */
int opcode_exec(char *line, stack_t **stack, unsigned int line_number,
			 FILE *monty_file, bus_t *bus)
{
	instruction_t opcodes[] = {
		{"push", push_op}, {"pall", print_ele}, {"pint", print_top},
		{"pop", pop_op}, {"swap", swap_top_stack}, {"add", add_stack},
		{"nop", Nothing}, {"sub", sub_top_stack}, {"div", div_top_stack},
		{"mul", mul_top_stack}, {"mod", mod_top_stack}, {"pchar", print_char},
		{"pstr", print_str}, {"rotl", rot_top}, {"rotr", rot_bot},
		{"queue", queue_st}, {"stack", set_data_stack},
		{NULL, NULL}
	};

	unsigned int index = 0;
	char *opcode;

	/* Get the opcode and argument from the line */
	opcode = strtok(line, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);

	bus->arg = strtok(NULL, " \n\t");
	/* Find the corresponding function for the opcode */
	while (opcodes[index].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[index].opcode) == 0)
		{
			opcodes[index].f(stack, line_number);
			return (0);
		}
		index++;
	}
	/* Handle unknown instruction error */
	if (opcode && opcodes[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(monty_file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
