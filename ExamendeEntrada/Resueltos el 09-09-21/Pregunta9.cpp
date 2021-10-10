// Pregunta 9: Escriba una función que genere el numero n de la secuencia Fibonacci
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <iostream>
using namespace std;

unsigned long int Fibonacci(int N) {
    unsigned long int Fib[N+1]; //array para los valores
    Fib[0] = 1;
    Fib[1] = 1;
    // Bucle de 2 a N
    for( int i = 2; i <= N; i++) {
        Fib[i] = Fib[i-1] + Fib[i-2]; //Igual a la suma de los 2 previos
    }
    return Fib[N];
}

int main(){
	int n;
  cout << "Ingrese que número de la serie de Fibonacci desea: ";
  cout << endl;
  cin >> n;
	unsigned long int result;
	result = Fibonacci(n);
  cout << "El número " << n << " de la serie de Fibonacci es: " << result;
	return 0;
}
