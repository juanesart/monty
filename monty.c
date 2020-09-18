#include "monty.h"

/**
 * main - entry point of the program
 * @argc: counter of arguments
 * @argv: array of arguments
 * Return: 0 success
 */

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAIL);
	}
	open_monty(argv[1]);
	return (EXIT_SUCCE);
}
