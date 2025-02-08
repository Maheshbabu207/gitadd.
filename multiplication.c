#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int carry = 0, count = 0, result = 0;

    // Temporary list to store  results
    Dlist *tempHeadR1 = NULL;
    Dlist *tempTailR1 = NULL;

    Dlist *tempHeadR2 = NULL;
    Dlist *tempTailR2 = NULL;

    while (temp2 != NULL)
    {
        for (int i = 0; i < count; i++)
        {
            dl_insert_first(&tempHeadR2, &tempTailR2, 0);
        }
        temp1 = *tail1;
        while (temp1)
        {
            int result = (temp1->data * temp2->data) + carry;
            // carry = 0;
            carry = result / 10;
            result = result % 10;
            dl_insert_first(&tempHeadR2, &tempTailR2, result);

            temp1 = temp1->prev;
        }
        if (carry > 0)
        {
            dl_insert_first(&tempHeadR2, &tempTailR2, carry);
            carry = 0;
        }

        addition(&tempHeadR1, &tempTailR1, &tempHeadR2, &tempTailR2, headR, tailR);

        dl_delete_list(&tempHeadR1, &tempTailR1);
        dl_delete_list(&tempHeadR2, &tempTailR2);

        tempHeadR1 = *headR;
        tempTailR1 = *tailR;

        *headR = NULL;
        *tailR = NULL;

        temp2 = temp2->prev;
        temp1 = *tail1;
        count++;
    }

    *headR = tempHeadR1;
    *tailR = tempTailR1;

    return SUCCESS;
}
