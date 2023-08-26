#include <stdio.h>
#include <stdlib.h>
 
// Função para mesclar dois subarrays ordenados em um único array ordenado
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
 
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
 
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
 
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}
 
// Função principal do Merge Sort
void mergeSort(int arr[], int size) {
    int i;
    if (size <= 1) {
        return; // O array já está ordenado ou é vazio
    }
 
    int middle = size / 2;
    int left[middle];
    int right[size - middle];
 
    // Dividir o array em duas metades
    for (i = 0; i < middle; i++) {
        left[i] = arr[i];
    }
    for (i = middle; i < size; i++) {
        right[i - middle] = arr[i];
    }
 
    // Chama o mergeSort recursivamente para cada metade
    mergeSort(left, middle);
    mergeSort(right, size - middle);
 
    // Mescla as metades ordenadas
    merge(arr, left, middle, right, size - middle);
}
 
int main(){
    int num_dias=0, num_lanchonete=0, i, j, pode=0;
 
    scanf("%d", &num_lanchonete);
 
    int tab_price[num_lanchonete];
    for(i=0; i<num_lanchonete; i++){
        scanf("%d", &tab_price[i]);
    }
    mergeSort(tab_price, num_lanchonete);
 
    scanf("%d", &num_dias);
 
    int qtd_price;
    for(i=0; i<num_dias; i++){
        scanf("%d", &qtd_price);
        // Verifica quantas lanchonetes têm preços menores ou iguais à quantidade de moedas disponíveis
        int j;
        for (j = 0; j < num_lanchonete; j++) {
            if (qtd_price >= tab_price[j]) {
                pode++;
            } else {
                break; // Como o array está ordenado, se encontrar um preço maior, pode parar de verificar
            }
        }
        printf("%d\n", pode);
        pode = 0;
    }
 
/*
    for(i=0; i<num_dias; i++){
        for(j=0; j<num_lanchonete; j++){
            if(qtd_price[i] <= tab_price[j]) pode++;
        }
        printf("%d\n", pode);
        pode = 0;
    }
    */
 
    return 0;
}