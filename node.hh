#include <string>

using namespace std;

struct node {
    node* prox;
    string value;
    int* count;
};

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

void sumWord(node* n, int thisPage) {
    n->count[thisPage] += 1;
}

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