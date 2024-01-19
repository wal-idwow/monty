#include "monty.h"
void (*f)(stack_t **stack, unsigned int line_number);
global_t vglo;

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_op_file(ac, av);
	init_v_var(fd);
	nlines = getline(&vglo.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = tokenize(vglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = opcode_select(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				glob_v_free();
				exit(EXIT_FAILURE);
			}
			vglo.arg = tokenize(NULL, " \t\n");
			f(&vglo.head, vglo.cont);
		}
		nlines = getline(&vglo.buffer, &size, fd);
		vglo.cont++;
	}

	glob_v_free();

	return (0);
}
