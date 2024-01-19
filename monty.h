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
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;


extern bus_t bus;
extern global_t vglo;

/* opcode_instructuions*/
void push_cmd(stack_t **stack, unsigned int line_number);
void pall_cmd(stack_t **stack, unsigned int line_number);
void pt_cmd_top(stack_t **doubly, unsigned int cline);
void rm_top_elem(stack_t **doubly, unsigned int cline);
void swap_stack(stack_t **doubly, unsigned int cline);
void take_to_queu(stack_t **doubly, unsigned int cline);
void take_to_stack(stack_t **doubly, unsigned int cline);
void add_stack(stack_t **doubly, unsigned int cline);
void nop_stack(stack_t **doubly, unsigned int cline);
void sub_stack(stack_t **doubly, unsigned int cline);
void div_stack(stack_t **doubly, unsigned int cline);
void mul_stack(stack_t **doubly, unsigned int cline);
void mod_stack(stack_t **doubly, unsigned int cline);
void print_fs(stack_t **doubly, unsigned int cline);
void print_st(stack_t **doubly, unsigned int cline);
void rotate_st(stack_t **doubly, unsigned int cline);
void reverse_st(stack_t **doubly, unsigned int cline);

/*opcode function*/
void (*opcode_select(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int check_char(char *s, char c);
char *tokenize(char *s, char *d);
int compr_str(char *s1, char *s2);

/* doubly linked list functions */
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node_top(stack_t **head, const int n);
void free_db(stack_t *stack);

/* main */
void glob_v_free(void);
void init_v_var(FILE *file);
FILE *check_op_file(int ac, char *av[]);

#endif /* __MONTY_H__ */
