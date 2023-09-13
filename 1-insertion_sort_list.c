#include "sort.h"

void
insertion_sort_list(listint_t **list)
{
    listint_t *node, *prox, *ant;

    if (!list || !*list)
        return;

    node = *list;
    /* start a loop to travel the list */
    while (node)
    {   
        /* set a pointer to each, next and previus elements of the list */
        ant = node->prev;
        prox = node->next;
        while (ant && (ant->n > node->n))
        {
            /* change pointer between current and previus node */

            ant->next = node->next;
            /* 
            If next node exist, change its *prev pointer to ponint to the ant node and not to the current anymore
            has to be befor modifiyng the nodes pointers
             */
            if (node->next != NULL)
            {
                node->next->prev = ant;
            }
            /* continue changeing node and ant */      
            node->next = ant;
            node->prev = ant->prev;
            ant->prev = node;

            /* if prev node exist, change its *next pointer */
            if (node->prev)
            {
                node->prev->next = node;
            }
            /* if it doesnt exist means now the current node has to be the head of the list */
            else
            {
                *list = node;
            }
            ant = node->prev;
            print_list(*list);
        }
        node = prox;
    }
    
}