// Ejercicio 1: Producto m�ximo de dos n�meros en una sequencia
// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

//funci�n que retorna la multiplicaci�n entre los dos n�meros mayores del arreglo
int maximaMultiplicacion(vector<int> v){
  sort(v.begin(), v.end(), greater<int>()); //se ordenan de mayor a menor
  const int &primero = v.at( 0 ); // el primer elemento es el mayor
  const int &segundo = v.at( 1 ); // el segundo elemento es el segundo mayor

  return primero*segundo;
}

//main
int main() {
  int n;
  cin >> n;
  vector<int> arreglo(n);
  for ( auto& elem : arreglo )
     cin >> elem;

  cout << maximaMultiplicacion(arreglo);

  return 0;
}
