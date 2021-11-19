/*
Ejercicio 5: Hay n habitaciones etiquetadas de 0 a n - 1 y todas las habitaciones est�n
bloqueadas excepto la habitaci�n 0. Su objetivo es visitar todas las habitaciones.
Sin embargo, no puede ingresar a una habitaci�n cerrada sin tener su llave. Cuando
visita una habitaci�n, puede encontrar un juego de llaves distintas en ella. Cada
llave tiene un n�mero que indica qu� habitaci�n desbloquea, y puedes llevarlas todas
contigo para desbloquear las otras habitaciones.  Dada una matriz de habitaciones donde
las habitaciones [i] es el conjunto de claves que puede obtener si visit� la habitaci�n i,
devuelva verdadero si puede visitar todas las habitaciones, o falso en caso contrario.
(https://leetcode.com/problems/keys-and-rooms/)

Curso: Programaci�n Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> buscar = {0};
        vector<int> stack = {0};
        while (!stack.empty()) {
            auto node = stack.back();
            stack.pop_back();
            for (const auto& el : rooms[node]) {
                if (!buscar.count(el)) {
                    buscar.emplace(el);
                    if (buscar.size() == rooms.size()) {
                        return true;
                    }
                    stack.emplace_back(el);
                }
            }
        }
        return buscar.size() == rooms.size();
    }
};
