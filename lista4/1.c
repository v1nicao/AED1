#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define CHAVE_INVALIDA 0
 
typedef struct {
    unsigned int vezes;
    char info[10];
    char name[21];
} Celula;
 
typedef struct {
    Celula celulas[100];
    unsigned int size;
} ListaLinear;
 
int createListEmpty(ListaLinear* lista) {
    lista->size = 0;
    return 1;
}
 
void createList(ListaLinear* lista, Celula celula) {
    lista->celulas[0] = celula;
    lista->size = 1;
}
 
int sizeList(ListaLinear lista) {
    if (lista.size >= 0) return lista.size;
    else return -1;
}
 
int insInicio(ListaLinear* list, Celula celula) {
    unsigned int i;
 
    if (list->size == 100) return 0;
    else {
        for (i = list->size; i > 0; i--) {
            list->celulas[i] = list->celulas[i - 1];
        }
        list->celulas[0] = celula;
        list->size++;
        return 1;
    }
}
 
int insFinal(ListaLinear* lista, Celula celula) {
    if (lista->size == 100) return 0;
    else {
        lista->celulas[lista->size] = celula;
        lista->size++;
        return 1;
    }
}
 
void mostrarCelula(Celula celula) {
    printf("%s", celula.name);
    printf(" - ");
    printf("%s\n", celula.info);
    //printf("%u\n", celula.vezes);
}
 
void mostrarLista(ListaLinear lista) {
    unsigned int i;
    unsigned int maxLigacoes = 0;
    int indexMaxLigacoes = -1;
 
    if (lista.size == 0) {
        printf("Atenção: A lista está vazia.\n");
    }
    else {
        for (i = 0; i < lista.size; i++) {
            mostrarCelula(lista.celulas[i]);
 
            if (lista.celulas[i].vezes > maxLigacoes) {
                maxLigacoes = lista.celulas[i].vezes;
                indexMaxLigacoes = i;
            }
        }
        /*
        if (indexMaxLigacoes != -1) {
            printf("\nContato com o maior número de ligações:\n");
            mostrarCelula(lista.celulas[indexMaxLigacoes]);
        }
        */
    }
}
void removerElemento(ListaLinear* lista, const char* nome) {
    int posicao = -1;
    unsigned int i;
 
    // Encontrar a posição do elemento com o nome fornecido
    for (i = 0; i < lista->size; i++) {
        if (strcmp(lista->celulas[i].name, nome) == 0) {
            posicao = i;
            break;
        }
    }
 
    if (posicao == -1) {
        printf("Contato não encontrado.\n");
        return;
    }
 
    // Remover o elemento da lista
    for (i = posicao; i < lista->size - 1; i++) {
        lista->celulas[i] = lista->celulas[i + 1];
    }
 
    lista->size--;
}
 
 
 
int main(int argc, char** argv) {
    unsigned int i;
    char operation;
    int intResultado;
    ListaLinear lista;
    Celula celula;
    char temp1[21], temp2[21];
 
    intResultado = createListEmpty(&lista);
    if (intResultado == -1) exit(1);
    while (lista.size < 2) {
        strcpy(celula.name, "Hermanoteu");
        strcpy(celula.info, "4523-2248");
        celula.vezes = 300;
        insInicio(&lista, celula);
        strcpy(celula.name, "Ooloneia");
        strcpy(celula.info, "4523-4887");
        celula.vezes = 299;
        insInicio(&lista, celula);
    }
    //insInicio(&lista,celula);
 
    scanf(" %c", &operation);
    while (operation != 'F') {
        if (operation == 'I') {
            scanf("%s", celula.name);
            scanf("%s", celula.info);
            scanf("%u", &celula.vezes);
            insFinal(&lista, celula);
        }
        if (operation == 'S') {
            mostrarLista(lista);
            //loadContacts(&lista);
            //printf("Aperte 0 para sair\n");
        }
        if (operation == 'R') {
            char nome_temp[21];
            scanf("%s", nome_temp);
            removerElemento(&lista, nome_temp);
        }
 
        if (operation == 'L') {
            char name_temp[21];
            scanf("%s", name_temp);
            int found = 0;
            for (i = 0; i < lista.size; i++) {
                if (strcmp(name_temp, lista.celulas[i].name) == 0) {
                    lista.celulas[i].vezes++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Contato não encontrado.\n");
            }
        }
 
        scanf(" %c", &operation);
    }
    mostrarLista(lista);
 
    //saveContacts(lista);
 
    //printf("PROGRAMA FINALIZADO\n");
    return 0;
}