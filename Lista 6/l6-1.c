// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
 
int partition(int *A, int p, int r) {
    int j, aux, pivo = A[r], i = p - 1;
    for (j = p; j <= r - 1; j++) {
        if (A[j] <= pivo) {
            i++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    A[r] = A[i + 1];
    A[i + 1] = pivo;
    return i + 1;
}
 
void quicksort(int *A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
 
int main() {
    int n, k, i;
 
    // Leitura do tamanho do vetor
    scanf("%d", &n);
 
    // Alocar espaço para o vetor
    int *v = (int *)malloc(n * sizeof(int));
 
    // Leitura dos elementos do vetor
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
 
    // Leitura do valor de k
    scanf("%d", &k);
 
    // Ordenar o vetor usando quicksort
    quicksort(v, 0, n - 1);
 
    // Imprimir o k-ésimo menor elemento do vetor
    printf("%d\n", v[k - 1]);
 
    // Liberar memória alocada
    free(v);
 
    return 0;
}