// Ejercicio 3: Dado un arreglo de números enteros, calcule el índice de pivote de este arreglo.
// Nota: El índice pivote es el índice donde la suma de todos los números estrictamente a la izquierda del índice es igual a la suma de todos los números estrictamente a la derecha del índice.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

//funcion que calcula el indice pivot de un arreglo
int encontrarPivot(int arr[], int n){
  int sumaPrefijos[n];
  sumaPrefijos[0] = arr[0];
  for (int i = 1; i < n; i++)
    sumaPrefijos[i] = sumaPrefijos[i - 1] + arr[i];

  int sumaSufijos[n];
  sumaSufijos[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--)
    sumaSufijos[i] = sumaSufijos[i + 1] + arr[i];

  for (int i = 1; i < n - 1; i++)
    if (sumaPrefijos[i] == sumaSufijos[i])
      return i;

  return -1;
}

//main
int main(){
  // tie es un método que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Caso de prueba 1:
  // Entrada: {1,7,3,6,5,6}
  // Salida: 3
  cout << "Caso de prueba 1:\n";
  int arr1[] = {1, 7, 3, 6, 5, 6};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << encontrarPivot(arr1, n1);
  cout << "\n";

  // Caso de prueba 2:
  // Entrada: {1, 2, 3}
  // Salida: -1
  cout << "Caso de prueba 2:\n";
  int arr2[] = {1, 2 ,3};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << encontrarPivot(arr2, n2);

  return 0;
}
