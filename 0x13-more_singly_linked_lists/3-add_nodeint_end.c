#include "lists.h"

/**
* add_nodeint_end - adds a new node at the end
* of listint_t list.
* @head: pointer to list
* @n: element to be added
* Return:  the address of the new element,
* or NULL if it failed
*/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *c_node = *head;
	listint_t *sire;

	sire = (listint_t *) malloc(sizeof(listint_t));

	if (!sire)
	{
		free(sire);
		return (NULL);
	}
	sire->n = n;
	sire->next = NULL;

	if (*head == NULL)
	{
		*head = sire;
	}
	else
	{
		while (c_node->next != NULL)
		{
			c_node = c_node->next;
		}
		c_node->next = sire;
	}
	return (*head);
}
