#include "hash_tables.h"
/**
 * hash_table_create - create a hash table of BUFF_SIZE
 * @size: len of new hash tab
 * Return: new hash tab
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_tab = NULL;
	unsigned long int i;

	/* create table hash */
	new_tab = malloc(sizeof(hash_table_t));
	if (new_tab == NULL)
		return (NULL);

	/* create array for each node in the table hash */
	new_tab->array = malloc(sizeof(hash_node_t *) * size);
	if (new_tab->array == NULL)
	{
		free(new_tab);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		new_tab->array[i] = NULL;
	}
	/* save len of table_hash create */
	new_tab->size = size;

	return (new_tab);
}

/**
 * hash_table_set - function that adds an element to hash table
 * @ht: hash table to update
 * @key: key
 * @value: value of key
 * Return: updated table
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx = 0;
	char *temp_val = NULL;
	hash_node_t *temp = NULL;
	hash_node_t *new = NULL;

	if (ht == NULL || ht->array == NULL || value == NULL)
		return (0);

	if (strlen(key) == 0 || key == NULL)
		return (0);
	temp_val = strdup(value);
	if (temp_val == NULL)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);

	/* Collision checker */
	temp = ht->array[idx];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = temp_val;
			temp->value = strdup(value);
			free(temp_val);
			return (1);
		}
		temp = temp->next;	
	}

	/* If no collision, insert node */
	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(new);
		return (0);
	}
	new->key = strdup(key);
	new->value = temp_val;
	new->next = ht->array[idx];
	ht->array[idx] = new;
	return (1);
}


/**
 * hash_table_get - function that retrieves a value by key
 * @ht: hash table
 * @key: key to search
 * Return: associated value, or NULL if key not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx = 0;
	hash_node_t *temp = NULL;

	if (key == NULL)
		return (NULL);

	if (ht != NULL)
	{
		idx = key_index((const unsigned char *)key, ht->size);
		temp = ht->array[idx];
		/* Look for key and return value if found */
		while (temp != NULL)
		{
			if (strcmp(temp->key, key) == 0)
				return (temp->value);
			temp = temp->next;
		}
	}
	return (NULL);
}


/**
 * hash_table_print - function that prints a hash table
 * @ht: a hash table
 * Return: a dictionary format of the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *temp = NULL;

	if (ht == NULL)
		return;

	printf("{");
	while (i < ht->size)
	{
		temp = ht->array[i];
		while (temp)
		{
			printf("'%s' : '%s'", temp->key, temp->value);
			if (ht->array[i + 1] == NULL)
				break;
			printf(", ");
			temp = temp->next;
		}
		i++;
	}
	printf("}\n");
}

/**
 * hash_table_delete - function that deletes a hash table
 * @ht: table 
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *temp = NULL, *next_temp = NULL;

	if (ht == NULL)
		return;

	while (i < ht->size)
	{
		next_temp = ht->array[i];
		while (temp)
		{
			temp = next_temp;
			next_temp = next_temp->next;
			if (temp->key != NULL)
				free(temp->key);
			if (temp->value != NULL)
				free(temp->value);
			free(temp);
		}
		free(ht->array[i]);
		i++;
	}
	free(ht->array);
	free(ht);
}
