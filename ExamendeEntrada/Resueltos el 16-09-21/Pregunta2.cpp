// Pregunta 2: Escriba una función para eliminar elementos duplicados de una lista enlazadas no ordenada
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Estructura Nodo para la lista enlazada
struct Node {
    int data;
    struct Node* next;
};

// Estructura para crear un nuevo nodo
struct Node* newNode(int data){
    Node* temp = new Node;
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

// Funcion que elimina duplicados de una lista enlazada desordenada
void eliminarDuplicados(struct Node* start){
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    //Elegimos los elemenos uno a uno
    while (ptr1 != NULL && ptr1 -> next != NULL) {
        ptr2 = ptr1;

        // Se compara el elemento elegido con el resto de los elementos
        while (ptr2 -> next != NULL) {
            // Si está duplicado se elimina
            if (ptr1 -> data == ptr2 -> next -> data) {
                dup = ptr2 -> next;
                ptr2 -> next = ptr2 -> next -> next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1 -> next;
    }
}

// Funcion para imprimir los nodos de una lista enlazada
void imprimirLista(struct Node* node){
    while (node != NULL) {
        printf("%d ", node -> data);
        node = node -> next;
    }
}

//main
int main(){
    struct Node* start = newNode(15);
    start -> next = newNode(21);
    start -> next -> next = newNode(1);
    start -> next -> next -> next = newNode(20);
    start -> next -> next -> next -> next = newNode(15);
    start -> next -> next -> next -> next -> next = newNode(1);
    start -> next -> next -> next -> next -> next -> next = newNode(15);

    printf("Lista enlazada antes de eliminar los elementos duplicados:\n");
    imprimirLista(start);

    eliminarDuplicados(start);

    printf("\nLista enlazada después de eliminar los elementos duplicados: \n");
    imprimirLista(start);

    return 0;
}
