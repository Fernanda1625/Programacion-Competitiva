// Pregunta 9: Como ya sabrás, Ada the Ladybug es una granjera. Tiene un hermoso campo cuadrado (de tamaño NxN) en el que cultiva muchas plantas hermosas. Cada planta tiene cierta altura. Quiere saber, para cada subcuadrado (de algún tamaño definido KxK) cuál es la planta de tamaño mínimo en ella. Como no quiere demasiada información, solo te pide la suma de todas esas plantas más bajas.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

const int MAX = 5005;
const int MODULO = 1000000007;

long long multiply(long long a, long long b, long long modulo) {
    long long q = (long double)a * (long double)b / (long double)modulo;
    long long result = a * b - q * modulo;
    return (result + (modulo << 2)) % modulo;
}

int N, K;
long long data[MAX][MAX];
long long minimumInRow[MAX][MAX];

void add(deque<long long> &dq, long long value) {
  while (!dq.empty() && dq.back() > value) dq.pop_back();
  dq.push_back(value);
}

void remove(deque<long long> &dq, long long value) {
  if (!dq.empty() && dq.front() == value) dq.pop_front();
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i ++) {
        long long x0, a, b, c;
        cin >> x0 >> a >> b >> c;
        data[i][1] = x0;
        a %= c;
        b %= c;
        for (int j = 2; j <= N; j ++) {
            data[i][j] = (multiply(data[i][j - 1], a, c) + b) % c;
        }
    }
    for (int i = 1; i <= N; i ++) {
        deque<long long> activeMinimums;
        for (int j = 1; j <= N; j ++) {
            if (j > K) remove(activeMinimums, data[i][j - K]);
            add(activeMinimums, data[i][j]);
            minimumInRow[i][j] = activeMinimums.front();
        }
    }
    long long result = 0;
    for (int j = K; j <= N; j ++) {
        deque<long long> activeMinimums;
        for (int i = 1; i <= N; i ++) {
            if (i > K) remove(activeMinimums, minimumInRow[i - K][j]);
            add(activeMinimums, minimumInRow[i][j]);
            if (i >= K) result = (result + activeMinimums.front()) % MODULO;
        }
    }
    printf("%lld\n", result);
    
    return 0;
}
