#include <stdio.h>
#include <string>

using namespace std;

void ReadFile(node* n, char* arq) {
    FILE *file;
    //nome do arquivo - talvez de erro, pois é necessário da extensão (não sei como vai vir no parâmetro)
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
    printf("%s", allWords);

    //fecha o file
    fclose(file);
} 