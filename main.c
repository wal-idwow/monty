#include "monty.h"
void (*f)(stack_t **stack, unsigned int line_number);
glob_t glob_v;

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
	nlines = getline(&glob_v.bf, &size, fd);
	while (nlines != -1)
	{
		lines[0] = tokenize(glob_v.bf, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = opcode_select(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glob_v.culine);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				glob_v_free();
				exit(EXIT_FAILURE);
			}
			glob_v.secin = tokenize(NULL, " \t\n");
			f(&glob_v.doub, glob_v.culine);
		}
		nlines = getline(&glob_v.bf, &size, fd);
		glob_v.culine++;
	}

	glob_v_free();

	return (0);
}
