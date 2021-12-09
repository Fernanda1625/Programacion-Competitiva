// Ejercicio 3: String Matching
// URL: https://open.kattis.com/problems/stringmatching
// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

vector<int> kmp_pre(string substring){
    vector<int> table(substring.size() + 1, -1);
    for( int i = 1; i <= substring.size(); i++ ){
        int pos = table[i - 1];

        while( pos != -1 && substring[pos] != substring[i - 1] ){
            pos = table[pos];
        }
        table[i] = pos + 1;
    }
    return table;
}

void kmp_search( string substring, string fullstring, vector<int> table ){
    int fullIndex = 0;
    int subIndex = 0;

    int fSize = (int)fullstring.size();
    int sSize = (int)substring.size();

    while( fullIndex < fSize ){
        while( subIndex != -1 && (subIndex == sSize || substring[subIndex] != fullstring[fullIndex]) )
            subIndex = table[subIndex];

        subIndex++;
        fullIndex++;

        if( subIndex == sSize ){
            cout << fullIndex - sSize << " ";
        }
    }
    cout << "\n";
}


int main() {
    char buffer[1048576];
    cin.rdbuf()->pubsetbuf(buffer, sizeof(buffer));

    int x,y,z;
    string sub, full;
    while ( getline(cin,sub) ) {
        getline(cin, full);
        kmp_search(sub, full, kmp_pre(sub));
    }
}
