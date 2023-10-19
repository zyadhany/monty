#include "monty.h"


/**
 * print_dlistint - prints all the elements of list
 * @h: given list
 *
 * Return: numper of element in list
 */
size_t print_dlistint(const stack_t *h)
{
	size_t n = 0;

	while (h)
	{
		print_int(h->n);
		_putchar('\n');
		n++;
		h = h->next;
	}

	return (n);
}

/**
 * print_end_dlistint - prints all the elements of list
 * @h: given list
 *
 * Return: numper of element in list
 */
size_t print_end_dlistint(const stack_t *h)
{
	size_t n = 0;

	if (h)
		while (h->next)
			h = h->next;

	while (h)
	{
		print_int(h->n);
		_putchar('\n');
		n++;
		h = h->prev;
	}

	return (n);
}

/**
 * add_dnodeint_end - check the code
 * @head: given list
 * @n: added element
 *
 * Return: pointer to list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp, *at = NULL;

	if (!head)
		return (NULL);

	tmp = malloc(sizeof(stack_t));

	if (!tmp)
		return (NULL);

	tmp->n = n;
	tmp->next = NULL;
	tmp->prev = NULL;

	at = *head;
	if (!*head)
	{
		*head = tmp;
		return (*head);
	}

	while (at->next)
	{
		at = at->next;
	}

	at->next = tmp;
	tmp->prev = at;

	return (tmp);
}

/**
 * rem_node - check the code
 * @head: given list
 *
 * Return: free element of list
 */
void rem_node(stack_t *head)
{
	if (!head)
		return;
	
	if (head->prev)
		head->prev->next = head->next;

	if (head->next)
		head->next->prev = head->prev;

	free(head);
}

/**
 * free_dlistint - check the code
 * @head: given list
 *
 * Return: free all element of list
 */

void free_dlistint(stack_t *head)
{
	if (head)
	{
		free_dlistint(head->next);
		free(head);
	}
}
