// Ejercicio 3: Dado un arreglo, y una ventana deslizante de tama�o k que se mueve desde el extremo izquierdo de la matriz hacia la derecha.
// Devuelve la ventana deslizante m�xima.
// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;


// funci�n para encontrar el m�ximo para todos y
// cada uno de los subarreglos contiguos de tama�o k.
void printKMax(int arr[], int n, int k){
  int j, max;

  for (int i = 0; i <= n - k; i++){
      max = arr[i];

      for (j = 1; j < k; j++){
        if (arr[i + j] > max)
          max = arr[i + j];
      }
      cout << max << " ";
  }
}

// main
int main(){
	//tie es un m�todo que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
  // Caso de prueba:
  // Entrada: {1,3,-1,-3,5,3,6,7} k=3
  // Salida: {3,3,5,5,6,7}

  int arr[] = {1,3,-1,-3,5,3,6,7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;
  printKMax(arr, n, k);

  return 0;
}
