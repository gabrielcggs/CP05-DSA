#include<stdio.h>

int somaVetor(int v[], int n)
{
    // Caso base
    if (n == 0){return 0;}

    // Recursividade
    return v[n - 1] + somaVetor(v, n - 1);
}

int maiorVetor(int vetor[], int n)
{
    // Caso base
    if (n == 1){return vetor[0];}

    // Encontra o maior dos elementos anteriores
    int maior = maiorVetor(vetor, n - 1);

    if (vetor[n - 1] > maior){return vetor[n - 1];}

    return maior;
}



int main()
{
    int v[] = {10, 20, 30, 40, 50};
    int n = sizeof(v) / sizeof(v[0]);
    printf("Soma: %d\n", somaVetor(v, n));
    printf("Maior: %d\n", maiorVetor(v, n));
    return 0;
}