// Ejercicio 3: Teniendo en cuenta la entrada de valores enteros no negativos, ordene estos números de acuerdo con los siguientes criterios: Primero el par en orden ascendente seguido por el impar en orden descendente.(https://www.urionlinejudge.com.br/judge/en/problems/view/1259)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

template<typename Type> void printPriorityQueue(Type& q){
  while(!q.empty()){
    cout << q.top() << endl;
    q.pop();
  }
}

int main(){
  int N, numero;
  priority_queue<int, vector<int>, greater<int> > queueEven;
  priority_queue<int> queueOdd;

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> numero;
    if(numero % 2 == 0)
      queueEven.push(numero);
    else
      queueOdd.push(numero);
  }

  printPriorityQueue(queueEven);
  printPriorityQueue(queueOdd);
}
