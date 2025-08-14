#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define max_altura 8.0

// Función que genera un entero aleatorio entre 0 y max (inclusive)
int randy(double max) {
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }
    return (int)round(((double)rand() / RAND_MAX) * max);
}

int main() {
    const int n = 150000;  // tamaño seguro para la pila
    int k;

    printf("CODEFORCES. Valla de Policarpo.\n");
    printf("Encuentra el segmento contiguo que tenga la menor altura.\n\n");

    printf("Ingresa k: ");
    scanf("%d", &k);

    if (k > n || k <= 0) {
        printf("Error: k debe ser mayor que 0 y menor o igual que n.\n");
        return 1;
    }

    // Declarar arreglos en la pila
    int v[n];                  // vector de alturas
    int num_segments = n - k + 1;
    int sums[num_segments];     // vector de sumas

    // Llenar la valla con alturas aleatorias
    for (int i = 0; i < n; i++) {
        v[i] = randy(max_altura);
    }

    // Calcular sumas de segmentos
    for (int i = 0; i < num_segments; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum += v[i + j];
        }
        sums[i] = sum;
    }

    // Encontrar mínimo
    int min_sum = sums[0];
    int min_index = 0;
    for (int i = 1; i < num_segments; i++) {
        if (sums[i] < min_sum) {
            min_sum = sums[i];
            min_index = i;
        }
    }

    // Mostrar resultados
    printf("\n----------------------------\n");
    printf("SEGMENTO LOCALIZADO \n");
    printf("----------------------------\n");
    printf("Posicion %d \n", min_index + 1);
    printf("altura %d \n", min_sum);
    printf("----------------------------\n\n");

    return 0;
}



