// Ejercicio 2: Dado un arreglo de n�meros enteros y un n�mero entero k, devuelve el n�mero total de subarreglos continuas cuya suma es igual a k
// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

// Funci�n para encontrar el n�mero de subarreglos
// con suma exactamente igual a k.
int findSubarraySum(int arr[], int n, int k){
  // Mapa STL para almacenar el n�mero de subarreglos
  // a partir del �ndice cero que tiene un valor
  // particular de suma.
  unordered_map<int, int> prevSum;

  int contador = 0;

  // Suma de elementos hasta ahora
  int sumaActual = 0;

  for (int i = 0; i < n; i++) {
    // Agregue el elemento actual a la suma hasta ahora.
    sumaActual += arr[i];
    // Si sumaActual es igual a la suma deseada,
    // luego se encuentra un nuevo subarreglo. Entonces
    // aumenta el recuento de subarreglos
    if (sumaActual == k)
      contador++;

    // sumaActual excede la suma dada por sumaActual - k
    // Encuentra el n�mero de submatrices que tienen
    // esta suma y excluye esos subarreglos
    // de sumaActual aumentando el recuento en
    // la misma cantidad.
    if (prevSum.find(sumaActual - k) != prevSum.end())
      contador += (prevSum[sumaActual - k]);

    // Agregue el valor de sumaActual para contar
    // diferentes valores de suma.
    prevSum[sumaActual]++;
  }

  return contador;
}

int main(){
  // tie es un m�todo que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //Caso de prueba 1:
  // Entrada: {1,1,1}, k=2
  // Salida: 2
  int arr1[] = { 1,1,1};
  int k1 = 2;
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << "Caso de prueba 1:\n";
  cout << findSubarraySum(arr1, n1, k1);
  cout << "\n";

  //Caso de prueba 2:
  // Entrada: {1,2,3}, k=3
  // Salida: 2
  int arr2[] = { 1,2,3};
  int k2 = 3;
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << "Caso de prueba 2:\n";
  cout << findSubarraySum(arr2, n2, k2);
  return 0;
}
