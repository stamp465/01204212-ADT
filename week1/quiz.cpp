#include <stdio.h>
int main(void)
{
	char letter = 'A';
	int number = 20;
	if ((letter >= 'A') && (letter <= 'Z'))
		if (number >= 10)
			printf("*****\n");
	else
		printf("#####\n");
}
