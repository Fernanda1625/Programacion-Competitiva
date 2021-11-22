/*
Ejercicio 1: Dada una cuadrícula de matriz de números enteros n x n,
devuelve la suma mínima de una trayectoria descendente con cambios distintos
de cero. Una trayectoria descendente con cambios distintos de cero es una
elección de exactamente un elemento de cada fila de la cuadrícula de modo
que no haya dos elementos elegidos en filas adyacentes en la misma columna.
(https://leetcode.com/problems/minimum-falling-path-sum-ii/)

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //inicializar la primera fila de dp
        for(int j = 0; j < n; j++){
            dp[0][j] = arr[0][j];
        }

        for(int i = 1; i < m; i++){
            vector<int> last_row(dp[i-1].begin(), dp[i-1].end());
            auto last_row_min_it = min_element(last_row.begin(), last_row.end());
            int last_row_min_idx = last_row_min_it - last_row.begin();
            int last_row_min = *last_row_min_it;
            nth_element(last_row.begin(), last_row.begin()+1, last_row.end(), less<int>());
            int last_row_2min = last_row[1];
            for(int j = 0; j < n; j++){
                if(j == last_row_min_idx){
                    dp[i][j] = arr[i][j] + last_row_2min;
                }else{
                    dp[i][j] = arr[i][j] + last_row_min;
                }
            }
        }

        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};
