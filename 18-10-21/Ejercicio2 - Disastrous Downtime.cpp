// Ejercicio 2: Dados los tiempos de inicio de N (1=N=100,000) solicitudes, cada una de las cuales dura 1000 milisegundos
// y K (1=K=100.000), el número máximo de solicitudes que un servidor puede manejar simultáneamente, calcule el mínimo
// número de servidores necesarios para procesar todas las solicitudes.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int main() {
	/*
		Caso de prueba 1:
		Entrada: 	2 1
					0
					1000
		Salida:     1

		Caso de prueba 2:
		Entrada:    3 2
					1000
					1010
					1999
		Salida: 2
		
		Caso de prueba 3:
		Entrada:    7 2
                    1000
					1010
					1500
					1999
					2000
					2010
					2999
		Salida: 2
		
		
	*/

	int n, k;
	map<int, int> event;
	int max_event = 0;
	int counter = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		event[num]++;
		event[num + 1000]--;
	}

	for (auto i : event) {
		counter += i.second;
		max_event = max(max_event, counter);
	}

	cout << (int)ceil((double) max_event / k) << "\n";

	return 0;
}
