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
		fence[idx] = randy(12.0);

	for (idx = 0; idx < total_sums; idx++)
		sums_vec[idx] = 0;


	for (idx = 1; idx < (n+1); idx++)
	{
		++count;

		if (is_multiple_of_4(count))
		{
			int inner_iteration_begin = count - k;

			for (jdx = count; jdx >= inner_iteration_begin && jdx >= 0; jdx--)
			{
				sums_vec[jdx] += fence[jdx];

				/*if (jdx == count)
					continue;

				if (fence[jdx+1] < fence[jdx])
				{
				}*/
			}
		}
	}


//	for (idx = 0; idx < n; idx++)
//		printf("%i , ", arr[idx]);
/*
	for (idx = 0; idx < 5; idx++)
	{
		++count;
	}
	printf("\n %i \n", count);
*/


	printf("Sums of each plank\n");
	for (idx = 0; idx < total_sums; idx++)
		printf("%i , ", sums_vec[idx]);

	printf("\n\n");

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



















