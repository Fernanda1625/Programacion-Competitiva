/*
Ejercicio 4: Un robot est� ubicado en la esquina superior izquierda de una cuadr�cula de m x n
(marcado como 'Inicio' en el diagrama a continuaci�n). El robot solo puede moverse hacia abajo
o hacia la derecha en cualquier momento. El robot est� tratando de llegar a la esquina inferior
derecha de la cuadr�cula (marcada como 'Finalizar' en el diagrama a continuaci�n). Ahora considere
si se agregan algunos obst�culos a las cuadr�culas. �Cu�ntos caminos �nicos habr�a? Un obst�culo
y un espacio se marcan como 1 y 0 respectivamente en la cuadr�cula.
(https://leetcode.com/problems/unique-paths-ii/)

Curso: Programaci�n Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid){
        const int row = obstacleGrid.size();
        const int column = obstacleGrid[0].size();

        vector<int> path(obstacleGrid[0].size(), 1);
        if (obstacleGrid[0][0] == 1){
            path[0] = 0;
        }
        for (size_t c = 1; c < column; ++c){
            if (obstacleGrid[0][c] == 1 || path[c - 1] == 0)
            {
                path[c] = 0;
            }
        }

        for (size_t r = 1; r < row; ++r){
            if (obstacleGrid[r][0] == 1){
                path[0] = 0;
            }
            for (size_t c = 1; c < column; ++c){
                if (obstacleGrid[r][c] == 1){
                    path[c] = 0;
                }
                else{
                    path[c] += path[c - 1];
                }
            }
        }

        return path.back();
    }
};
