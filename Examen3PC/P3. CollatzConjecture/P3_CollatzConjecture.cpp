// Problema 3: CollatzConjecture
// URL: https://open.kattis.com/problems/collatz
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

vector<long long> getpath(long long n) {
    vector<long long> res;

    while(n != 1) {
        res.push_back(n);

        if(n%2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            n++;
        }
    }

    res.push_back(1);
    return res;
}

int main() {

    long long n, m;
    while(cin >> n && cin >> m) {
        if(n == 0 && m == 0) {
            break;
        }

        vector<long long> p1 = getpath(n);
        vector<long long> p2 = getpath(m);

        long long lastsimilar = 1;
        while(p1.size() > 0 && p2.size() > 0 && p1.back() == p2.back()) {
            lastsimilar = p1.back();
            p1.pop_back();
            p2.pop_back();
        }

        cout << n << " needs " << p1.size() << " steps, ";
        cout << m << " needs " << p2.size() << " steps, ";
        cout << "they meet at " << lastsimilar << endl;
    }

    return 0;
}
