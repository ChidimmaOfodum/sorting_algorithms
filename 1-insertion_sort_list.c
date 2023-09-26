#include "sort.h"
#include <limits.h>
void insert_min_node_head(listint_t **list);
/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: address of the head of the list
 *
 * Description: sorts a doubly linked list of integers using insertion sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *p, *prev, *next, *tmp;

	if (list == NULL || *list == NULL)
		return;

	insert_min_node_head(list);

	cur = (*list)->next;

	while (cur)
	{
		tmp = cur->next;
		p = cur->prev;

		while (p)
		{
			if (p->n > cur->n)
			{
				next = cur->next;
				prev = cur->prev;

				prev->next = next;
				if (next)
					next->prev = prev;

				prev = p->prev;
				prev->next = cur;
				p->prev = cur;
				cur->prev = prev;
				cur->next = p;

				print_list((*list)->next);
			}
			p = p->prev;
		}

		cur = tmp;
	}

	tmp = *list;
	*list = (*list)->next;
	free(tmp);
	(*list)->prev = NULL;
}

/**
 * insert_min_node_head - inserts dummy node at head of list
 * @list: the list
 *
 * Return: alway void
 */
void insert_min_node_head(listint_t **list)
{
	listint_t *node;
	int *temp;

	node = malloc(sizeof(listint_t));
	if (!node)
		return;
	temp = (int *)&node->n;
	*temp = INT_MIN;
	(*list)->prev = node;
	node->next = *list;
	node->prev = NULL;
	*list = node;
}
