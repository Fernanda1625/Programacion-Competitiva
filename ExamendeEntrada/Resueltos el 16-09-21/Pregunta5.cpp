// Pregunta 5: Escriba una funci�n que verifique si un �rbol es balanceado. Para el prop�sito de esta pregunta, un �rbol
// balanceado es aquel �rbol en el que la diferencia de alturas entre cada sub�rbol no es mayor a 1.
// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

//Nodo de un �rbol
class node {
public:
    int data;
    node* left;
    node* right;
};

// Devuelve la altura de un �rbol
int height(node* node);

// Devuelve verdadero si es balanceado
bool esBalanceado(node* root){
  int lh; //para la altura del subarbol izquierdo
  int rh; // para la altura del subarbol derecho

  // si el arbol est� vac�o retorna verdadero
  if (root == NULL)
    return 1;

  //Obtenga la altura de los sub�rboles izquierdo y derecho
  lh = height(root -> left);
  rh = height(root -> right);

  if (abs(lh - rh) <= 1 && esBalanceado(root->left) && esBalanceado(root->right))
    return 1;

  //Si llegamos aqu�, el �rbol no est� equilibrado en altura
  return 0;
}

// Funcion que retorna el m�ximo de dos enteros
int max(int a, int b){
    return (a >= b) ? a : b;
}

// La funci�n Calcula la altura de un �rbol. La altura es el n�mero de nodos a lo largo de la ruta m�s larga desde el nodo ra�z hasta el nodo hoja m�s lejano.
int height(node* node){
  // arbol vacio
  if (node == NULL)
    return 0;
  // Si el �rbol no est� vac�o, entonces altura = 1 + m�ximo de altura izquierda y altura derecha
  return 1 + max(height(node->left), height(node->right));
}

// Funci�n auxiliar que asigna un nuevo nodo con los datos dados y punteros NULL izquierdo y derecho.
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
