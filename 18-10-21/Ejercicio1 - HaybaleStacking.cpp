// Ejercicio 1: Comienza con N (1 <= N <= 1,000,000, N impares) pilas vacías, Bessie es dada una secuencia de K instrucciones (1 <= K <= 25.000), cada una de las
// forma "A B", lo que significa que Bessie debe agregar una nueva bala de heno a la parte superior de cada pila en el rango A..B. Calcule la altura mediana después.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000 // maximo definido en el problema

int Stack[MAX_N+10];
int N,K;

// función para comparar
int compare(const void *a, const void *b){
	return (*(int*)a-*(int*)b);
}

// funcion principal
int main(){
  /*
    Caso de prueba:
    Entrada:    7 4
                5 5
                2 4
                4 6
                3 5
    Salida: 1
  */

	int i,s,e;
  	cin >> N >> K;
	for(i = 0; i < K; i++){
		cin >> s >> e;
		++Stack[s-1];
		--Stack[e];
	}

	for(i = 1; i < N; i++){
		Stack[i] += Stack[i-1];
	}

	qsort(Stack,N,sizeof(int),compare);

  	cout << "\n";
	cout << Stack[N/2] << "\n";

	return 0;
}
