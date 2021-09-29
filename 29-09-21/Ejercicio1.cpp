// Ejercicio 1: Dado un arreglo de números y un número positivo k, encontrar la suma máxima del subarreglo de tamaño k
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

//función que permite hallar el máximo entre dos números
int max(int a, int b){
    return (a > b)? a : b;
}

//función para hallar la suma máxima del subarreglo de tamaño k
int sumkMax(int arr[], int n, int k){
    int start = 0;
    int sum = 0;
    int max_sum = 0;

    for (int i = 0; i < n ; i++){
      sum = sum + arr[i];

      if (i >= k-1){
        max_sum = max (sum, max_sum);
        sum = sum - arr[start];
        start++;
      }
    }
    return max_sum;
}

//main
int main(){
  // tie es un método que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Caso de prueba:
  // Entrada: {2,3,4,1,5} k=3
  // Salida: 10

  int arr[] = {2,3,4,1,5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;
  cout << sumkMax(arr, n, k);
  return 0;
}
