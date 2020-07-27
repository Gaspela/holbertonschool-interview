#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: head of pointer.
 * @number: number to insert.
 * Return: new node.
 */
listint_t *insert_node(listint_t **head, int number)
{

	listint_t *new, *tmp;

	tmp = *head;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(new));

	if (new == NULL)
		return (NULL);

	if (*head == NULL || (*head)->n >= new->n)
	{
		new->n = number;
		new->next = NULL;
		new->next = *head;
		*head = new;
	}
	else
	{
		while (tmp->next != NULL && tmp->next->n < new->n)
		{
			tmp = tmp->next;
		}
		new->next = tmp->next;
		tmp->next = new;
	}
	return (new);
}
