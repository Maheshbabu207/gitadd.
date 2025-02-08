#include "apc.h"

int data;
extern int flag;

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    /* Definition goes here */

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int borrow = 0;
    
    while (temp1 || temp2)
    {
        if (temp1 && temp2)
        {

            if (temp1->data < temp2->data)
            {

                data = (10 + temp1->data) - (temp2->data) - borrow;

                dl_insert_first(headR, tailR, data);
                borrow = 1;
            }
            else
            {
                data = temp1->data - temp2->data - borrow;
                borrow = 0;
                if (data < 0)
                {

                    data += 10;
                    borrow = 1;
                }
                dl_insert_first(headR, tailR, data);
            }
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        else if (temp1 != NULL && temp2 == NULL)
        {
            data = temp1->data - borrow;
            borrow = 0;

            if (data < 0)
            {

                data += 10;
                borrow = 1;
            }
            dl_insert_first(headR, tailR, data);
            temp1 = temp1->prev;
        }
    }
    while ((*headR)->data == 0 && (*headR != *tailR))
    {
        *headR = (*headR)->next;
        free((*headR)->prev);
        (*headR)->prev = NULL;
    }

    if (flag)
    {
        Dlist *temp = *headR;

        while (temp != NULL)
        {
            if (temp->data != 0)
            {
                temp->data = -1 * (temp->data);

                *headR = temp;

                break;
            }
            temp = temp->next;
        }
    }

    return SUCCESS;
}
