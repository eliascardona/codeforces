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
    int rdx=0;

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
        }
    }

	int zeros_count = 0;
	int zeros_indexes_vector[k];
	// Colecting the zeros' positions
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


	printf("\n\n");
    int waste_idx=0;
	// final sorting
    for (rdx=0; rdx < zeros_count; rdx++)
	{
		// wc = waste cell 
		int wc_current_index = zeros_indexes_vector[rdx];
		int wc_next_index = zeros_indexes_vector[rdx+1];

		if(rdx == zeros_count-1) break;

    	for (waste_idx = wc_current_index; waste_idx < wc_next_index; waste_idx++)
		{
			printf("%d  ", waste_idx);
			if (waste_idx = wc_current_index)
			{
				int correctCropPlant = getNextCropPlant(field_linear_vector[waste_idx-1]);
				field_linear_vector[waste_idx+1] = correctCropPlant;
			}

			int correctCropPlant = getNextCropPlant(field_linear_vector[waste_idx+1]);
			field_linear_vector[waste_idx] = correctCropPlant;
		}
		printf("\n");
	}


    // Printing the matrix after processing (and initial if k=0)
    printf("\n\n FINAL COLORFUL FIELD IS \n");
    for (idx=0; idx < n; idx++)
    {
        for (jdx=0; jdx < m; jdx++)
        {
            printf("\t%d", field[idx][jdx]);
        }
        printf("\n");
    }

    printf("\n");

    for (rdx=0; rdx < zeros_count; rdx++)
	    printf("%d\t", zeros_indexes_vector[rdx]);


    printf("\n zeros count is %d", zeros_count);
    printf("\n\n");



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


