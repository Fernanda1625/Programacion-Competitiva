/*
Ejercicio 8: Un robot est� ubicado en la esquina superior izquierda de una cuadr�cula de m x n.
El robot solo puede moverse hacia abajo o hacia la derecha en cualquier momento. El robot est�
tratando de llegar a la esquina inferior derecha de la cuadr�cula. �Cu�ntos caminos �nicos
posibles hay? (https://leetcode.com/problems/unique-paths/)

Curso: Programaci�n Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coeff(int m, int n) {
        long long int ans=1;

        int temp = m;
        if(n>m){
            m = n;
            n = temp;
        }

        for(int i=1; i<=n; i++){
            ans *= (m+i);
        }
        for(int i=1; i<=n; i++){
            ans /= i;
        }

        return ans;
    }
    int uniquePaths(int m, int n) {

        //Ir a la derecha m-1 veces y bajar n-1 veces en cualquier ruta v�lida
        // Caminos de este tipo: (m+n-2)!/(m-1)!(n-1)!
        m = m-1;
        n = n-1;
        // => (m+n)!/m!n!
        // => (m+n)(m+n-1)...(m+1)/n!
        return coeff(m,n);
    }
};
