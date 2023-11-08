#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Mova os elementos do arr[0..i-1] que são maiores que a chave
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[100]; // Tamanho máximo do array
    int n = 0; // Tamanho atual do array

    printf("Insira os valores a serem ordenados (digite -1 para encerrar):\n");

    int value;
    while (1) {
        scanf("%d", &value);

        if (value == -1) {
            break; // Encerra a entrada de valores
        }

        arr[n] = value;
        n++;

        insertionSort(arr, n); // Ordena o array após cada inserção

        printf("Array ordenado parcialmente:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    printf("Array final ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
