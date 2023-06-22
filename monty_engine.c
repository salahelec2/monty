#include "monty.h"

/**
 * start_vars -  initializes the members of a structure
 * @var: Global variables to initialize
 * Return: 0 Success, 1 Failed
 */
int start_vars(vars *var)
{
	var->file = NULL;
	var->buffer = NULL;
	var->tmp = 0;
	var->dict = create_instruction();
	if (var->dict == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * create_instruction - Create new functions dictionary
 * Return: pointer to dict
 */
instruction_t *create_instruction()
{
	instruction_t *instruct = malloc(sizeof(instruction_t) * 9);

	if (!instruct)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	instruct[0].opcode = "pall", instruct[0].f = op_pall;
	instruct[1].opcode = "push", instruct[1].f = op_push;
	instruct[2].opcode = "pint", instruct[2].f = op_pint;
	instruct[3].opcode = "pop", instruct[3].f = op_pop;
	instruct[4].opcode = "swap", instruct[4].f = op_swap;
	instruct[5].opcode = "add", instruct[5].f = op_add;
	instruct[6].opcode = "nop", instruct[6].f = NULL;
	instruct[7].opcode = "sub", instruct[7].f = op_sub;
	instruct[8].opcode = "div", instruct[8].f = op_divi;

	return (instruct);
}

/**
 * function_call - call the wanted function
 * @var: Global variables
 * @opcode: op code to be interpreted
 * Return: None
 */
int function_call(vars *var, char *opcode)
{
	int i;

	for (i = 0; var->dict[i].opcode; i++)
		if (strcmp(opcode, var->dict[i].opcode) == 0)
		{
			if (!var->dict[i].f)
				return (EXIT_SUCCESS);
			var->dict[i].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				var->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/**
 * _isdigit - checks whether a given string contains only digit
 * @string: string to check
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}

/**
 * free_all - Clean all program allocated memory
 * Return: None
 */
void free_all(void)
{
	if (gvar.buffer != NULL)
		free(gvar.buffer);
	if (gvar.file != NULL)
		fclose(gvar.file);
	free(gvar.dict);
	if (gvar.head != NULL)
	{
		while (gvar.head->next != NULL)
		{
			gvar.head = gvar.head->next;
			free(gvar.head->prev);
		}
		free(gvar.head);
	}
}

