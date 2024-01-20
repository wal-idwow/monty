#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob - global structure to use in the functions
 * @st_qu: is stack or queue , lifo
 * @culine: current line , cont
 * @secin: second parameter inside the current line, arg
 * @doub: doubly linked list, head
 * @fd: file descriptor
 * @bf: input text, buffer
 * Description: doubly linked list node structure
 */
typedef struct glob
{
	char *bf;
	char  *secin;
	int st_qu;
	unsigned int culine;
	stack_t *doub;
	FILE *fd;
} glob_t;

/**
 * struct bus_s - variables - values, file, line content
 * @val: value, arg
 * @file: pointer to monty file, file
 * @line: line content, content
 * @swtch: flag change stack <-> queue, lifi
 * Description: carries values through the program
 */

typedef struct bus_s
{
	char *val;
	char *line;
	int swtch;
	FILE *file;
}  bus_t;

extern bus_t bus;
extern glob_t glob_v;

/* commands */
void push_cmd(stack_t **head, unsigned int cline);
void pall_cmd(stack_t **head, unsigned int cline);
void pt_cmd_top(stack_t **head, unsigned int cline);
void rm_top_elem(stack_t **head, unsigned int cline);
void swap_stack(stack_t **head, unsigned int cline);

/*node operations */
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node_top(stack_t **head, const int n);
int check_char(char *s, char c);
int compr_str(char *s1, char *s2);
FILE *check_op_file(int ac, char *av[]);

/*stack operations*/
void add_stack(stack_t **doubly, unsigned int cline);
void nop_stack(stack_t **doubly, unsigned int cline);
void sub_stack(stack_t **doubly, unsigned int cline);
void div_stack(stack_t **doubly, unsigned int cline);
void mul_stack(stack_t **doubly, unsigned int cline);

/* stack manipulation*/
void take_to_queu(stack_t **doubly, unsigned int cline);
void take_to_stack(stack_t **doubly, unsigned int cline);
void rotate_st(stack_t **doubly, unsigned int cline);
void reverse_st(stack_t **doubly, unsigned int cline);

/* more operations */
void mod_stack(stack_t **doubly, unsigned int cline);
void print_st(stack_t **doubly, unsigned int cline);
void print_fs(stack_t **doubly, unsigned int cline);

/*opcode */
void (*opcode_select(char *code))(stack_t **stack, unsigned int cline);
void free_db(stack_t *head);
char *tokenize(char *str, char *delim);
void glob_v_free(void);
void init_v_var(FILE *file);

#endif /* __MONTY_H__ */
