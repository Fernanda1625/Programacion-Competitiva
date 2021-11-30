// Problema 2: BrokenKeyboard
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1642
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

#define TEXT_SIZE 1000010
#define KEYBOARD_SIZE 128

char text[TEXT_SIZE];
int keys;

int bigger_substring_size = 0;

int biggerSubstring(){

    int substring_counter[KEYBOARD_SIZE];
    int curr_start = 0, curr_end = keys-1;
    int text_actual_size = strlen(text);
    int keys_used = 0, counter_aux = 0;

    for ( int i = 0; i < KEYBOARD_SIZE; ++i )
        substring_counter[i] = 0;

    // Contador para cada caracter
    for ( int i = 0; i < keys; ++i ){
        if( substring_counter[text[i]] == 0 ){
            // Numero de caracteres diferentes
            keys_used++;
        }
        substring_counter[text[i]]++;
    }

    // Mientras el texto no haya terminado
    while( curr_end < text_actual_size-2 ){
        // Aún no se ha alcanzado el límite de pulsaciones de teclas
        while( keys_used <= keys && (curr_end < text_actual_size-2) ){
            curr_end++;
            if( substring_counter[text[curr_end]] == 0 ){
                keys_used++;
            }
            substring_counter[text[curr_end]]++;
        }
        if( keys_used > keys ){
            curr_start++;
        }

        if( (curr_end - curr_start + 1) > bigger_substring_size ){
            bigger_substring_size = curr_end - curr_start + 1;
        }

        if( substring_counter[text[curr_start-1]] > 0 ){
            substring_counter[text[curr_start-1]]--;
            counter_aux = substring_counter[text[curr_start-1]];
            if(counter_aux == 0){
                keys_used--;
            }
        }
    }
    return 0;
}

int main(){
    while(true){

        bigger_substring_size = 0;
        scanf("%d", &keys);
        getchar();

        if( keys != 0 ){
            if( fgets(text, TEXT_SIZE, stdin) != NULL ){
                biggerSubstring();
            }
            printf("%d\n", bigger_substring_size);
        }
        else{
            break;
        }
    }
    return 0;
}
