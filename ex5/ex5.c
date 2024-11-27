/*5) Faça um programa em C que conte quantos pares de números em um vetor (lista) de
tamanho n possuem soma igual a um valor k. Qual a complexidade de tempo? Conte as
instruções que são função de n e compare os resultados.
Exemplo: vetor = {1, 5, 7, -1, 5}
k = 6
Resposta: 3: (1, 5), (1, 5), (7, -1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void preencheVetor (int *vet, int tamanho);
void imprimeVetor (int *vet, int tamanho);
void paresSomak (int k, int *vet, int tamanho);

int main ()
{
    srand(time(NULL));
    int *vetor = malloc(TAM*(sizeof(int)));
    preencheVetor(vetor, TAM);
    imprimeVetor(vetor, TAM);
    paresSomak(6, vetor, TAM);
    return 0;
}

void preencheVetor (int *vet, int tamanho)
{
    int negativo = 0;
    for (int i=0; i<tamanho; i++)
    {
        *(vet+i) = rand()%11; //de 0 a 10
        if(rand()%2 == 1)  //de -10 a 10
        {
            *(vet+i) = *(vet+i) * (-1);
        }
    }
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

void paresSomak (int k, int *vet, int tamanho)
{
    int temp, contIndice = 0;
    int *indices = malloc(sizeof(int)), *pares = malloc(sizeof(int));
    *pares = 0;
    printf("valor de k = %d\n", k);
    for (int i=0; i<=tamanho-1; i++)
    {
        for(int j=i; j<tamanho-1; j++)
        {
            if((*(vet+i)) + (*(vet+j+1)) == k)
            {
                *(indices+contIndice) = *(vet+i);
                contIndice++;
                *(indices+contIndice) = *(vet+j+1);
                contIndice++;
                *pares = *pares + 1;
            }
        }
    }
    (*pares == 0) ? printf("Resposta: 0") : printf("Resposta: %d: ", *pares);
    *pares = (*pares) * 2;
    for (int i=0; i<(*pares); i=i+2)
    {
        printf("(%d, %d) ", *(indices+i), *(indices+i+1));
    }
    return;
}
