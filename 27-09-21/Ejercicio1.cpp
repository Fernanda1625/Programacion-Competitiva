// Ejercicio 1: Dada un arreglo de números enteros que ya está ordenada en orden ascendente, busque dos números que sumen un número objetivo específico.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

// //funcion que encuentra dos elementos de un arreglo que suman un target dado
void twoSum(int A[], int arr_size, int target){
  int l, r;
  sort(A, A + arr_size);
  
  l = 0;
  r = arr_size - 1;
  
  while (l < r) {
    if (A[l] + A[r] == target){
      cout << "[" << l << "," << r << "]";
      break;
    }
    else if (A[l] + A[r] < target)
      l++;
    else // A[i] + A[j] > sum
      r--;
  }
}

// main
int main(){
  // tie es un método que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Caso de prueba 1:
  // Entrada: { 1, 2, 7, 9, 11, 15 }; target = 11
  // Salida: [1,3]

  int A[] = { 1, 2, 7, 9, 11, 15 };
  int target = 11;
  int arr_size = sizeof(A) / sizeof(A[0]);

  twoSum(A,arr_size,target);

  return 0;
}
