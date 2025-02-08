#include "apc.h"
int calculate_length(Dlist *head)
{
    int len = 0;
    Dlist *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int compare_lists(Dlist *head1, Dlist *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data)
        {
            return 1;
        }
        else if (head1->data < head2->data)
        {
            return -1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int len1 = calculate_length(*head1);
    int len2 = calculate_length(*head2);
    int count = 0;

    if (len1 < len2)
    {
        return count;
    }
    if(len1 == len2)
    {
        int value = compare_lists(*head1, *head2);
        if(value < 0)
        {
            return count;
        }
        else if(value == 0)
        {
            count = 1;
            return count;
            
        }
    }

    while (1)
    {
        
        if (len1 > len2)
        {
            subtraction(head1, tail1, head2, tail2, headR, tailR);
            dl_delete_list(head1, tail1);

            *head1 = *headR;
            *tail1 = *tailR;

            *headR = NULL;
            *tailR = NULL;
            count++;
        }
        else if (len1 == len2)
        {
            int comparison = compare_lists(*head1, *head2);
            if (comparison > 0)
            {
                subtraction(head1, tail1, head2, tail2, headR, tailR);
                dl_delete_list(head1, tail1);

                *head1 = *headR;
                *tail1 = *tailR;

                *headR = NULL;
                *tailR = NULL;
                count++;
            }
            else if (comparison == 0)
            {
                count++;
                break;
            }
            else if(comparison < 0)
            {
                break;
            }
        }
        else
        {
            break;
        }

        len1 = calculate_length(*head1);
    }
    *headR = *head1;
    *tailR = *tail1;
    return count;
}
