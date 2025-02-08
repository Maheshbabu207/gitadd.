#include <stdio.h>
#include "apc.h"

#include <string.h>

int flag = 0;
void validation(char *argv[])
{
	
	int len1 = strlen(argv[1]);
	int len2 = strlen(argv[3]);

	if (len1 < len2)
	{
		char *temp = argv[1];
		argv[1] = argv[3];
		argv[3] = temp;

		flag = 1;
	}
	else if (len1 == len2)
	{

		if (strcmp(argv[1], argv[3]) < 0)
		{
			char *temp = argv[1];
			argv[1] = argv[3];
			argv[3] = temp;

			flag = 1;
		}
	}
}
