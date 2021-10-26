// Ejercicio 2: Está enviando un mensaje a un amigo con un teclado especial. El teclado solo acepta letras minúsculas. Cuando se presiona el botón #, la última letra se elimina del mensaje. Dadas algunas pulsaciones de teclas: muestra el mensaje resultante.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

void backSpace(string &str){
  deque<char> cadena;
  string resultado = "";
  for (int i = 0; i < str.length(); i++){
    if (str[i]=='#')
      cadena.pop_back();
    else cadena.push_back(str[i]);
  }

  for (auto i = cadena.begin(); i != cadena.end(); i++ ){
    resultado += *i;
  }

  cout << resultado;
}

int main(){
  string s = "abc#de##f#ghi#jklmn#op#";
  //cin >> s;
  backSpace(s);

  return 0;
}
