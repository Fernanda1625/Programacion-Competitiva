// Ejercicio 1: Está enviando un mensaje a un amigo con un teclado especial. El teclado solo acepta letras minúsculas y las almacena en un búfer. Cuando se presiona la tecla @, alterna la tecla Bloq Mayús: todas las letras en el búfer cambiar su caso, así como todas las pulsaciones de teclas posteriores. Cuando se presiona la tecla $, se vacía todo el búfer. Dadas algunas pulsaciones de teclas: muestra el mensaje resultante.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

void capsLock(string &str){
  queue<char> cadena;
  string resultado = "";
  bool mayuscula = false;

  for (int i=0; i < str.length();i++){
    if(str[i] == '$'){
      while (!cadena.empty()){
        resultado += (mayuscula) ? toupper(cadena.front()) : tolower(cadena.front());
        cadena.pop();
      }
    } else if (str[i] == '@'){
        mayuscula = (mayuscula) ? false : true;
      }else {
        cadena.push(str[i]);
      }
  }
  cout << resultado << endl;
}

int main(){
    string cadena = "abc$d@ef$@g$";
    //cin >> cadena;
    capsLock(cadena);

    return 0;
}
