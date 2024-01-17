#include "monty.h"
/**
 * f_div - divides the top two elements of the stack.
 * @head: pointer to the stack head
 * @linenumber: line_number
 * Return: no return value
*/
void f_div(stack_t **head, unsigned int linenumber)
{
	stack_t *h;
	int len = 0, result;

	h = *head;

	/* calculate the length of the stack*/
	while (h)
	{
		h = h->next;
		len++;
	}

	/*check if the stack has less than 2 elements */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", linenumber);
		fclose(bus.montyfile);
		free(bus.currentline);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;

	/*check for division by zero */
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linenumber);
		fclose(bus.montyfile);
		free(bus.currentline);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/*perform division and update the stack*/

	result = h->next->n / h->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
