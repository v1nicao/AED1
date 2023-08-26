#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Definição da estrutura do nó da lista
typedef struct Node {
    char name[21];
    int data;
    struct Node* next;
} Node;
 
// Função para criar um novo nó
Node* createNode(char name[], int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
// Função para inserir um nó no início da lista
Node* insertAtBeginning(Node* head, char name[], int data) {
    Node* newNode = createNode(name, data);
    newNode->next = head;
    return newNode;
}
 
// Função para imprimir a lista
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s -> %d\n", current->name, current->data);
        current = current->next;
    }
}
// Função auxiliar para inserir um nó na lista ordenada
Node* insertSorted(Node* head, Node* newNode) {
    if (head == NULL || strcmp(head->name, newNode->name) > 0) {
        newNode->next = head;
        return newNode;
    }
 
    Node* current = head;
    while (current->next != NULL && strcmp(current->next->name, newNode->name) < 0) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
 
    return head;
}
 
// Função para ordenar a lista por inserção
Node* insertionSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; // A lista está vazia ou já está ordenada
    }
 
    Node* sorted = NULL;
    Node* current = head;
 
    while (current != NULL) {
        Node* next = current->next;
        sorted = insertSorted(sorted, current);
        current = next;
    }
 
    return sorted;
}
 
 
 
int main() {
    Node* head = NULL;
    int qtd_aluno, i, nt;
 
    scanf("%d", &qtd_aluno);
    for (i = 0; i < qtd_aluno; i++) {
        char name_temp[21];
        scanf("%s", name_temp);
        scanf("%d", &nt);
        head = insertAtBeginning(head, name_temp, nt);
    }
 
    // Ordenar a lista por nome
    head = insertionSort(head);
 
    // Imprimir a lista ordenada
    printList(head);
 
    // Liberar a memória alocada para os nós
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
 
    return 0;
}