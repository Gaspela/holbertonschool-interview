#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
* check_palindrome - Element list
* @head: head the list *
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int check_palindrome(listint_t *head)
{
	int length = 0;

	while (head)
	{
		head = head->next;
		length++;
	}
	return (length);
}
/**
* is_palindrome - function in C that checks if a singly linked list
* is a palindrome.
* @head: head the list *
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	int length;
	int n = 0;
	int list[2048];

	listint_t *node = *head;

	if (head == NULL || *head == NULL)
		return (1);

	if ((*head)->next == NULL)
		return (1);

	length = check_palindrome(node);
	node = *head;
	for (n = 0; n < length / 2; n++)
	{
		list[n] = node->n;
		node = node->next;
	}
	n--;
	if (length % 2 == 1)
		node = node->next;

	while (node)
	{
		if (node->n != list[n])
			return (0);
		n--;
		node = node->next;
	}
	return (1);
}
