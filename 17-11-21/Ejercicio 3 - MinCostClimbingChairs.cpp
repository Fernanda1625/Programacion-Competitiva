/*
Ejercicio 3: Se le da un costo de matriz de números enteros donde el costo [i] es
el costo del i-ésimo escalón en una escalera. Una vez que pague el costo, puede
subir uno o dos escalones. Puede comenzar desde el paso con índice 0 o desde el
paso con índice 1. Devuelve el costo mínimo para llegar a la parte superior del piso.
(https://leetcode.com/problems/min-cost-climbing-stairs/)

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(3);
        for (int i = cost.size() - 1; i >= 0; --i) {
            dp[i % 3] = cost[i] +
                        min(dp[(i + 1) % 3],
                            dp[(i + 2) % 3]);
        }
        return min(dp[0], dp[1]);
    }
};
