// Problema 15: Kindergarten Excursion
// URL: https://open.kattis.com/problems/excursion
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> count(3, 0);

    string s;
    cin >> s;

    for(auto& i : s) {
        count[i-'0']++;
    }

    long long swaps = 0;

    for(auto& i : s) {
        if(i == '0') {
            count[0]--;
        }
        else {
            swaps += count[0];
        }
    }

    for(auto& i : s) {
        if(i == '1') {
            count[1]--;
        }
        if(i == '2') {
            swaps += count[1];
        }
    }

    cout << swaps << endl;
}
