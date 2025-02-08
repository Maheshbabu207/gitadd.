#include "apc.h"

#include<string.h>

void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
    int i=0, j=0;
	char *str1 = argv[1];
	while(str1[i] != '\0')
	{
		int data = str1[i] - '0';
		dl_insert_last(head1, tail1, data);
		i++;
	}
	char *str2 = argv[3];
	while(str2[j] != '\0')
	{
		int data = str2[j] - '0';
		dl_insert_last(head2, tail2, data);
		j++;
	}

}
