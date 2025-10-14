#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double random_0_1(void) {
	return (double)rand() / (double)RAND_MAX;
}


int main() {
	printf("problema Team \n");
	srand((unsigned int)time(NULL));

	int n = 0;
	int i = 0, j = 0;
	printf("ingrese el numero de problemas a resolver: ");
	scanf("%d", &n);

	int mat[n][3];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			int random = (random_0_1() < 0.5) ? 0 : 1;
			mat[i][j] = random;
		}
	}


	int cont_filas = 0, cont_cols = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (mat[i][j] == 1)
			{
				cont_filas++;
				if (cont_filas >= 2)
				{
					cont_cols++;
				}
			}
		}
		cont_filas = 0;
	}


	printf("\nla matriz es\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}


	printf("\nLos amigos van a resolver %d problemas \n", cont_cols);



	return 0;
}


