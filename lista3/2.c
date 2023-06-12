#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
 
typedef struct {
    int elements[MAX_SIZE];
    int size;
} IntSet;
 
// Função para inicializar o conjunto
void initSet(IntSet* set) {
    set->size = 0;
}
 
// Função para verificar se um elemento pertence ao conjunto
int contains(const IntSet* set, int element) {
    int i;
    for (i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return 1; // Retorna 1 se o elemento estiver no conjunto
        }
    }
    return 0; // Retorna 0 se o elemento não estiver no conjunto
}
 
// Função para adicionar um elemento ao conjunto
void addElement(IntSet* set, int element) {
    if (set->size < MAX_SIZE && !contains(set, element)) {
        set->elements[set->size] = element;
        set->size++;
    }
}
 
// Função para remover um elemento do conjunto
void removeElement(IntSet* set, int element) {
    int found = 0;
    int i;
    for (i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < set->size - 1; i++) {
            set->elements[i] = set->elements[i + 1];
        }
        set->size--;
    }
}
 
// Função para imprimir os elementos do conjunto
void printSet(const IntSet* set) {
    int i;
    printf("%d", set->elements[0]);
    for (i = 1; i < set->size; i++) {
        printf(" %d", set->elements[i]);
    }
    printf("\n");
}
 
// Função para realizar a união de dois conjuntos
IntSet unionSets(const IntSet* set1, const IntSet* set2) {
    IntSet result;
    initSet(&result);
    int i;
    
    // Adiciona os elementos do primeiro conjunto
    for (i = 0; i < set1->size; i++) {
        addElement(&result, set1->elements[i]);
    }
 
    // Adiciona os elementos do segundo conjunto
    for (i = 0; i < set2->size; i++) {
        addElement(&result, set2->elements[i]);
    }
 
    return result;
}
 
// Função para realizar a interseção de dois conjuntos
IntSet intersectSets(const IntSet* set1, const IntSet* set2) {
    IntSet result;
    initSet(&result);
    int i;
    // Verifica quais elementos do primeiro conjunto estão no segundo conjunto
    for (i = 0; i < set1->size; i++) {
        if (contains(set2, set1->elements[i])) {
            addElement(&result, set1->elements[i]);
        }
    }
 
    return result;
}
 
int main() {
    IntSet set1, set2, setUnion, setIntersect;
    int n1, n2, t, i;
 
    // Lê a quantidade de elementos do primeiro conjunto
    scanf("%d", &n1);
    initSet(&set1);
    for (i = 0; i < n1; i++) {
        int element;
        scanf("%d", &element);
        addElement(&set1, element);
    }
 
    // Lê a quantidade de elementos do segundo conjunto
    scanf("%d", &n2);
    initSet(&set2);
    for (i = 0; i < n2; i++) {
        int element;
        scanf("%d", &element);
        addElement(&set2, element);
    }
 
    // Lê a quantidade de testes
    scanf("%d", &t);
 
    // Realiza os testes
    for (i = 0; i < t; i++) {
        int operation;
        scanf("%d", &operation);
 
        if (operation == 1 || operation == 2) {
            int value;
            scanf("%d", &value);
 
            IntSet* set;
            if (operation == 1)
                set = &set1;
            else
                set = &set2;
 
            if (contains(set, value))
                printf("S\n");
            else
                printf("N\n");
        } else if (operation == 3) {
            setUnion = unionSets(&set1, &set2);
            printSet(&setUnion);
        } else if (operation == 4) {
            setIntersect = intersectSets(&set1, &set2);
            printSet(&setIntersect);
        }
    }
 
    return 0;
}