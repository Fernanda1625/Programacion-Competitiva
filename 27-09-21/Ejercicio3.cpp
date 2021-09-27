// Ejercicio 3: Dada un arreglo de números enteros que ya está ordenado en orden ascendente, retorne un arreglo de los cuadrados de estos ordenados.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

//funcion que encuentra los cuadrados de un arreglo
void findSquares(int arr[], int n){
  for (int i = 0; i < n; i++)
    arr[i] = arr[i] * arr[i];

    //Ordenamos el arreglo de cuadrados
    sort(arr, arr + n);
}

//main
int main(){
  // tie es un método que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Caso de prueba 1:
  // Entrada: {-6, -3, -1, 2, 4, 5}
  // Salida: {1, 4, 6, 16, 25, 36}

  int arr[] = { -6, -3, -1, 2, 4, 5 };
  int n = sizeof(arr) / sizeof(arr[0]);
  findSquares(arr, n);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}

