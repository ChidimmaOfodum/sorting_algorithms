#include "sort.h"
#include <limits.h>
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
