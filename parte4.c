#include <stdio.h>
#include <stdlib.h>

typedef struct No No;

struct No
{
    int valor;
    No *proximo;
};

No *inicio = NULL;

No *inserirInicio(No *inicio, int valor)
{
    // 1. Alocar um novo nó
    No *novo = malloc(sizeof(No));

    // 2. Verificar se malloc retornou NULL
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return inicio;
    }

    // 3. Guardar o valor
    novo->valor = valor;

    // 4. Apontar para o início atual
    novo->proximo = inicio;

    // 5. Retornar o novo início
    return novo;
}

void imprimirLista(No *inicio)
{
    No *atual = inicio;

    while (atual != NULL)
    {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

int main()
{
    inicio = inserirInicio(inicio, 10);
    inicio = inserirInicio(inicio, 20);
    inicio = inserirInicio(inicio, 30);

    imprimirLista(inicio);

    No *atual = inicio;

    while (atual != NULL)
    {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}