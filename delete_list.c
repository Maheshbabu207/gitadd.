#include "apc.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head==NULL && *tail==NULL)
    {
        return FAILURE;
    }
    else
    {
        if((*head)->prev==NULL && (*head)->next==NULL)
        {
            free(*head);
            *head=NULL;
            *tail=NULL;
            return SUCCESS;
        }
        else
        {
            while(*head!=NULL && *tail!=NULL)
            {
                dl_delete_last(head,tail);
            }
        }
    }

}
