#include "monty.h"
/**
* exec - executes the opcode
* @stack: A pointer to the head of the stack
* @linenumber: line_counter
* @montyfile: poiner to the monty file
* @currentline: line content from monty file
* Return: no return
*/
int exec(char *currentline, stack_t **stack, unsigned int linenumber,
		FILE *montyfile)
{
	instruction_t opst[] = {
				{"push_operation", f_push}, {"opcode_pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop}, {"swap", f_swap}, {"addition", f_add},
				{"nop", f_nop}, {"sub", f_sub}, {"divide", f_divide},
				{"mul", f_mul}, {"mod", f_mod}, {"pchar", f_pchar},
				{"opcode_pstr", f_pstr}, {"rotl", f_rotl}, {"rot_right", f_rotr},
				{"queue", f_queue}, {"set_stack_mode", f_stack}, {NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(currentline, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, linenumber);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", linenumber, op);
		fclose(montyfile);
		free(currentline);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
