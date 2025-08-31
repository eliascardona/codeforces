#include <stdio.h>
#include <stdlib.h>

int getNextCropPlant(int prevPlant);
int getPreviousCropPlant(int prevPlant);

int main() {
    int n=0, m=0;
    int k=0, t=0;
    printf("CODEFORCES. Colorful field.\n");
    printf("Finding the right plants \n\n");

    printf("Enter n (rows): ");
    scanf("%d", &n);

    printf("Enter m (columns): ");
    scanf("%d", &m);

    printf("Enter k (waste fields): ");
    scanf("%d", &k);

    printf("Enter t (planted fields): ");
    scanf("%d", &t);

    int linear_field_length = n*m;
    int field[n][m];
    int plant[3] = {1, 2, 3};

    int a=0, b=0;
    int i=0, j=0;

    int idx=0, jdx=0;
    int rdx=0, sdx=0;

    // filling of original matrix, the original field
    for (idx=0; idx < n; idx++)
    {
        for (jdx=0; jdx < m; jdx++)
        {
            int plant_index = (idx * m + jdx) % 3;
            field[idx][jdx] = plant[plant_index];
        }
    }

    int *field_linear_vector = &field[0][0];

    if (k > 0)
    {
        // Enter waste cells BEFORE first print
        for (rdx=0; rdx < k; rdx++)
        {
            printf("x: ");
            scanf("%d", &a);
            printf("y: ");
            scanf("%d", &b);

            if (a > n || b > m)
            {
                printf("incorrect input\n");
                return 1;
            }

            int lineal_index = (a-1) * m + (b-1);

            int next_plant_index = lineal_index + 1;
            field_linear_vector[lineal_index] = 0;

            // applying the next plant inmediatly
            if (lineal_index >= 0 && next_plant_index < (n*m)) {
                int next_plant_value = getNextCropPlant(field_linear_vector[lineal_index-1]);
                field_linear_vector[next_plant_index] = next_plant_value;
            }
        }
    }

	int zeros_count = 0;
	int zeros_indexes_vector[k];
	// Applying the proper sequence
    for (idx=0; idx < n; idx++)
    {
        for (jdx=0; jdx < m; jdx++)
        {
			int lineal_index = (idx * m + jdx);

			if (field_linear_vector[lineal_index] == 0)
			{
				zeros_indexes_vector[zeros_count] = lineal_index;
				zeros_count++;
			}
        }
    }

	// wc = waste cell 
	int wc_first_index = zeros_indexes_vector[0];

	// final sequence
    for (rdx=0; rdx < zeros_count; rdx++)
	{
		// wc = waste cell 
		int wc_current_index = zeros_indexes_vector[rdx];

		if(rdx == 0) continue;

		if(rdx == 1)
		{
	    	for (sdx = wc_first_index + 2; sdx < wc_current_index; sdx++)
			{
				int previousCropPlant = getPreviousCropPlant(field_linear_vector[sdx]);
				field_linear_vector[sdx] = previousCropPlant;
			}
		}

		int wc_begin = zeros_indexes_vector[rdx-1];

	   	for (sdx = wc_begin; sdx < wc_current_index; sdx++)
		{
			int previousCropPlant = getPreviousCropPlant(field_linear_vector[sdx]);
			field_linear_vector[sdx] = previousCropPlant;
		}

		if(rdx == zeros_count-1) break;
	}


    // Printing the matrix after processing (and initial if k=0)
    for (idx=0; idx < n; idx++)
    {
        for (jdx=0; jdx < m; jdx++)
        {
            printf("\t%d", field[idx][jdx]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}

int getNextCropPlant(int prevPlant) {
    switch(prevPlant) {
        case 3:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        default:
            return 4;
    }
}

int getPreviousCropPlant(int currentCropPlant) {
    switch(currentCropPlant) {
        case 3:
            return 2;
        case 2:
            return 1;
        case 1:
            return 3;
        default:
            return 4;
    }
}


