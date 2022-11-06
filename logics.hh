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

    setlocale(LC_ALL, "de_DE.utf8");
    
    for(int i = 0; i < size; i++)
        value += towlower(params[i]);  
    
    return value;
}

/// @brief verifica se tem todos os caracteres corretos
/// @param word string a se verificar
/// @param index index da string a se verificar
/// @details essa funcao usara a string ischar e os caracteres q nao estao dentro do range do 'a' e 'z' para verificar se corresponde, ja que tambem o valor pode estar fora como os apresentados na linha 44
/// @return retorna verdadeiro para caso seja uma letra 
bool isClearOfNonLetters(string word, int index) {

    string isChar = "ẃéŕýúíóṕáśǵj́ḱĺḉźǘńḿẽỹũĩõãṽñẁèỳùìòàǜǹm̀ŵêŷûîôâŝĝĥĵẑĉçäåæëïðöøüẂÉŔÝÚÍÓṔÁŚǴJ́ḰĹḈŹǗŃḾẼỸŨĨÕÃṼÑẀÈỲÙÌÒÀǛǸM̀ŴÊŶÛÎÔÂŜĜĤĴẐĈÇÄÅÆËÏÐÖØÜ";
    int lenghIsChar = isChar.length();
    
    for(int i = 0; i < lenghIsChar; i++) {
        if(word[index] == isChar[i]) return true;
    }

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

    if(file.fail()) {
        cout << "Entrada inválida" << endl;
        exit(404);
    }


    while(getline(file, aux))
        allWords.append(lowerWord(aux) + " "); // isso e importante pq quando for separar as palavras nao vai precisar de if extra

    file.close();

    return filter(allWords);
}

void fromFile(node* header, int pageNum, int thisPage, char* arq) {
    string fileTxt = readFile(arq);
    string aux = "";
    int sizeFile = fileTxt.length();

    for(int i = 0; i < sizeFile; i++) {
        if(fileTxt[i] != ' ') {
            aux += fileTxt[i];
        } else if(aux != "") {
            addWord(header, aux, pageNum ,thisPage);
            aux = "";
        }
    }
}


