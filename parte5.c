#include <stdio.h>
#include <stdlib.h>

    typedef struct No No;

struct No
{
    int valor;
    No *proximo;
}

/*
 * Função auxiliar para montar a lista utilizada no exercício 5.
 * A atividade trabalha a inserção no início antes do percurso.
 */
No *inserirInicio(No *inicio, int valor)
{
    // ALOCAÇÃO DO NÓ
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        return inicio;
    }

    novo->valor = valor;

    // LIGAÇÃO COM O PRÓXIMO NÓ
    novo->proximo = inicio;

    return novo;
}

/*
 * Exercício 5 - Imprimindo a lista
 */
void imprimirLista(No *inicio)
{
    // Utilizamos um ponteiro auxiliar para não alterar o início da lista.
    No *atual = inicio;

    while (atual != NULL)
    {
        // EXIBIÇÃO DO VALOR DO NÓ
        printf("%d -> ", atual->valor);

        // AVANÇO PARA O PRÓXIMO NÓ
        atual = atual->proximo;
    }

    printf("NULL\n");
}

int main(void)
{
    No *inicio = NULL;

    /*
     * Montagem de uma lista de exemplo.
     * Como a inserção ocorre no início, os valores serão impressos
     * na ordem inversa à ordem destas chamadas.
     */
    inicio = inserirInicio(inicio, 30);
    inicio = inserirInicio(inicio, 20);
    inicio = inserirInicio(inicio, 10);

    printf("Lista encadeada: ");
    imprimirLista(inicio);

    /*
     * Liberação dos nós criados.
     * Não faz parte do exercício de remoção; é apenas para evitar
     * deixar a memória alocada ao programa.
     */
    No *atual = inicio;
    while (atual != NULL)
    {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}
