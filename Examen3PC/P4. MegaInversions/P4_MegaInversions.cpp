// Problema 4: Mega Inversions
// URL: https://open.kattis.com/problems/megainversions
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

void inc(vector<long long>& f, long long i, long long d) {
    for(; i < f.size(); i |= i+1) {
        f[i] += d;
    }
}

long long sum(vector<long long>& f, long long i) {
    long long total = 0;
    for(; i > 0; i &= i-1) {
        total += f[i-1];
    }
    return total;
}

long long count(vector<long long>& f, long long i) {
    return sum(f, f.size()) - sum(f, i);
}

int main() {
    long long n;
    cin >> n;

    vector<long long> f1(n+1, 0);
    vector<long long> f2(n+1, 0);
    vector<long long> f3(n+1, 0);

    for(long long i = 0; i < n; i++) {
        int num;
        cin >> num;
        long long s1 = count(f1, num+1);
        long long s2 = count(f2, num+1);

        inc(f1, num, 1);
        inc(f2, num, s1);
        inc(f3, num, s2);
    }

    cout << count(f3, 0) << endl;
}
