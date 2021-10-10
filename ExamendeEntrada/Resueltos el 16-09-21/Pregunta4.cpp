// Pregunta 4: Escriba una función que ordene una pila de forma ascendente. Las únicas funciones permitidas son push, pop, empty (consulta) y peek o top
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

//Funcion que retorna la pila ordenada
stack<int> ordenarPila(stack<int> &input){
  stack<int> tmpStack;
  while (!input.empty()){
    //sacar el primer elemento
    int tmp = input.top();
    input.pop();
    // mientras que la pila temporal no está vacía y la parte superior de //la pila es mayor que temp
    while (!tmpStack.empty() && tmpStack.top() > tmp){
      //sacar de la pila temporal y colocarlo en la pila de entrada
      input.push(tmpStack.top());
      tmpStack.pop();
    }
    // colocar en la pila temporal
    tmpStack.push(tmp);
  }
  return tmpStack;
}

// main
int main(){
  //Caso de prueba
  // Entrada: Arriba -> 13 - 102 - 9 - 43 - 8 - 25
  // Salida:  Arriba -> 102 - 43 - 25 - 13 - 9 - 8
  stack<int> pila;
  pila.push(25);
  pila.push(8);
  pila.push(43);
  pila.push(9);
  pila.push(102);
  pila.push(13);

  stack<int> tmpStack = ordenarPila(pila);
  cout << "Elementos ordenados:\n";

  while (!tmpStack.empty()){
    cout << tmpStack.top() << endl;
    tmpStack.pop();
  }

  return 0;
}
