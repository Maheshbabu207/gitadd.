#include "apc.h"
int dl_delete_last(Dlist **head, Dlist **tail)
{
    if(*head == NULL && *tail == NULL)
    {
        return FAILURE;
    }
    Dlist *temp = temp;
    if(*head == *tail)
    {
        free(*head);
        *head = *tail = NULL;
    }
    else
    {
        *tail = (*tail)->prev;
        free((*tail)->next);
        (*tail)->next = NULL;
        return SUCCESS;
    }    
}
