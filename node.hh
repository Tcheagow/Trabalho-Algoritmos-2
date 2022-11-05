#include <string>

using namespace std;

struct node {
    node* prox;
    string value;
    int* count;
};

void createNode(node* n, int pageNum) {
    n->prox = new node;
    n->prox->count = new int[pageNum];
    n->prox->prox = nullptr;
}