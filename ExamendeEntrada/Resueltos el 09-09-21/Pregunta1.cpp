// Pregunta 1: Escriba una función que identifique si dos strings son anagramas o no.
// Un anagrama es una palabra que resulta de la transposición de letras de otra palabra.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//funcion para castear a char
int comparar(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

//funcion que verifica si dos cadenas son anagramas o no
int esAnagrama(char *cadena1, char *cadena2) {
  // Convertir a minúsculas a ambas palabras
  int contador = 0;
  while (cadena1[contador]) {
    cadena1[contador] = tolower(cadena1[contador]);
    contador++;
  }
  contador = 0;
  while (cadena2[contador]) {
    cadena2[contador] = tolower(cadena2[contador]);
    contador++;
  }

  // Ordenar las letras de ambas palabras
  qsort(cadena2, strlen(cadena2), sizeof(char), comparar);
  qsort(cadena1, strlen(cadena1), sizeof(char), comparar);

  // Si al ordenarlas y ponerlas en minúsculas son iguales, entonces son
  // anagramas
  return strcmp(cadena1, cadena2) == 0;
}

int main() {
  char palabras[3][2][20] = {
      {"Amor", "Roma"},
      {"Luis", "Saul"},
      {"odin", "nido"}};
  for (int i = 0; i < 3; i++) {
    printf("\n\nProbando con '%s' y '%s'\n", palabras[i][0], palabras[i][1]);
    int resultado = esAnagrama(palabras[i][0], palabras[i][1]);
    if (resultado) {
      printf("Si son Anagramas");
    } else {
      printf("No son anagramas");
    }
  }
  return 0;
}
