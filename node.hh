#include <string>

using namespace std;

/// @brief estrutura do no, sera um no circular (com cabeca) e ordenado
struct node {
    node* prox;
    string value;
    int* count;
};

/// @brief cria e adiciona o no
/// @param proxN proximo no
/// @param n no anterior
/// @param key valor da palavra (filosofico)
/// @param pageNum quantidade de paginas
/// @param thisPage numero da pagina
void createNode(node* proxN, node* n, string key, int pageNum, int thisPage) {
    n->prox = new node;
    n->prox->count = new int[pageNum];
    
    for(int i = 0; i < pageNum; i++) {
        n->prox->count[i] = 0;
    }

    n->prox->count[thisPage] = 1;

    n->prox->value = key;
    n->prox->prox = proxN;
}

/// @brief soma quando a palavra repete
/// @param n no achado
/// @param thisPage numero da pagina
void sumWord(node* n, int thisPage) {
    n->count[thisPage] += 1;
}

/// @brief faz o sistema de adicao
/// @param header e a cabeca
/// @param key valor da palavra (filosofico e tambem ja chega em lowercase)
/// @param pageNum quantidade de paginas
/// @param thisPage numero da pagina
void addWord(node* header, string key, int pageNum, int thisPage) {

    node* i = header->prox;
    for(;i->prox != header; i = i->prox) {
        if(i->value.compare(key) == 0) {
            sumWord(i, thisPage);
            return;
        }
        if(i->prox->value.compare(key) > 0) {
           createNode(i->prox, i, key, pageNum, thisPage);
           return;
        }
    }

    createNode(header, i, key, pageNum, thisPage);
}