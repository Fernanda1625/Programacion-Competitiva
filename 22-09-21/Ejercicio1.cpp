// Ejercicio 1: Dados un número entero de arreglos y un entero k, devuelve el número de subarreglos no vacíos que tienen una suma divisible por k.
// Un subarreglo es una parte contigua de un arreglo.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

//funcion que calcula la cantidad de subarreglos que tiene una suma divisible por k
int subArrEsDivisible(int arr[], int n, int k){
  int mod[k];
  memset(mod, 0, sizeof(mod));
  // Recorre el arreglo original y calcula la suma acumulada
  // Toma el resto de esta suma total y aumenta en uno
  // para el resto del arreglo mod[]
  int suma = 0;
  for (int i = 0; i < n; i++) {
    suma += arr[i];
    // como la suma puede ser negativa, tomamos el módulo dos veces
    mod[((suma % k) + k) % k]++;
  }

  int result = 0;
  for (int i = 0; i < k; i++){
    // Si hay más de un subarreglo de prefijo con un valor de mod particular
    if (mod[i] > 1)
      result += (mod[i] * (mod[i] - 1)) / 2;
  }
  // agregue los elementos que son divisibles por k ellos mismos
  // es decir, los elementos cuya suma = 0
  result += mod[0];

  return result;
}

// main
int main(){
  // tie es un método que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Caso de prueba 1:
  // Entrada: {4, 5, 0, -2, -3, 1], k = 5
  // Salida: 7
  cout << "Caso de prueba 1:\n";
  int arr1[] = { 4, 5, 0, -2, -3, 1 };
  int k1 = 5;
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << subArrEsDivisible(arr1, n1, k1) << endl;
  cout << "\n";

  // Caso de prueba 2:
  // Entrada: {5} , k = 9
  // Salida: 0
  cout << "Caso de prueba 2:\n";
  int arr2[] = {5};
  int k2 = 9;
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << subArrEsDivisible(arr2, n2, k2) << endl;

  return 0;
}
