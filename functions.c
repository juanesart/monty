#include "monty.h"
/**
 * stack_creator - creates a stack with the data n
 * @n: data to be inserted in the stack
 * @fd: pointer to a monty file
 * @buffer: pointer to string of monty commands
 * Return: pointer to the stack
 */
stack_t *stack_creator(int n, FILE *fd, char *buffer)
{
	stack_t *stack = malloc(sizeof(stack_t));

	if (stack == NULL)
	{
		fclose(fd);
		free(buffer);
		free_f();
		fprintf(stderr, "Error: Fail allocating memory\n");
		exit(EXIT_FAIL);
	}
	stack->n = n;
	return (stack);
}

/**
 * f_pall - prints all the values on the stack
 * @head: pointer to the first element on stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_pall(stack_t **head, unsigned int line_n)
{
	stack_t *temp;

	(void) line_n;

	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * f_push - pushes an element to the stack
 * @stack: pointer to the new element
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_push(stack_t **stack, unsigned int line_n)
{
	(void) line_n;

	(*stack)->next = head;
	(*stack)->prev = NULL;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = (*stack);
	head = (*stack);
}
/**
 * f_pint -  prints the value at the top of the stack.
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_pint(stack_t **head, unsigned int line_n)
{
	if (!(*head) || !head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
		free_f();
		exit(EXIT_FAIL);
	}
	printf("%d\n", (*head)->n);
}
/**
 * f_pop - removes the top element of the stack
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_pop(stack_t **head, unsigned int line_n)
{
	if (!(*head) || !head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
		exit(EXIT_FAIL);
	}
	if ((*head)->next == NULL)
	{
		free(*head);
		(*head) = NULL;
	}
	else
	{
		(*head) = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
}
