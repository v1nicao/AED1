#include <stdio.h>
#include <stdlib.h>
 
typedef struct no {
    int data;
    struct no *next;
} NO;
 
typedef struct pilha {
    NO *topo;
    int size;
} Pilha;
 
void push(Pilha *stack, int data) {
    NO *novoNO = (NO*) malloc(sizeof(NO));
    novoNO->data = data;
    novoNO->next = stack->topo;
    stack->topo = novoNO;
    stack->size++;
}
 
int pop(Pilha *stack) {
    if (stack->topo == NULL) printf("A PILHA ESTA VAZIA\n");
 
    int data = stack->topo->data;
    NO *temp = stack->topo;
    stack->topo = stack->topo->next;
    free(temp);
    stack->size--;
    return data;
}
 
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
 
int main() {
    int qtd, i;
    int vagao[1000];
    Pilha *stack = (Pilha*) malloc(sizeof(Pilha));
    stack->topo = NULL;
    stack->size = 0;
 
    scanf("%d", &qtd);
 
    for (i = 0; i < qtd; i++) {
        scanf("%d", &vagao[i]);
        push(stack, vagao[i]);
    }
 
    int temp[qtd];
    Pilha *tempStack = (Pilha*) malloc(sizeof(Pilha));
    tempStack->topo = NULL;
    tempStack->size = 0;
 
    for (i = 0; i < qtd; i++) {
        temp[i] = pop(stack);
        push(tempStack, temp[i]);
    }
 
    bubbleSort(vagao, qtd);
 
    for (i = 0; i < qtd; i++) {
        if (temp[i] != vagao[i]) {
            printf("No\n");
            return 0;
        }
    }
 
    printf("Yes\n");
 
    return 0;
}