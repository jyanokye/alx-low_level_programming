#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t
 * linked list, and returns the head node’s data (n)
 * @head: head of linked list
 * Return: if the linked list is empty return 0
 * else, return the head node's data (n)
 */

int pop_listint(listint_t **head)
{
	int a;
	listint_t *c_node = *head;
	listint_t *sire;

	if (*head == NULL)
		return (0);

	a = (c_node)->n;
	sire = c_node->next;
	free(c_node);
	*head = sire;
	return (a);
}
