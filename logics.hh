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
        value += towlower(params[i]);  
    
    return value;
}

/// @brief verifica se tem todos os caracteres corretos
/// @param word string a se verificar
/// @param index index da string a se verificar
/// @details essa funcao usara a string ischar e os caracteres q nao estao dentro do range do 'a' e 'z' para verificar se corresponde, ja que tambem o valor pode estar fora como os apresentados na linha 44
/// @return retorna verdadeiro para caso seja uma letra 
bool isClearOfNonLetters(string word, int index) {
    string isChar = "ÁÉÍÓÚÊÔÃÕÀÇáéíóúêôãõàç";
    int lengthIsChar = isChar.length();
    
    for(int i = 0; i < lengthIsChar; i++) {
        if(word[index] == isChar[i]) return true;
    }

    return false;
}

/// @brief atraves de um calculo simples retorna o oposto
/// @param word string a se verificar
/// @param index index da string a se verificar
/// @return retorna a letra em minusculo
string tolowerNonAscii(string word, int index) {
    string aux;
    aux += word[index];
    aux += word[index + 1];

    string toCheck[][2] =  {{"Á","á"}, {"É","é"}, {"Í","í"}, {"Ó","ó"}, {"Ú","ú"}, {"Ê","ê"}, {"Ô","ô"}, {"Ã","ã"}, {"Õ","õ"}, {"À","à"}, {"Ç","ç"}};

    for(int i = 0; i < 21; i++) {
        if(aux == toCheck[i][0]) {
            aux = toCheck[i][1][0];
            aux += toCheck[i][1][1];
            return aux;
        }
    }

    return aux;
}

/// @brief filtra valores que nao sejam caracteres alfabeticos
/// @param value valor a ser filtrado
/// @return retorna a string filtrado
string filter(string value) {
    int max = value.length();
    string finalValue("");

    for(int i = 0; i < max; i++)
        if(((value[i] >= 'a' && value[i] <= 'z')) || value[i] == ' ')
            finalValue += value[i];
        else if(isClearOfNonLetters(value, i)) {
            finalValue += tolowerNonAscii(value, i);
            i++;
        }

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

/// @brief fluxo principal de obter informacoes do arquivo
/// @param header cabeca do no
/// @param pageNum numero de paginas (total)
/// @param thisPage numero da pagina atual
/// @param arq argumento com o nome do arquivo
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

/// @brief cria o arquivo resultado
/// @param header no da cabeca
/// @param pageNum numero de paginas (total)
void toFile(node* header, int pageNum) {
    node* i = header->prox;
    ofstream out("resultado.out");

    for(; i != header; i = i->prox) {
        string value = i->value;
        for(int j = 0; j < pageNum; j++){
            value += " " + to_string(i->count[j]);
        }
        
        out << value << endl;
    }
}