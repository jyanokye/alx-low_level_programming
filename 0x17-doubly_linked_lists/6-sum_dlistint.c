#include "lists.h"
/**
 * sum_dlistint - funtion sum all data
 * @head: single list in
 * Return: sum all data
 */
int sum_dlistint(dlistint_t *head)
{
	int sumary;


	for (sumary = 0; head != NULL;)
	{
		sumary += head->n;
		head = head->next;
	}
	return (sumary);
}
