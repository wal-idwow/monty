#ifndef MONTY_H

#define MONTY_H


#define _GNU_SOURCE

#include <stdio.h>

#include <unistd.h>

#include <string.h>

#include <stdlib.h>

#include <ctype.h>

#include <stdarg.h>


/**

 * struct stack_s - doubly linked list representation of a stack (or queue)

 * @n: integer

 * @prev: points to the previous element of the stack (or queue)

 * @next: points to the next element of the stack (or queue)

 *

 * Description: doubly linked list node structure

 * for stack, queues, LIFO, FIFO

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

 * for stack, queues, LIFO, FIFO

 */

typedef struct instruction_s

{

        char *opcode;

        void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;


extern stack_t *head;

typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/

void unlock_fichier(char *fichier_nam);

void per_fich(FILE *fd);

int sep_line(char *buff, int ln_num, int shape);

void lock_for(char *opercode, char *value, int ln, int shape);

/*Stack operations*/

stack_t *create_node(int nnode);

void free_nodes(void);

void oput_stck(stack_t **escalier, unsigned int lnb_opc);

void inclu_st(stack_t **novl_node, __attribute__((unused))unsigned int lnb_opc);

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int linn);

void call_fun(op_func func, char *operationc, char *val, int ln, int shape);

void oput_hight(stack_t **escalier, unsigned int lnb_opc);

void out_hight(stack_t **escalier, unsigned int lnb_opc);

void nil(stack_t **escalier, unsigned int lnb_opc);

void exch_elm(stack_t **escalier, unsigned int lnb_opc);

/*Math operations with nodes*/

void inp_stack(stack_t **escalier, unsigned int lnb_opc);

void elem_stck(stack_t **escalier, unsigned int lnb_opc);

void aug_elem(stack_t **escalier, unsigned int lnb_opc);

void red_ele(stack_t **escalier, unsigned int lnb_opc);

void dis_nod(stack_t **escalier, unsigned int lnb_opc);

/*String operations*/

void output_ascval(stack_t **escalier, unsigned int lnb_opc);

void output_strg(stack_t **escalier, __attribute__((unused))unsigned int lnb_opc);

void rt_fnsbm(stack_t **escalier, __attribute__((unused))unsigned int lnb_opc);

/*Error hanlding*/

void rt_lnstop(stack_t **escalier, __attribute__((unused))unsigned int lnb_opc);

void erreur(int erreur_code, ...);

void plus_erreur(int erreur_code, ...);

void mang_erreur(int erreur_code, ...);

#endif