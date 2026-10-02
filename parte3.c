#include <stdio.h>

// Definição do apelido No para struct No
typedef struct No No;

// Definição da estrutura do nó
struct No {
    int valor;
    No *proximo;
};

int main()
{
    // Ponteiro para um nó da lista
    No *inicio = NULL;

    return 0;
}
