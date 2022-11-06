#include <iostream>
#include <fstream>
#include <string>
#include "./node.hh"
using namespace std;

/// @brief funcao para retornar a palavra em lowerCase
/// @param params string a passar pelo lower case
/// @return retorna a string em lowercase
string lowerWord(string params) {
    string value;
    int size = params.length();

    for(int i = 0; i < size; i++)
        value += tolower(params[i]);
    
    return value;
}

/// @brief verifica se tem todos os caracteres corretos
/// @param word
/// @return retorna verdadeiro para caso seja uma letra 
bool isClearOfNonLetters(string word, int index) {
    return (((word[index] >= 'a' && word[index] <= 'z')) || word[index] == ' ');
}

string filter(string value) {
    int max = value.length();
    string finalValue("");

    for(int i = 0; i < max; i++)
        if(isClearOfNonLetters(value, i))
            finalValue += value[i];

    return finalValue;
}

/// @brief funcao onde le e retorna o valor em string
/// @param arq argumento do arquivo 
/// @return texto inserido dentro 
string readFile(char* arq) {
    ifstream file(arq);
    string allWords = "";
    string aux;

    while(getline(file, aux))
        allWords.append(lowerWord(aux));

    file.close();

    return filter(allWords);
}