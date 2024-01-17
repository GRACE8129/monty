#include "monty.h"
/**
 * f_pint - prints the top element of the stack
 * @head: pointer to the head of the stack
 * @linenumber: line_number
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int linenumber)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linenumber);
		fclose(bus.montyfile);
		free(bus.currentline);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
