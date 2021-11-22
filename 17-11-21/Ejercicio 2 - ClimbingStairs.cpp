/*
Ejercicio 2: Estás subiendo una escalera. Se necesitan n pasos para llegar a la cima.
Cada vez puedes subir 1 o 2 escalones. ¿De cuántas formas distintas puedes subir a la cima?
(https://leetcode.com/problems/climbing-stairs/)

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;

        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++)
        {
            int third = first + second;
            first = second;
            second = third;
        }

        return second;
    }
};
