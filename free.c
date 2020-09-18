#include "monty.h"
/**
 * free_f - free the stack
 */

void free_f(void)
{
	if (head)
	{
		while (head->next != NULL)
		{
			head = head->next;
			free(head->prev);
		}
		free(head);
	}
}
/**
 * free_all -  free all l_list
 * @head: pointer to head of linked
 */
void free_all(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (temp != NULL)
	{
		free(head);
		temp = temp->next;
		head = temp;
	}
}
