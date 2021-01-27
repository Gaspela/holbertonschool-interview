#include "lists.h"
/**
 * find_listint_loop - checks list for a loop
 * @head: pointer to the first element
 * Return: the address of the node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	if (head == NULL)
		return (0);

	slow = head->next;
	for (fast = slow->next; slow && fast && fast->next; fast = fast->next->next)
	{
		if (slow == head || fast == head)
			return (head);
		if (slow == fast && fast != head)
		{
			head = head->next;
			slow = head;
			fast = head;
		}
		slow = slow->next;
	}
	return (NULL);
}
