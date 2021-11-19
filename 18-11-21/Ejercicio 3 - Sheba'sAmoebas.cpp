/*
Ejercicio 3: La primera l�nea de entrada contiene dos n�meros enteros m y n,(1 = m, n = 100).
A esto le siguen m l�neas, cada una de las cuales contiene n caracteres. Un "#" denota un p�xel
negro, un "." Denota un p�xel blanco. Por cada p�xel negro, exactamente dos de sus ocho vecinos
tambi�n son negros. Muestra un solo entero que representa el n�mero de bucles en la entrada.
(https://open.kattis.com/problems/amoebas)

Curso: Programaci�n Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    char map[m][n + 1];
    for (int i = 0; i < m; i++)
        cin >> map[i];
    int size = m * n;
    char visited[size];
    memset(visited, 0, (size_t)size);

    int counter = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (map[i][j] == '#' && !visited[i * n + j]){
                int x = i, y = j;
                int val = 0;
                while (!visited[val = x * n + y]){
                    visited[val] = 1;
                    int break_loops = 0;
                    for (int a = -1; a < 2; a++){
                        for (int b = -1; b < 2;  b++){
                            if (a != 0 || b != 0){
                                int _val = (x+a) * n + (y+b);
                                if (_val < 0 || _val >= size) continue;
                                if (map[x+a][y+b] == '#' && !visited[_val]){
                                    x += a;
                                    y += b;
                                    break_loops = 1;
                                }
                            }
                            if (break_loops) break;
                        }
                        if (break_loops) break;
                    }
                }
                counter++;
            }
        }
    }
    cout << "\n" << counter;

    return 0;
}
