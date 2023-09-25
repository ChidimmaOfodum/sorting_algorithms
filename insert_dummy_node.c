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
        temp = INT_MIN;
        (*list)->prev = node;
        node->next = *list;
        node->prev = NULL;
        *list = node;
}
