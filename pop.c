#include "monty.h"
/**
 * f_pop - removes the top element of the stack
 * @head: pointer to the head of the stack
 * @linenumber: line_number
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int linenumber)
{
	stack_t *current_node;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", linenumber);
		fclose(bus.montyfile);
		free(bus.currentline);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	*head = current_node->next;
	free(current_node);
}
