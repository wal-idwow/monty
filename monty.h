#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
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

extern bus_t bus;

/*functions.c*/
void pop_op(stack_t **stack, unsigned int line_number);
void push_op(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
void queue_st(stack_t **stack, unsigned int line_number);
void add_stack(stack_t **stack, int value);

/*more_functions.c*/
ssize_t read_line(char **lineptr, int file __attribute__((unused)));
char *line_cl(char *content);
void stack_free(stack_t *head);
char *reall(char *ptr, unsigned int old_size, unsigned int new_size);
int opcode_exec(char *line, stack_t **stack, unsigned int line_number,
			 FILE *monty_file, bus_t *bus);

/* more_stack.c */
void node_add(stack_t **head, int n);
void Nothing(stack_t **head, unsigned int counter);
void print_char(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void print_ele(stack_t **head, unsigned int counter);


/* operations.c */
void add_top_stack(stack_t **head, unsigned int counter);
void mul_top_stack(stack_t **head, unsigned int counter);
void mod_top_stack(stack_t **head, unsigned int counter);
void div_top_stack(stack_t **stack, unsigned int line_number);
void sub_top_stack(stack_t **stack, unsigned int counter);

/* stack_operations */
void rot_top(stack_t **stack, __attribute__((unused)) unsigned int counter);
void rot_bot(stack_t **stack, __attribute__((unused)) unsigned int counter);
void set_data_stack(stack_t **stack, unsigned int counter);
void swap_top_stack(stack_t **stack, unsigned int counter);

#endif
