/*
Ejercicio 3.1: Dados los pesos y valores de n artículos, coloque estos artículos en una mochila de
capacidad W para obtener el valor total máximo en la mochila. En otras palabras, dadas dos matrices
de enteros val [0..n-1] y wt [0..n-1] que representan valores y pesos asociados con n elementos
respectivamente. También dado un entero W que representa la capacidad de la mochila, averigüe el
subconjunto de valor máximo de val [] tal que la suma de los pesos de este subconjunto sea menor
o igual que W. No puede romper un artículo, elija el artículo completo o no. (Solución recursiva)

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }


int knapSack(int W, int wt[], int val[], int n){

    // Caso base
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
        return max( val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main(){
	/*
	Caso de prueba 1 :
		Capacidad de la mochila = 50
		Peso = 10; Valor = 60
		Peso = 20; Valor = 100
		Peso = 30; Valor = 120
		Solución: Máximo valor posible = 220
	Caso de prueba 2 :
		Capacidad de la mochila = 10
		Peso = 1; Valor = 5
		Peso = 2; Valor = 3
		Peso = 4; Valor = 5
		Solución: Máximo valor posible = 11
	*/
    int val1[] = {60, 100, 120};
    int wt1[] = {10, 20, 30};
    int W1 = 50;
    int n1 = sizeof(val1) / sizeof(val1[0]);
    
    int val2[] = {1, 2, 4, 2, 5};
    int wt2[] = {5, 3, 5, 3, 2};
    int W2 = 10;
    int n2 = sizeof(val2) / sizeof(val2[0]);
    cout << "Caso de prueba 1: " << knapSack(W1, wt1, val1, n1) << endl;
    cout << "Caso de prueba 2: " << knapSack(W2, wt2, val2, n2);
    
    return 0;
}
