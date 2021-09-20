// Ejercicio 1: INTEST - Dados cierta cantidad de números, hallar los que son divisibles por k
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

//funcion que calcula los numeros en un arreglo que son divisibles por k
void esDividible (int arr[], int n, int k){
  int contador = 0;
  for(int i = 0; i < n; ++i){
    if (arr[i] % k == 0){
      contador = contador + 1;
    }
  }
  cout << contador << "\n";
}

//main
int main() {
  // tie es un método que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, numero;

  //Caso de prueba:
  // n = 7 -> 7 numeros en el arreglo
  // k = 3 -> cuantos son divisibles por 3
  // Entrada: {1, 51, 966369, 7, 9, 999996, 11}
  // Salida: 4 -> 4 números son diviibles por 3

  n = 7;
  k = 3;
  int arr[7] = {1, 51, 966369, 7, 9, 999996, 11};

  esDividible(arr,n,k);

  return 0;
}
