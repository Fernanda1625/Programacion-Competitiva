// Ejercicio 1: Dado un arreglo de n enteros, encontrar la suma máxima de valores en un subarreglo contiguo no vacío.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

// funcion para hallar el maximo entre dos numeros
long int max(long int a, long int b) {
  return (a > b) ? a : b;
}

// funcion para hallar el maximo entre tres numeros
long int max(long int a, long int b, long int c) {
  return max(max(a, b), c);
}

// funcion para encontrar la maxima suma posible de un subarreglo en un arreglo arr[]
long int maxCrossingSum(long int arr[], long int l, long int m, long int h){
  // incluir elementos a la izquierda de la mitad
  long int sum = 0;
  long int left_sum = INT_MIN;
  for (int i = m; i >= l; i--) {
    sum = sum + arr[i];
    if (sum > left_sum)
      left_sum = sum;
  }

  // incluir elementos a la derecha de la mitad
  sum = 0;
  long int right_sum = INT_MIN;
  for (int i = m + 1; i <= h; i++) {
    sum = sum + arr[i];
    if (sum > right_sum)
      right_sum = sum;
  }

  // Devolver el maximo de la suma de los elementos
  // a la izquierda y a la derecha de la mitad
  return max(left_sum + right_sum, left_sum, right_sum);
}

// Devuelve la suma del subarreglo de suma máxima
long int maxSubArraySum(long int arr[], long int l, long int h){
  // Caso base: solo un elemento
  if (l == h)
    return arr[l];

  // encontrar el punto medio
  long int m = (l + h) / 2;

  //Devuelve un máximo de los siguientes tres casos posibles:
    // a) Suma máxima de subarreglos en la mitad izquierda
    // b) Suma máxima de subarreglos en la mitad derecha
    // c) Suma máxima del subarreglo tal que el subarreglo cruza el punto medio
  return max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h));
}

//main
int main(){
  long int n;
  cin >> n;
  long int arr[n];

  // ingresando elementos
  for (int i=0; i<n; i++)
    cin >> arr[i];

  long int max_sum = maxSubArraySum(arr, 0, n - 1);
  cout << max_sum;

  return 0;
}
