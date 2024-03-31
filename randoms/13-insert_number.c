#include "lists.h"
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;

	while (head != NULL)
	{
		current = *head;
		*head = head->next;


