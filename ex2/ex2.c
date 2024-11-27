/*2) Faça um programa em C para encontrar o maior elemento de um vetor (lista) com n
elementos aleatórios ordenados de forma crescente. Qual a complexidade de tempo?
Conte as instruções que são função de n e compare os resultados.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000

void preencheVetor (int *vet, int tamanho);
void ordenaVetor (int *vet, int tamanho);
void maiorElemento (int *vet, int tamanho, int *p, int *ct);

int main ()
{
    srand(time(NULL));
    int *contatempo = (int)malloc(sizeof(int));
    *contatempo = 0;
    int *vetor = (int*)malloc(sizeof(int)*TAM), *p = (int*)malloc(sizeof(int));
    *p = 0;
    preencheVetor(vetor, TAM);
    ordenaVetor(vetor, TAM);
    maiorElemento(vetor, TAM, p, contatempo);
    free(contatempo);
    free(vetor);
    free(p);
    return 0;
}

void preencheVetor (int *vet, int tamanho)
{
    for (int i=0; i<tamanho; i++)
    {
        *(vet+i) = (rand()%TAM)+1;
    }
    return;
}

void ordenaVetor (int *vet, int tamanho)
{
    int temp;
    for(int j=tamanho-1; j>0; j--)
    {
        for (int i=1; i<=j; i++)
        {
            if (*(vet+i-1) > *(vet+i))
            {
                temp = *(vet+i);
                *(vet+i) = *(vet+i-1);
                *(vet+i-1) = temp;
            }
        }
    }
    return;
}

void maiorElemento (int *vet, int tamanho, int *p, int *ct)
{
    (*ct)++; //numero de execuções será: 1, complexidade ctt O(1)
    *p = *(vet+tamanho-1);
    return;
}
