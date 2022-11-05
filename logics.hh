#include <stdio.h>
#include <string>
#include <node.hh>

using namespace std;

/// @brief funcao onde le e retorna o valor em string
/// @param arq argumento do arquivo
/// @return texto inserido dentro 
string ReadFile(char* arq) {
    FILE *file;
    //nome do arquivo
    file = fopen(arq, "r");
    string allWords;

    //verifica se o arquivo foi lido corretamente, senão fecha o programa
    if (file == NULL) {
        printf("Problemas na abertura do arquivo\n");
        fclose(file);
        exit(0);
    }

    //le tudo do file
    fscanf(file, "%[^EOF]s", &allWords);

    //fecha o file
    fclose(file);

    return allWords;
} 