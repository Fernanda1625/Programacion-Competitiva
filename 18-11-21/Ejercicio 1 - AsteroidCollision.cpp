/*
Ejercicio 1: Se nos da una matriz de asteroides de números enteros que representan asteroides en una fila.
Para cada asteroide, el valor absoluto representa su tamaño y el signo representa su dirección (positivo
que significa derecha, negativo que significa izquierda). Cada asteroide se mueve a la misma velocidad.
Descubra el estado de los asteroides después de todas las colisiones. Si dos asteroides se encuentran,
el más pequeño explotará. Si ambos son del mismo tamaño, ambos explotarán. Dos asteroides que se mueven en
la misma dirección nunca se encontrarán. (https://leetcode.com/problems/asteroid-collision/)

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> pila;

        for(int& cur : asteroids){
            bool exploded = false;
            while(!pila.empty() && pila.top() > 0 && cur < 0){
                int prev = pila.top();
                if(abs(prev) > abs(cur)){
                    exploded = true;
                    break;
                } else if(abs(prev) == abs(cur)){
                    pila.pop();
                    exploded = true;
                    break;
                }else{
                    //abs(prev) < abs(cur)
                    pila.pop();
                    //cur sigue yendo a la izquierda
                }
            }

            if(!exploded){
                pila.push(cur);
            }
        }

        asteroids.clear();

        while(!pila.empty()){
            asteroids.insert(asteroids.begin(), pila.top());
            pila.pop();
        }

        return asteroids;
    }
};
