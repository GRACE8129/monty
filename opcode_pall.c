#include "monty.h"
/**
 * f_opcode_pall - prints the elements of the stack
 * @head: a pointer to the head of the stack.
 * @linenumber: unused parameter
 * Return: no return
*/
void f_opcode_pall(stack_t **head, unsigned int linenumber)
{
	stack_t *h;
	(void)linenumber; /*unused parameter*/

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
