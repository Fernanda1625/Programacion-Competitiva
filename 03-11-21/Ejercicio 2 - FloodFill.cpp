// Ejercicio 2: Una imagen est� representada por una imagen de cuadr�cula entera de m x n donde la imagen [i] [j]
// representa el valor de p�xel de la imagen. Tambi�n se le dan tres enteros sr, sc y newColor. Debe realizar un
// relleno de inundaci�n en la imagen a partir de la imagen de p�xeles [sr] [sc]. Para realizar un relleno de inundaci�n,
// considere el p�xel inicial, m�s los p�xeles conectados en 4 direcciones al p�xel inicial del mismo color que el p�xel
// inicial, m�s los p�xeles conectados en 4 direcciones a esos p�xeles (tambi�n con el mismo color), y pronto.
// Reemplace el color de todos los p�xeles mencionados anteriormente con newColor. Devuelve la imagen modificada despu�s
// de realizar el relleno por inundaci�n. (https://leetcode.com/problems/flood-fill/)

// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color == newColor) return image;
        dfs(&image, sr, sc, newColor, color);
        return image;
    }

private:
    void dfs(vector<vector<int>> *image, int r, int c, int newColor, int color) {
        static const vector<pair<int, int>> directions{{-1,  0}, { 1,  0},
                                                       { 0,  1}, { 0, -1}};
        if (r < 0 || r >= image->size() ||
            c < 0 || c >= (*image)[0].size() ||
            (*image)[r][c] != color) {
            return;
        }
        (*image)[r][c] = newColor;
        for (const auto& d : directions) {
            dfs(image, r + d.first, c + d.second, newColor, color);
        }
    }
};
