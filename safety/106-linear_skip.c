#include "search_algos.h"

/**
 * linear_skip - Searches for an item in a sorted singly linked list
 *               of integers using linear skip.
 * @list: A pointer to the head of the linked list to search.
 * @value: The value to search for.
 *
 * Return: If value is not found or the head of the list is NULL, return NULL
 *         Otherwise, return a pointer to the first node containing the value.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *jump;

	if (list == NULL)
		return (NULL);

	for (current = jump = list; jump->next != NULL && jump->n < value;)
	{
		current = jump;
		if (jump->express != NULL)
		{
			jump = jump->express;
			printf("Checked value at index [%ld] = [%d]\n",
					jump->index, jump->n);
		}
		else
		{
			while (jump->next != NULL)
				jump = jump->next;
		}
	}

	printf("Found value between indexes [%ld] and [%ld]\n",
			current->index, jump->index);

	for (; current->index < jump->index && current->n <
	     value; current = current->next)
		printf("Checked value at index [%ld] = [%d]\n", current->index, current->n);
	printf("Checked value at index [%ld] = [%d]\n", current->index, current->n);

	return (current->n == value ? current : NULL);
}
