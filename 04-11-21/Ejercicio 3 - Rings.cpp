// Ejercicio 3: Genere una cuadr�cula con los n�meros de timbre. Si el n�mero de anillos es menor a 10,
// use dos caracteres para cada cuadrado de la cuadr�cula; de lo contrario, utilice tres caracteres para
// cada cuadro de la cuadr�cula. Justifique a la derecha todos los n�meros de anillo en los cuadrados de
// la cuadr�cula y use "." Para completar los caracteres restantes. Si una fila o columna no contiene un
// n�mero de timbre, de todos modos deber�a aparecer, rellena completamente con ".".
// (https://open.kattis.com/problems/rings2)

// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

int main() {
    int height, width;
    cin >> height >> width;

    char tree[150][150];
    for(int i = 0; i < 103; i++) {
        for(int j = 0; j < 103; j++) {
            tree[i][j] = '.';
        }
    }

    for(int i = 1; i <= height; i++) {
        for(int j = 1; j <= width; j++) {
            cin >> tree[i][j];
        }
    }

    bool swapMade = true;
    int k = 0;
    while(swapMade) {
        k++;
        swapMade = false;
        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= width; j++){
                if(tree[i][j] == 'T' && (tree[i-1][j] == '.' || tree[i+1][j] == '.' || tree[i][j-1] == '.' || tree[i][j+1] == '.')) {
                    tree[i][j] = k + '0';
                    swapMade = true;
                }

                if(tree[i][j] == 'T' && (tree[i-1][j] == k + '0' - 1 || tree[i+1][j] == k + '0' - 1 || tree[i][j-1] == k + '0' - 1 || tree[i][j+1] == k + '0' - 1)) {
                    tree[i][j] = k + '0';
                    swapMade = true;
                }
            }
        }
    }

    for(int i = 1; i <= height; i++) {
        for(int j = 1; j <= width; j++) {
            if(k < 10) {
                if(tree[i][j] == '.') {
                    cout << "..";
                }
                else {
                    cout << '.' << int(tree[i][j] - '0');
                }
            }
            else {
                if(tree[i][j] == '.') {
                    cout << "...";
                }
                else {
                    if(int(tree[i][j] - '0') >= 10)
                        cout << '.' << int(tree[i][j] - '0');
                    else
                        cout << ".." << int(tree[i][j] - '0');
                }

            }
        }
        cout << '\n';
    }
}
