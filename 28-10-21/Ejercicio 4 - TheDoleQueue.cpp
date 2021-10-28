// Ejercicio 4: Escriba un programa que lea sucesivamente (en ese orden) los tres números
// ( N , k y m ; k , m > 0, 0 < N <20) y determine el orden en el que los solicitantes son
// enviados a reentrenamiento. Cada conjunto de tres números estará en una línea separada y
//  el final de los datos se señalará con tres ceros (0 0 0).
// (https://www.beecrowd.com.br/judge/en/problems/view/1119)

// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, M, a, b;

   int v[1000];

    while(cin >> N >> K >> M && N) {
        int e = 0, f = N - 1;
        for(int i = 0; i < N; i++)
            v[i] = i + 1;

        int c = 0;
        while(c < N) {
            int i = K;
            while (i > 0){
                if(v[e] > 0) i--;
                if(i == 0) a = e;
                e = (e + 1) % N;
            }
            i = M;
            while(i > 0) {
                if(v[f] > 0) i--;
                if(i == 0) b = f;
                f = (f + N - 1) % N;
            }
            if(c > 0)
                cout <<",";
            if(a != b) {
                printf("%3d%3d", v[a], v[b]);
                c += 2;
            } else {
                printf("%3d", v[a]);
                c++;
            }
            v[a] = v[b] = 0;
        }
        cout << '\n';
  }
  return 0;
}
