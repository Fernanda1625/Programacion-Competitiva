/*
Ejercicio 9: Los demonios hab�an capturado a la princesa y la hab�an encarcelado
en la esquina inferior derecha de una mazmorra. La mazmorra consta de m x n habitaciones
dispuestas en una cuadr�cula 2D. Nuestro valiente caballero se coloc� inicialmente en
la habitaci�n superior izquierda y debe abrirse camino a trav�s de la mazmorra para
rescatar a la princesa.  El caballo tiene un punto de vida inicial representado por
un n�mero entero positivo. Si en alg�n momento su punto de vida cae a 0 o menos,
muere inmediatamente. Algunas de las habitaciones est�n custodiadas por demonios
(representados por n�meros enteros negativos), por lo que el caballero pierde salud
al entrar en estas habitaciones; otras habitaciones est�n vac�as (representadas como 0)
o contienen orbes m�gicos que aumentan la salud del caballero (representados por n�meros
enteros positivos). Para alcanzar a la princesa lo m�s r�pido posible, el caballero decide
moverse solo hacia la derecha o hacia abajo en cada paso. Devuelve la salud inicial m�nima
del caballero para que pueda rescatar a la princesa. (https://leetcode.com/problems/dungeon-game/)

Curso: Programaci�n Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        //acolchado hacia abajo y hacia la derecha
        vector<vector<int>> minhp(m+1, vector<int>(n+1, INT_MAX));

        /*
        (m, n-1) y (m-1, n) es el vecino inferior y
        vecino derecho de la princesa
        */
        minhp[m][n-1] = minhp[m-1][n] = 1;

        for(int i = m-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                if(dungeon[i][j] - min(minhp[i+1][j], minhp[i][j+1]) >= 0){
                    minhp[i][j] = 1;
                } else{

                    minhp[i][j] = min(minhp[i+1][j], minhp[i][j+1])-dungeon[i][j];
                }
            }
        }

        return minhp[0][0];
    }
};
