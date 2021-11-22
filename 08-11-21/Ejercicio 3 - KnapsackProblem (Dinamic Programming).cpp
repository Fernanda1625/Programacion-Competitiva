/*
Ejercicio 3.1: Dados los pesos y valores de n art�culos, coloque estos art�culos en una mochila de
capacidad W para obtener el valor total m�ximo en la mochila. En otras palabras, dadas dos matrices
de enteros val [0..n-1] y wt [0..n-1] que representan valores y pesos asociados con n elementos
respectivamente. Tambi�n dado un entero W que representa la capacidad de la mochila, averig�e el
subconjunto de valor m�ximo de val [] tal que la suma de los pesos de este subconjunto sea menor
o igual que W. No puede romper un art�culo, elija el art�culo completo o no. (Soluci�n con programaci�n din�mica)

Curso: Programaci�n Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n){
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for(i = 0; i <= n; i++){
        for(w = 0; w <= W; w++){
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main(){
	/*
	Caso de prueba 1 :
		Capacidad de la mochila = 50
		Peso = 10; Valor = 60
		Peso = 20; Valor = 100
		Peso = 30; Valor = 120
		Soluci�n: M�ximo valor posible = 220
	Caso de prueba 2 :
		Capacidad de la mochila = 10
		Peso = 1; Valor = 5
		Peso = 2; Valor = 3
		Peso = 4; Valor = 5
		Soluci�n: M�ximo valor posible = 11
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
