// Ejercicio 3: Estás sentado en una fila de sillas, esperando una entrevista. Al elegir el próximo entrevistado, el entrevistador siempre elegirá entre ya sea en el lado izquierdo o en el lado derecho de la fila de sillas. Además, el entrevistador sabe exactamente cuánto tiempo le llevará cada entrevista y, siendo vago, siempre elegirá el bando con el menor tiempo de entrevista. (Puede asumir que todos los tiempos son distintos). Se le indica con un tiempo de entrevista de -1, lo que significa que el entrevistador siempre lo elegirá por encima de la persona del lado opuesto. ¿Cuánto tiempo pasará antes de que el entrevistador llegue a usted?
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

void interviewWait(vector<int> &arr){
    deque<int> d;

    for(auto elemento:arr){
        d.push_back(elemento);
    }

    int resultado = 0;

    while (d.front() != -1 && d.back() != -1){
        if (d.front() < d.back()){
          resultado += d.front();
          d.pop_front();
        } else {
            resultado += d.back();
            d.pop_back();
        }
    }
    cout << resultado;
}

int main(){

  vector<int> arreglo = {4,-1,5,2,3};

  interviewWait(arreglo);

  return 0;
}
