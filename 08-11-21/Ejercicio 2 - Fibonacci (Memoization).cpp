// Ejercicio 2: Fibonacci Memoization
// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

int FibonacciMemoization(int n){
  static map<int, int> values;
  if (n==0 || n==1)
    return n;
  map<int,int>::iterator iter = values.find(n);
  if (iter == values.end()){
    return values[n] = FibonacciMemoization(n-1) + FibonacciMemoization(n-2);
  }
  else
  {
    return iter->second;
  }
}

int main (){
  int n;
  cout << "Ingrese el �ndice de Fibonacci que desea: ";
  cin >> n;
  cout << "El n�mero de Fibonacci es " <<  FibonacciMemoization(n);
  return 0;
}
