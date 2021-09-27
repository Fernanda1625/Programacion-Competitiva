// Ejercicio 2: Dada un arreglo de números enteros que ya está ordenada en orden ascendente, busque tres números que sumen un número objetivo específico.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

//funcion que encuentra tres elementos de un arreglo que suman un target dado
void threeSum(int A[], int arr_size, int target){
  int l, r;

  for (int i = 0; i < arr_size - 2; i++) {

    l = i + 1; //índice del primer elemento en los elementos restantes
    r = arr_size - 1; //iindice del ultimo elemento
    while (l < r) {
      if (A[i] + A[l] + A[r] == target) {
        cout << "[" << i << ", " << l << ", " << r << "]";
        break;
      }
      else if (A[i] + A[l] + A[r] < target)
        l++;
      else // A[i] + A[l] + A[r] > sum
        r--;
    }
  }
}

//main
int main(){
  // tie es un método que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Caso de prueba 1:
  // Entrada: { 1,2,4,5,12}; target = 19
  // Salida: [1,3,4]
  int A[] = { 1,2,4,5,12};
  int target = 19;
  int arr_size = sizeof(A) / sizeof(A[0]);

  threeSum(A, arr_size, target);

  return 0;
}
