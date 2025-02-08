#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*store the operands into the list */
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

//void digit_to_list(Dlist **head, Dlist **tail, char *str);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);


/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Inserted values at last*/
int dl_insert_last(Dlist **head, Dlist **tail, int data);

/*Inserted values at first*/
int dl_insert_first(Dlist **head, Dlist **tail, int data);

/*Delete List*/
int dl_delete_list(Dlist **head, Dlist **tail);

/*Delete last*/
int dl_delete_last(Dlist **head, Dlist **tail);

/*validation for subtractions lengths*/
void validation(char *argv[]);

/* Printing the list */
void print_list(Dlist *head);

#endif
