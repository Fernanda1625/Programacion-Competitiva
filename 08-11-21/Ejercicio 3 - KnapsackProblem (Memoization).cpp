/*
Ejercicio 3.1: Dados los pesos y valores de n artículos, coloque estos artículos en una mochila de
capacidad W para obtener el valor total máximo en la mochila. En otras palabras, dadas dos matrices
de enteros val [0..n-1] y wt [0..n-1] que representan valores y pesos asociados con n elementos
respectivamente. También dado un entero W que representa la capacidad de la mochila, averigüe el
subconjunto de valor máximo de val [] tal que la suma de los pesos de este subconjunto sea menor
o igual que W. No puede romper un artículo, elija el artículo completo o no. (Método de memorización)

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

int knapSackRec(int W, int wt[], int val[], int i, int** dp){
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W) {
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
        return dp[i][W];
    }
    else {
        dp[i][W] = max(val[i]  + knapSackRec(W - wt[i], wt, val, i - 1, dp), knapSackRec(W, wt, val, i - 1, dp));

        return dp[i][W];
    }
}

int knapSack(int W, int wt[], int val[], int n){
    int** dp;
    dp = new int*[n];

    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
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
