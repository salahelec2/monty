#include "monty.h"

#define BUFFER_SIZE 256
vars gvar;

/**
 * main - Stacks, Queues - LIFO, FIFO main program
 * @ac: arguments count
 * @av: argunemt vector / data
 * Return: 0 Success, 1 Failure
 */
int main(int ac, char **av)
{
	size_t buffer_size = BUFFER_SIZE;
	char *opcode_directive;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (start_vars(&gvar) != 0)
		return (EXIT_FAILURE);
	gvar.file = fopen(av[1], "r");
	if (!gvar.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	gvar.buffer = malloc(buffer_size * sizeof(char));
	if (!gvar.buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	while (fgets(gvar.buffer, buffer_size, gvar.file) != NULL)
	{
		if (strlen(gvar.buffer) > 0 && gvar.buffer[strlen(gvar.buffer) - 1] == '\n')
			gvar.buffer[strlen(gvar.buffer) - 1] = '\0';
		opcode_directive = strtok(gvar.buffer, " \r\t\n");
		if (opcode_directive != NULL)
		{
			if (function_call(&gvar, opcode_directive) == EXIT_FAILURE)
			{
				/*free_all();*/
				return (EXIT_FAILURE);
			}
		}
		gvar.line_number++;
	}
	free_all();
	return (EXIT_SUCCESS);
}
