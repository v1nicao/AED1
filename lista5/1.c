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
 
int main() {
    int cont = 0, dec = 0, i;
    char exp[1000];
    Pilha *stack = (Pilha*) malloc(sizeof(Pilha));
    stack->topo = NULL;
    stack->size = 0;
 
    //printf("Digite a expressao: ");
    fgets(exp, sizeof(exp), stdin);
 
    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch == '(') {
            push(stack, ch);
            cont++;
            dec = cont;
        }
        else if (ch == ')') {
            dec--;
        }
    }
 
    if (dec == 0)
        printf("Correta\n");
    else
        printf("Incorreta\n");
 
    return 0;
}