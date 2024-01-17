#include "monty.h"
/**
  *f_rot_right- rotates the stack to the bottom
  *@head: A pointer to the head of the stack.
  *@linenumber: line_number
  *Return: no return
 */
void f_rot_right(stack_t **head, __attribute__((unused)) unsigned int linenumber)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
