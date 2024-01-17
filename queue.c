#include "monty.h"
/**
 * f_queue - sets the stack mode to queue (FIFO)
 * @head: stack head
 * @linenumber: line_number
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int linenumber)
{
	(void)head;
	(void)linenumber;
	bus.lifi = 1;
}

/**
 * addqueue - adds a node to the tail stack
 * @n: The new_value to be added
 * @head: pointer to the head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *current_node;

	current_node = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (current_node)
	{
		while (current_node->next)
			current_node = current_node->next;
	}
	if (!current_node)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current_node->next = new_node;
		new_node->prev = current_node;
	}
}
