#include "apc.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    //printf("data = %d\n", data);
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
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}
