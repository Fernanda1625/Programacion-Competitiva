// Ejercicio 2: Dado un arreglo y un número x, encuentre la submatriz más pequeña con una suma mayor o igual que el valor dado.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

// función que devuelve la longitud del subarreglo más pequeño con una suma // mayor que o igual que S. Si no hay un subarreglo con la suma dada devuelve n+1
int smallestSubWithSum(int arr[], int n, int S){
    //Inicializamos la suma actual y la longitud mínima
    int sum_actual= 0;
    int lon_min = n+1;

    // inicializamos índices iniciales y finales
    int inicio = 0, fin = 0;
    while (fin < n) {
        // Siga agregando elementos del arreglo mientras
        // la suma actual sea menor que S
        while (sum_actual < S && fin < n)
            sum_actual += arr[fin++];

        // Si la suma actual es mayor o igual que S
        while (sum_actual >= S && inicio < n) {
            // actualizamos la longitud mínima si es necesario
            if (fin - inicio < lon_min)
                lon_min = fin - inicio;

            // eliminamos elementos iniciales
            sum_actual -= arr[inicio++];
        }
    }
    return lon_min;
}

// main
int main(){
  //tie es un método que garantiza el vaciado de std::cout antes de que std::cin acepte una entrada
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int arr[] = {2,4,2,5,1};
  int S = 7;
  int n = sizeof(arr) / sizeof(arr[0]);
  int res = smallestSubWithSum(arr, n, S);
  (res == n+1) ? cout << "No es posible\n" : cout << res << endl;

  return 0;
}
