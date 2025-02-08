#include "apc.h"

int main(int argc, char *argv[])
{
	

	/* Declare the pointers */

	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL, *tailR = NULL;


	char operator= argv[2][0];

	switch (operator)
	{
	case '+':
		digit_to_list(&head1, &tail1, &head2, &tail2, argv);
		/* call the function to perform the addition operation */
		print_list(head1);
		print_list(head2);
		addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		printf("result: ");
		print_list(headR);
		break;
	case '-':
		validation(argv);
		digit_to_list(&head1,&tail1,&head2,&tail2,argv);
		print_list(head1);
		print_list(head2);
		/* call the function to perform the subtraction operation */
		subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		printf("result: ");
		print_list(headR);
		break;
	case 'x':
		digit_to_list(&head1, &tail1, &head2, &tail2, argv);
		print_list(head1);
		print_list(head2);
		/* call the function to perform the multiplication operation */
		multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		printf("result: ");
		print_list(headR);
		break;
	case '/':
		digit_to_list(&head1, &tail1, &head2, &tail2, argv);

		print_list(head1);
		print_list(head2);
		/* call the function to perform the division operation */
		int value = division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		printf("result:%d\n", value);
		break;
	default:
		printf("Invalid Input:-( Try again...\n");
	}
	return 0;
}
