#include "apc.h"

int res;

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int carry = 0;	
	while(temp1 && temp2)
	{
		if(temp1 != NULL && temp2 != NULL)
		{
			res = temp1->data + temp2->data + carry;
			carry = 0;
			if(res > 9)
			{
				dl_insert_first(headR, tailR, res%10);
				carry = 1;
			}else
				dl_insert_first(headR, tailR, res);

		}
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	while(temp1 != NULL)
	{
		res = temp1->data + carry;
		carry = 0;
		if(res > 9)
		{
			dl_insert_first(headR, tailR, res%10);
			carry = 1;
		}else
			dl_insert_first(headR, tailR, res);

		temp1=temp1->prev;
	}
	while(temp2 != NULL)
	{
		res = temp2->data + carry;
		carry = 0;
		if(res > 9)
		{
			dl_insert_first(headR, tailR, res%10);
			carry = 1;
		}else
			dl_insert_first(headR, tailR, res);
			
		temp2=temp2->prev;
	}
	if(carry == 1)
	{
		dl_insert_first(headR, tailR, carry);
		carry = 0;
	}
}




