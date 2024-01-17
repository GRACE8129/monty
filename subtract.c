#include "monty.h"
/**
  *f_sub- sustracts the top element of the stack from the second element
  *@head: pointer to the head of the stack
  *@linenumber: line_number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int linenumber)
{
	stack_t *current_node;
	int sub, node_count;

	current_node = *head;
	for (node_count = 0; current_node != NULL; node_count++)
		current_node = current_node->next;
	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", linenumber);
		fclose(bus.montyfile);
		free(bus.currentline);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	sub = current_node->next->n - currrent_node->n;
	current_node->next->n = sub;
	*head = current_node->next;
	free(current_node);
}
