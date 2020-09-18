#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define EXIT_FAIL 1
#define EXIT_SUCCE 0


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

stack_t *head;
void open_monty(char *file_to_open);
void command_checker(char *tok, char *tokens,
unsigned int line_n, FILE *fd, char *buffer);
stack_t *stack_creator(int n, FILE *fd, char *buffer);
void f_pall(stack_t **head, unsigned int line_n);
void f_push(stack_t **stack, unsigned int line_n);
void f_pint(stack_t **head, unsigned int line_n);
void f_pop(stack_t **head, unsigned int line_n);
void f_swap(stack_t **head, unsigned int line_n);
void f_add(stack_t **head, unsigned int line_n);
void f_nop(stack_t **head, unsigned int line_n);
void f_sub(stack_t **head, unsigned int line_n);
void f_mul(stack_t **head, unsigned int line_n);
void f_div(stack_t **head, unsigned int line_n);
void f_mod(stack_t **head, unsigned int line_n);
void f_pchar(stack_t **head, unsigned int line_n);
void f_pstr(stack_t **head, unsigned int line_n);
void f_rotl(stack_t **head, unsigned int line_n);
void f_rotr(stack_t **head, unsigned int line_n);
void c_w_args(char *tok, char *tokens,
unsigned int line_n, FILE *fd, char *buffer);
void free_all(stack_t *head);
int c_n_args(char *tok, unsigned int line_n);
stack_t *check_is_num(char *tokens, FILE *fd, char *buffer);
void free_f(void);
#endif
