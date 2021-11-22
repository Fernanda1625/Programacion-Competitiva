// Ejercicio 1: Fibonacci Recursivo
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

int Fibonacci(int n){
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(){
	while (true){
		int t;
		bool upto;
		do{
			cout << "Solo mostrar el índice solicitado? \n(0 = Yes) 0r (1 = No)\n";
			cin >> t;
		} while (t != 1 && t != 0);
		upto = t;

		int n;
		cout << "Dar el índice solicitado en la secuencia de Fibonacci\n";
		cin >> n;

		if (upto){
			for (int i = 0; i < n; i++)
				cout << Fibonacci(i) << "\n";
		}
		else
		{
			cout << Fibonacci(n) << "\n";
		}
	}

	return 1;
}
