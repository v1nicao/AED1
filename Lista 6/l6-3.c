#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
 
void copy_vector(int v[], int v1[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        v1[i] = v[i];
    }
}
 
int insertion_sort(int v[], int n) {
    int cont = 0, j;
 
    for (j = 1; j < n; j++) {
        int aux = v[j];
        int i = j - 1;
 
        while ((i >= 0) && (v[i] > aux)) {
            v[i + 1] = v[i];
            i = i - 1;
            cont++;
        }
        v[i + 1] = aux;
        cont++;
    }
    return cont;
}
 
int selection_sort(int v[], int n) {
    int cont = 0, i, j;
 
    for (i = 0; i < n - 1; i++) {
        int min = i;
 
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) min = j;
        }
 
        if (i != min) {
            int aux = v[i];
            v[i] = v[min];
            v[min] = aux;
            cont++;
        }
    }
    return cont;
}
 
int main() {
    int tam_vet, i;
 
    scanf("%d", &tam_vet);
    int vetor[tam_vet];
    for (i = 0; i < tam_vet; i++) {
        scanf("%d", &vetor[i]);
    }
 
    int vetor1[tam_vet];
    copy_vector(vetor, vetor1, tam_vet);
 
    int trocas_insertion = insertion_sort(vetor, tam_vet);
    int trocas_selection = selection_sort(vetor1, tam_vet);
    //int valor_sub = fabs(trocas_insertion - trocas_selection);
 
    //printf("%d\n",valor_sub);
    printf("%d\n", trocas_insertion - trocas_selection);
 
    return 0;
}