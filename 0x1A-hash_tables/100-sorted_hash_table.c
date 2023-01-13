#include "hash_tables.h"

/**
 * hash_table_create - function to create a sorted hash table
 * @size: Size of the array
 * Return: Null for error or a pointer to a new hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; ++i)
	{
		ht->array[i] = NULL;
	}
	ht->head = NULL;
	ht->tail = NULL;

	return (ht);
}

/**
 * hash_table_set - add an element at the sorted hash table
 * @ht: Type pointer to the sorted hash table
 * @key: Type const char pointer of the key
 * @value: Value of the key
 * Return: 0 if fail or 1 if success
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *copy_val;
	hash_node_t *new_ht, *tp_t;

	if (ht == NULL || key == NULL || *key == 48 || value == NULL)
		return (0);

	copy_val = strdup(value);
	if (copy_val == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	for (tp_t = ht->head; tp_t != 0; tp_t = tp_t->next)
	{
		if (strcmp(tp_t->key, key) == 0)
		{
			free(tp_t->value);
			tp_t->value = copy_val;
			return (1);
		}
	}
	new_ht = malloc(sizeof(hash_node_t));
	if (new_ht == NULL)
	{
		free(copy_val);
		return (0);
	}
	new_ht->key = strdup(key);
	if (new_ht->key == NULL)
	{
		free(copy_val);
		free(new_ht);
		return (0);
	}
	new_ht->value = copy_val;
	new_ht->next = ht->array[idx];
	ht->array[idx] = new_ht;

	if (ht->head == NULL)
	{
		new_ht->prev = NULL;
		new_ht->next = NULL;
		ht->head = new_ht;
		ht->tail = new_ht;
	}
	else if (strcmp(ht->head->key, key) > 0)
	{
		new_ht->prev = NULL;
		new_ht->next = ht->head;
		ht->head->prev = new_ht;
		ht->head = new_ht;
	}
	else
	{
		for(tp_t = ht->head;
		    tp_t->next != NULL && strcmp(tp_t->next->key, key) < 0;
		tp_t = tp_t->next)
		;
		new_ht->prev = tp_t;
		new_ht->next = tp_t->next;
		if (tp_t->next == NULL)
			ht->tail = new_ht;
		else
			tp_t->next->prev = new_ht;
		tp_t->next = new_ht;
	}
	return (1);
}

/**
 * hash_table_get - function to get a value of a key in a sorted hash table
 * @ht: type pointer const char of the sorted hash_table
 * @key: type pointer char the key of the hash table
 * Return: Null if the key is not found or the value of the key
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *current_node;

	if (ht == NULL || *key == 48 || key == NULL)
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);

	for (current_node = ht->head;
	     current_node != NULL && strcmp(current_node->key, key) != 0;
	     current_node = current_node->next)
		;
	if (current_node == NULL)
	{
		return (NULL);
	}
	else
	{
		return (current_node->value);
	}
}

/**
 * hash_table_print - fucntion to print a sorted hash table
 * @ht: type pointer the sorted hash_table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");
	for (current_node = ht->head; current_node != NULL;
	     current_node = current_node->next)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * hash_table_print_rev - fucntion to print a sorted hash table in reverse
 * @ht: type pointer the sorted hash_table
 */
void hash_table_print_rev(const hash_table_t *ht)
{
	hash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");
	for (current_node = ht->tail; current_node != NULL;
	     current_node = current_node->prev)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * hash_table_delete - function that delete a sorted hash table
 * @ht: type pointer of the sorted hash_tabe
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *node, *temp;

	if (ht == NULL)
		return;

	for (node = ht->head; node != 0; node = temp)
	{
		temp = node->next;
		free(node->key);
		free(node->value);
		free(node);
	}
	free(head->array);
	free(head);
}
