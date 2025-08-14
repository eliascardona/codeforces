#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

bool is_multiple_of_4(int n);
int randy(double max);

int main()
{
	int n, k;

	printf("Polycarpus' fence\n");
	printf("Enter the length of your fence: ");
	scanf("%i", &n);
	printf("Enter the number of consecutive planks you need to remove: ");
	scanf("%i", &k);

	int idx, jdx, count = 1;
	int fence[n];
	int total_sums = (int) n / k;
	int sums_vec[total_sums];

	for (idx = 0; idx < n; idx++)
		fence[idx] = randy(8.0);

	printf("initial fence\n");
	for (idx = 0; idx < n; idx++)
		printf("%i , ", fence[idx]);
	printf("\n-------------------------------------\n");

	for (idx = 0; idx < total_sums; idx++)
		sums_vec[idx] = 0;

	int inner_iteration_begin;
	int inner_count=0;

	for (idx = 1; idx < (n+1); idx++)
	{
		++count;

//		if (is_multiple_of_4(count))
		
			inner_count++;
			/** 
			 * Como `k` siempre es 4, para sumar cada bloque de 4 elementos consecutivos,
			 * el índice inicial debe ser `count - k` (en base 0) y no `k` fijo en la primera iteración.  
			 * Además, el índice de fence[] debe ser ajustado a base 0, por lo que `count - k` es correcto.
			 */
			inner_iteration_begin = count - k;

			printf("internal iteration starts in ------------------------- %i \n", inner_iteration_begin);

			/** 
			 * Usamos índices 0-based: `count - 1` como último índice, y sumamos hacia `inner_iteration_begin` inclusivo.
			 * Además, `inner_count` debe usarse como índice 0-based para `sums_vec`.
			 */
			/*      super importante count -1      */
			for (jdx = count - 1; jdx >= inner_iteration_begin && jdx >= 0; jdx--)
			{
				sums_vec[inner_count - 1] += fence[jdx];
			}
		
	}

//	for (idx = 0; idx < n; idx++)
//		printf("%i , ", arr[idx]);

	printf("Sums of each plank\n");
	for (idx = 0; idx < total_sums; idx++)
		printf("%i , ", sums_vec[idx]);

	return 0;
}


int randy(double max)
{
	static int seeded = 0;
	if (!seeded) { srand(time(NULL)); seeded = 1; }
	return (int)round(((double)rand() / RAND_MAX) * max);
}


bool is_multiple_of_4(int n)
{
	return (n & 3) == 0;
}


