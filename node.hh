#include <string>

using namespace std;

/// @brief node struct
struct node {
    node* prox;
    string value;
    int* count;
};

/// @brief create an add 
/// @param proxN next node
/// @param n last node
/// @param key value of word
/// @param pageNum size of pages
/// @param thisPage num of page
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

/// @brief sum word
/// @param n node finded
/// @param thisPage num of page
void sumWord(node* n, int thisPage) {
    n->count[thisPage] += 1;
}

/// @brief compare words
/// @param header first node
/// @param key value of word
/// @param pageNum size of pages
/// @param thisPage num page
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