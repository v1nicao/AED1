#include <stdio.h>
#include <stdlib.h>
     
typedef struct no {
    int critic; // Horário crítico antes da morte
    int data;
    struct no *next;
} NO;
     
typedef struct fila {
    NO *inicio;
    NO *fim;
    int size;
} Fila;
     
Fila* criarFila() {
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->size = 0;
    return fila;
}
     
void enqueue(Fila *fila, int hrinitial, int data) {
    NO *novoNO = (NO*) malloc(sizeof(NO));
    novoNO->critic = data;
    novoNO->data = hrinitial;
    novoNO->next = NULL;
     
    if (fila->fim == NULL) {
        // Fila vazia, insere o primeiro elemento
        fila->inicio = novoNO;
    } else {
        // Insere o elemento no final da fila
        fila->fim->next = novoNO;
    }
     
    fila->fim = novoNO;
    fila->size++;
}
     
int dequeue(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("A FILA ESTA VAZIA\n");
        return -1; // Valor inválido, pois a fila está vazia
    }
     
    int data = fila->inicio->data;
    NO *temp = fila->inicio;
     
    fila->inicio = fila->inicio->next;
    free(temp);
     
    if (fila->inicio == NULL) {
        // Se a fila ficou vazia após a remoção, ajusta o ponteiro fim
        fila->fim = NULL;
    }
     
    fila->size--;
    return data;
}
     
int convertMIN(int hr, int min, int critic) {
    int aux = hr * 60;
    int convert;
    convert = aux + min + critic;
    return (convert);
}

int guardHOUR(int hour, int min){
    int guard = hour;
 
    return ((guard*60)+min);
}
     
int main() {
    int i, qtd_pacientes, died = 0;
    int hour, min, critic;
    Fila *fila = criarFila();
     
    scanf("%d", &qtd_pacientes);
    //int currentTime = 7 * 60; // Tempo atual de atendimento começa em 7h (7*60 minutos)
     
    for (i = 0; i < qtd_pacientes; i++) {
        scanf("%d %d %d", &hour, &min, &critic);
        int temp = convertMIN(hour, min, critic);
        int guarda = guardHOUR(hour, min);
        enqueue(fila, guarda, temp);
    }
     
     
    int currentTime = (fila->inicio->data);
    while (fila->inicio != NULL) {
        int tempoCritico = fila->inicio->critic;
            //printf("hora: %d\n", currentTime);
            //printf("tempo critico: %d\n", tempoCritico);
        if (tempoCritico < currentTime) {
            died++;
        }
        dequeue(fila);
        currentTime = currentTime + 30;
    }
     
    printf("%d\n", died);
     
    return 0;
}