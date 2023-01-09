#include "lists.h"
/**
 * sum_dlistint - funtion sum all data
 * @head: single list in
 * Return: sum all data
 */
int sum_dlistint(dlistint_t *head)
{
	int dumary;


	for (dumary = 0; head != NULL;)
	{
		dumary += head->n;
		head = head->next;
	}
	return (dumary);
}
