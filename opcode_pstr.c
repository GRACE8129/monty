#include "monty.h"
/**
 * f_opcode_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: a pointer to the head of the stack.
 * @linenumber: line_numbers.
 * Return: no return
*/
void f_opcode_pstr(stack_t **head, unsigned int linenumber)
{
	stack_t *h;
	(void)linenumber;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
