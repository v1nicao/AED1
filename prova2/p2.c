#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct no {
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
     
void enqueue(Fila *fila, int data) {
    NO *novoNO = (NO*) malloc(sizeof(NO));
    novoNO->data = data;
    novoNO->next = NULL;
     
    if (fila->fim == NULL) {
        fila->inicio = novoNO;
    } else {
        fila->fim->next = novoNO;
    }
     
    fila->fim = novoNO;
    fila->size++;
}
     
int dequeue(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia\n");
        return -1; 
    }
     
    int data = fila->inicio->data;
    NO *temp = fila->inicio;
     
    fila->inicio = fila->inicio->next;
    free(temp);
     
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
     
    fila->size--;
    return data;
}
 
void print_fila(Fila* fila){
 
}
/*
int busca(Fila* fila, int numero, int v){
    int direita = fila->size-1, esquerda=0, meio, found=0;
    
    while(esquerda <= direita && !found){
        meio = (direita+esquerda)/2;
        if()
    }
 
}
*/
 
 
int main() {
    char letter;
    int n, i;
    Fila *fila = criarFila();
 
    scanf("%c", &letter);
    getchar();
    
    while(letter != 'T'){
        switch(letter){
            case 'D':
            dequeue(fila);
                //int i;
                if(fila->size != -1) printf("%d", fila->inicio->data);
                for(i=0; i<fila->size; i++){
                    if(fila->inicio->next != NULL) printf("%d ", fila->inicio->next);
                    else break;
                }
                //printf("\n");
            
            break;
            
            case 'E':
            scanf("%d", &n);
            enqueue(fila, n);
            //int i;
            printf("%d", fila->inicio->data);
            for(i=0; i<fila->size; i++){
                    if(fila->inicio->next != NULL) printf("%d ", fila->inicio->next);
                    else break;
                }
            printf("\n");
            break;
 
            case 'B':
 
            break;
 
            case 'C':
            break;
        }
        scanf("%c", &letter);
        getchar();
    }
 
 
 
    return 0;
}
 
/*Problema: Descreva as diferenças com relação à complexidade de tempo das operações de
inserção e remoção entre uma lista encadeada ordenada e uma lista encadeada não ordenada. Consi-
dere também as diferenças entre armazenamento estático com uso de vetores e alocação dinâmica por
encadeamento.
 
Em uma lista encadeada ordenada teria uma complexidade de tempo maior, pois teria que verificar em qual posição deve
ser colocada (inicio ou fim, ou meio) ou gasta com algoritmos de ordenação(pior caso). Já o uso de armazenamento estático seria 
bom se fosse já pré-definido como seria o tamanho máximo, caso contrário, a alocação dinâmica seria a mais recomendada
Em uma lista encaeada desordenada teria uma complexidade de tempo menor, pois não teria a preocupação de se insirir no fim ou no começo ou no meio,
tirando a necessidade de algorítimos extras para ordena-lo. O uso de armazenamento seria igual a ambos os os tipos de lista encadeada citadas.
*/