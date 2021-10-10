// Pregunta 5: Escriba una función que verifique si un árbol es balanceado. Para el propósito de esta pregunta, un árbol
// balanceado es aquel árbol en el que la diferencia de alturas entre cada subárbol no es mayor a 1.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

//Nodo de un árbol
class node {
public:
    int data;
    node* left;
    node* right;
};

// Devuelve la altura de un árbol
int height(node* node);

// Devuelve verdadero si es balanceado
bool esBalanceado(node* root){
  int lh; //para la altura del subarbol izquierdo
  int rh; // para la altura del subarbol derecho

  // si el arbol está vacío retorna verdadero
  if (root == NULL)
    return 1;

  //Obtenga la altura de los subárboles izquierdo y derecho
  lh = height(root -> left);
  rh = height(root -> right);

  if (abs(lh - rh) <= 1 && esBalanceado(root->left) && esBalanceado(root->right))
    return 1;

  //Si llegamos aquí, el árbol no está equilibrado en altura
  return 0;
}

// Funcion que retorna el máximo de dos enteros
int max(int a, int b){
    return (a >= b) ? a : b;
}

// La función Calcula la altura de un árbol. La altura es el número de nodos a lo largo de la ruta más larga desde el nodo raíz hasta el nodo hoja más lejano.
int height(node* node){
  // arbol vacio
  if (node == NULL)
    return 0;
  // Si el árbol no está vacío, entonces altura = 1 + máximo de altura izquierda y altura derecha
  return 1 + max(height(node->left), height(node->right));
}

// Función auxiliar que asigna un nuevo nodo con los datos dados y punteros NULL izquierdo y derecho.
node* newNode(int data){
  node* Node = new node();
  Node -> data = data;
  Node -> left = NULL;
  Node -> right = NULL;

  return (Node);
}

// main
int main(){
  //Caso de prueba:
  //Entrada:
  /*
               1
             /   \
            2     3
          /  \   /
          4  5  6
        /
      7
  */
  //Salida: Si es balanceado
  node* raiz = newNode(1);
  raiz -> left = newNode(2);
  raiz -> right = newNode(3);
  raiz -> left -> left = newNode(4);
  raiz -> left -> right = newNode(5);
  raiz -> right -> left = newNode(6);
  raiz -> left -> left -> left = newNode(7);

  if (esBalanceado(raiz))
    cout << "Arbol SI es balanceado";
  else
    cout << "Arbol NO es balanceado";
  return 0;
}
