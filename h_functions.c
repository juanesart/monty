#include "monty.h"
/**
* check_is_num - checks if the arguments are numbers
* @tokens: Argument to check for ints
 * @fd: pointer to a monty file
 * @buffer: pointer to string of monty commands
* Return: argument or -1 if fails
*/
stack_t *check_is_num(char *tokens, FILE *fd, char *buffer)
{
	stack_t *sta = NULL;
	int num = 0, i = 0, neg = 0;

	if (tokens && tokens[0] == '-')
	{
		neg = -1;
		tokens++;
	}
	if (isdigit(*tokens) && tokens)
	{
		while (tokens[i] != '\0')
		{
			if (isdigit(tokens[i] == 0))
				return (NULL);
			i++;
		}
		num = atoi(tokens);
		if (neg != 0)
			num = num * -1;
		sta = stack_creator(num, fd, buffer);
		return (sta);
	}
	return (NULL);
}
