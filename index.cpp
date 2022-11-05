#include <iostream>

using namespace std;

/// @brief conversao via char do c
/// @param a ponteiro para a primeira casa do char
/// @return retorna valor do char
int charToInt(char* a) {
    int num = 0;

    for(char* i = a; *i != '\0'; i++)
        num = (num * 10) + (*(i) - '0');

    return num;
}

int main(int argc, char *argv[]) {
    int num = charToInt(argv[1]);

}