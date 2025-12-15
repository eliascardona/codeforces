#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Easter Eggs ---------\n\n");

	int n;
	int i = 0, j = 0;
	// ROYGBIV
	char colors[7] = "ROYGBIV";

	printf("Enter the number of eggs: ");
	scanf("%d", &n);

	char eggs[n];
	int aux = 0;

	for (i = 0; i < n; i++)
	{
		if (i % 7 == 0)
		{
			if (i == 0) continue;

			aux = i;
			if (aux == 0)
			{
				for (j = 0; j < 7; j++)
				{
					eggs[j] = colors[j];

					printf("%c  ", colors[j]);
				}
			}

			for (j = i; j < (i+7); j++)
			{
				eggs[j] = colors[j%7];

				printf("%c", colors[j%7]);
			}


		}
	}

	printf("\n\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", eggs[i]);
	}


	printf("\n");

	return 0;
}
