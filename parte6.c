int buscar(No *inicio, int valor) {
    No *atual = inicio;

    while (atual != NULL) {
        // Verifique se o valor foi encontrado
        if (atual->valor == valor) {
            return 1;
        }

        // Avance para o próximo nó
        atual = atual->proximo;
    }

    return 0;
}

