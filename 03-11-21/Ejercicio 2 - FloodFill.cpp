// Ejercicio 2: Una imagen está representada por una imagen de cuadrícula entera de m x n donde la imagen [i] [j]
// representa el valor de píxel de la imagen. También se le dan tres enteros sr, sc y newColor. Debe realizar un
// relleno de inundación en la imagen a partir de la imagen de píxeles [sr] [sc]. Para realizar un relleno de inundación,
// considere el píxel inicial, más los píxeles conectados en 4 direcciones al píxel inicial del mismo color que el píxel
// inicial, más los píxeles conectados en 4 direcciones a esos píxeles (también con el mismo color), y pronto.
// Reemplace el color de todos los píxeles mencionados anteriormente con newColor. Devuelve la imagen modificada después
// de realizar el relleno por inundación. (https://leetcode.com/problems/flood-fill/)

// Curso: Programación Competitiva
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
