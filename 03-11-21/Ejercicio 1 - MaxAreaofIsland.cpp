// Ejercicio 1: Se le da una cuadr�cula de matriz binaria de m x n. Una isla es un grupo de unos (que representan tierra)
// conectados en 4 direcciones (horizontal o vertical). Puede suponer que los cuatro bordes de la cuadr�cula est�n rodeados
// de agua. El �rea de una isla es el n�mero de celdas con valor 1 en la isla. Devuelve el �rea m�xima de una isla en la cuadr�cula.
// Si no hay isla, devuelve 0. (https://leetcode.com/problems/max-area-of-island/)

// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                    res=max(res,dfs(grid,i,j));
        return res;
    }
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        return dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1)+1;
    }
};
