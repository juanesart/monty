#include "monty.h"
/**
 * f_sub - substracts the twice top elements.
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_sub(stack_t **head, unsigned int line_n)
{
	stack_t *temp;
	int c = 0, sub = 0;

	temp = *head;
	while (temp)
	{
		c++;
		temp = temp->next;
	}
	if (c < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_n);
		exit(EXIT_FAIL);
	}
	sub = (*head)->next->n - (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = sub;
}
/**
 * f_mul - multiplies the twice top elements.
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_mul(stack_t **head, unsigned int line_n)
{
	stack_t *temp;
	int c = 0, mul = 0;

	temp = *head;
	while (temp)
	{
		c++;
		temp = temp->next;
	}
	if (c < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_n);
		exit(EXIT_FAIL);
	}
	mul = (*head)->next->n * (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = mul;
}
/**
 * f_div - divides the twice top elements.
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_div(stack_t **head, unsigned int line_n)
{
	stack_t *temp;
	int c = 0, rdiv = 0;

	temp = *head;
	while (temp)
	{
		c++;
		temp = temp->next;
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_n);
		free_f();
		exit(EXIT_FAIL);
	}
	if (!head || !(*head) || c < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_n);
		free_f();
		exit(EXIT_FAIL);
	}
	rdiv = (*head)->next->n / (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = rdiv;
}
/**
 * f_mod - module of the twice top elements.
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_mod(stack_t **head, unsigned int line_n)
{
	stack_t *temp;
	int c = 0, rmod = 0;

	temp = *head;
	while (temp)
	{
		c++;
		temp = temp->next;
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_n);
		free_all(*head);
		exit(EXIT_FAIL);
	}
	if (c < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_n);
		free_all(*head);
		exit(EXIT_FAIL);
	}
	rmod = (*head)->next->n % (*head)->n;
	f_pop(head, line_n);
	(*head)->n = rmod;
}
