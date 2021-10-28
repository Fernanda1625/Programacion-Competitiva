// Ejercicio 2: La primera línea contiene un número entero N que denota el número de operaciones para la teque.
// Cada una de las siguientes línea contiene una cadena S, que denota uno de los comandos de deque, seguido de
// un entero x.  (https://open.kattis.com/problems/teque)

// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> front, back;
    int N;
    cin >> N;

    while (N--) {
        string operacion;
        int x;
        cin >> operacion >> x;

        if (strcmp(operacion.c_str(), "get") == 0) {
            if (x < front.size()) {
                cout << front[x];
            } else {
                cout << back[x-front.size()];
            } cout << endl;
        } else if (strcmp(operacion.c_str(), "push_front") == 0) {
            front.push_front(x);
        } else if (strcmp(operacion.c_str(), "push_middle") == 0) {

            int mover;

            while (front.size() > back.size()) {
                mover = front.back();
                front.pop_back();
                back.push_front(mover);
            }

            while (back.size() > front.size()) {
                mover = back.front();
                back.pop_front();
                front.push_back(mover);
            }

            back.push_front(x);

        } else {
            back.push_back(x);
        }
    }
}
