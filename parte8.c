#include <stdio.h>
#include <stdlib.h>

typedef struct No No;

struct No {
    int valor;
    No *proximo;
};

No *inserirInicio(No *inicio, int valor) {
    No *novo;

    // ALOCAÇÃO DO NÓ
    novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return inicio;
    }

    novo->valor = valor;

    // LIGAÇÃO COM O PRÓXIMO NÓ
    novo->proximo = inicio;

    return novo;
}

void imprimirLista(No *inicio) {
    No *atual = inicio;

    // CASO BASE: a lista está vazia, portanto não há nós para percorrer.
    if (inicio == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("Lista: ");

    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

//Essa e a busca.
int buscar(No *inicio, int valor) {
    No *atual = inicio;

    // BUSCA: percorre a lista procurando o valor informado.
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

void liberarLista(No *inicio) {
    No *atual = inicio;
    No *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main(void) {
    No *inicio = NULL;
    int opcao;
    int valor;

    do {
        printf("\n===== LISTA ENCADEADA =====\n");
        printf("1 - Inserir valor no inicio\n");
        printf("2 - Mostrar lista\n");
        printf("3 - Buscar valor\n");
        printf("4 - Mostrar primeiro elemento\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);

                inicio = inserirInicio(inicio, valor);

                printf("Valor inserido com sucesso.\n");
                break;

            case 2:
                imprimirLista(inicio);
                break;

            case 3:
                printf("Valor para buscar: ");
                scanf("%d", &valor);

                if (buscar(inicio, valor)) {
                    printf("Valor encontrado na lista.\n");
                } else {
                    printf("Valor nao encontrado na lista.\n");
                }

                break;

            case 4:
                if (inicio == NULL) {
                    printf("A lista esta vazia.\n");
                } else {
                    printf("Primeiro elemento: %d\n", inicio->valor);
                }

                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    liberarLista(inicio);

    return 0;
}
