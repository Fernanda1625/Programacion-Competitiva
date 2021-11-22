/*
Ejercicio 3: Se le da un costo de matriz de n�meros enteros donde el costo [i] es
el costo del i-�simo escal�n en una escalera. Una vez que pague el costo, puede
subir uno o dos escalones. Puede comenzar desde el paso con �ndice 0 o desde el
paso con �ndice 1. Devuelve el costo m�nimo para llegar a la parte superior del piso.
(https://leetcode.com/problems/min-cost-climbing-stairs/)

Curso: Programaci�n Competitiva
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
