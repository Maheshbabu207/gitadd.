#include "apc.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    if(*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }
    else
    {
       (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
        return SUCCESS;
    }
}
