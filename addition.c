#include "monty.h"
/**
 * f_addition - adds the top two elements of the stack.
 * @head: A pointer to the head of the stack
 * @linenumber: line_number
 * Return: no return
*/
void f_addition(stack_t **head, unsigned int linenumber)
{
	stack_t *current;
	int len = 0, sum;

	current = *head;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", linenumber);
		fclose(bus.montyfile);
		free(bus.currentline);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	sum = current->n + current->next->n;
	current->next->n = sum;
	*head = current->next;
	free(current);
}
