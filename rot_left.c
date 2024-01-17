#include "monty.h"
/**
  *f_rotl- rotates the stack to the top
  *@head: pointer to the head of the stack
  *@linenumber: line_number
  *Return: no return
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int linenumber)
{
	stack_t *tmp = *head, *bottom_element;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	bottom_element = (*head)->next;
	bottom_element->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = bottom_element;
}
