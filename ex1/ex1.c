/*1) Faça um programa em C para encontrar o maior elemento de um vetor (lista) com n
elementos aleatórios não ordenados. Qual a complexidade de tempo? Conte as instruções
que são função de n e compare os resultados.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000

void preencheVetor (int *vet, int tamanho);
void maiorElemento (int *vet, int tamanho, int *p, int *ct);
void imprimeVetor (int *vet, int tamanho);

int main ()
{
    srand(time(NULL));
    int *contatempo = (int)malloc(sizeof(int));
    *contatempo = 0;
    int *vetor = (int*)malloc(sizeof(int)*TAM), *p = (int*)malloc(sizeof(int));
    *p = 0;
    preencheVetor(vetor, TAM);
    maiorElemento(vetor, TAM, p, contatempo);
    imprimeVetor(vetor, TAM);
    printf("\nMaior elemento: %d\n", *p);
    printf("Complexidade de tempo: %d\n", *contatempo);
    printf("Complexidade: O(n)\n");
    return 0;
}

void preencheVetor (int *vet, int tamanho)
{
    for (int i=0; i<tamanho; i++)
    {
        *(vet+i) = (rand()%1000)+1;
    }
    return;
}

void maiorElemento (int *vet, int tamanho, int *p, int *ct)
{
    int maior = 0;
    for (int i=1; i<tamanho; i++) //complexidade: O(n)
        {
            (*ct)++; //numero de execuções será: tamanho-1
            if (*(vet+i) > *(vet+maior))
            {
                maior = i;
            }
        }
    *p = *(vet+maior);
    return;
}

void imprimeVetor (int *vet, int tamanho)
{
    for (int i=0; i<tamanho; i++)
    {
        printf("%d ", *(vet+i));
    }
    printf("\n");
    return;
}
