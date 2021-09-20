// Ejercicio 2: Encontrar bucles en un flujo de datos
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <iostream>
#include <vector>
using namespace std;

//función para encontrar un bucle en un arreglo dado
void encontrarBucle(vector<int> v){
  int tamanio = size(v);
  for(int i = 0; i < tamanio - 1; i++ ){
    int temporal = v[i];
    int contador = 0;
    for( int j = i; j < tamanio - 1; j++ ){
      if( temporal == v[j] )
        contador++;
    }
    if( contador > 2 ){
      cout << v[i] << " ";
    }
  }
}

//main
int main(){
  int a; // para ingresar los elementos
  vector <int> arreglo;
  cout << "Ingrese los elementos y 0 para dejar de ingresar\n";
  while(true){
    cin >> a;
    if (a == 0) //0 para dejar de ingresar elementos al arreglo
      break;
    else
      arreglo.push_back(a);
  }
  encontrarBucle(arreglo);

  return 0;
}
