// Ejercicio 1: Dado un arreglo de n�meros y un n�mero positivo k, encontrar la suma m�xima del subarreglo de tama�o k
// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

//funci�n que permite hallar el m�ximo entre dos n�meros
int max(int a, int b){
    return (a > b)? a : b;
}

//funci�n para hallar la suma m�xima del subarreglo de tama�o k
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
  // tie es un m�todo que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
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
