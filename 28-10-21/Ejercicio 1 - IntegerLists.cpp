// Ejercicio 1: Dado un programa BAPC y su entrada, devuelve su salida o "error" en caso de que 'D'
// se aplique a una lista vac�a. Las listas se representan con el car�cter '[' seguido de una lista
// de n�meros enteros separados por comas seguidos del car�cter ']'. Observe que las listas de entrada
// y salida pueden ser bastante largas. (https://open.kattis.com/problems/integerlists)

// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int main() {
    int casos;
    cin >> casos;
    while(casos--) {
        string comando;
        cin >> comando;

        int n;
        cin >> n;

        deque<int> d;
        cin.ignore();
        for(int i = 0; i < n; i++) {
            cin.ignore();
            int t;
            cin >> t;
            d.push_back(t);
        }
        cin.ignore();
        if(n == 0) {
            cin.ignore();
        }

        bool beg = true;
        bool printed = false;
        for(auto i : comando) {
            if(i == 'R') {
                beg = !beg;
            }
            if(i == 'D') {
                if(d.size() == 0) {
                    printed = true;
                    cout << "error" << endl;
                    break;
                }
                else {
                    if(beg) {
                        d.pop_front();
                    }
                    else {
                        d.pop_back();
                    }
                }
            }
        }

        if(!printed) {
            cout << "[";
            while(!d.empty()) {
                if(beg) {
                    cout << d.front();
                    d.pop_front();
                }
                else {
                    cout << d.back();
                    d.pop_back();
                }

                if(d.size() != 0) {
                    cout << ",";
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}
