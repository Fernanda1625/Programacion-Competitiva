// Ejercicio 2: Cálculo rápido de sumas de elementos en un determinado rango
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

// funcion para obtener la suma de prefijos en un arreglo
void sumaPrefijos(int arr[], int n, int arrSumaPrefijos[]){
  arrSumaPrefijos[0] = 0;
  for (int i = 0; i < n; i++){
    arrSumaPrefijos[i+1] = arrSumaPrefijos[i] + arr[i];
  }
}

//main
int main(){
  // tie es un método que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Caso de prueba:
  // Entrada: {15, 5, 20, 8}
  // Salida:  {0, 15, 20, 40, 48}

  int arr[] = { 15, 5, 20, 8 };
  int n = sizeof(arr) / sizeof(arr[0]);
  int arrSumaPrefijos[n];

  sumaPrefijos(arr, n, arrSumaPrefijos);

  cout << "Entrada:\n";
  for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
  cout << "Salida:\n";
  for (int i = 0; i < n+1; i++){
    cout << arrSumaPrefijos[i] << " ";
  }

  return 0;

}
