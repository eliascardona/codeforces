#include <stdio.h>
#include <stdlib.h>

int getNextPlant(int prevPlant);

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

    if (k > 0) {
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
            int prev_plant_index = lineal_index - 1;
            int next_plant_index = lineal_index + 1;

            field_linear_vector[lineal_index] = 0;

            // applying the next plant inmediatly
            if (prev_plant_index >= 0 && next_plant_index < (n*m)) {
                int next_plant_value = getNextPlant(field_linear_vector[prev_plant_index]);
                field_linear_vector[next_plant_index] = next_plant_value;
            }
        }
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

int getNextPlant(int prevPlant) {
    switch(prevPlant) {
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        default:
            return 4;
    }
}


