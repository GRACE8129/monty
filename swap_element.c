#include "monty.h"
/**
 * f_swap - swaps the top two elements of the stack.
 * @head: pointer to the head of the stack
 * @linenumber: line_number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int linenumber)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", linenumber);
		fclose(bus.montyfile);
		free(bus.currentline);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
