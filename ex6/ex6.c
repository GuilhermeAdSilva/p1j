/*6) Faça um programa em C que calcule o produto de matrizes quadradas de ordem n. Qual
a complexidade de tempo? Conte as instruções que são função de n e compare os
resultados.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAT 2

void geraMatriz (int **matriz, int linhaColuna);
void imprimeMatriz (int **matriz, int linhaColuna);
void produtoMatriz (int **matA, int **matB, int **matR, int ordem, int *t);

int main ()
{
    srand(time(NULL));

    int **matrizA = malloc(MAT*(sizeof(int*)));
    for (int i=0; i<MAT; i++)
    {
        matrizA[i] = malloc(MAT*(sizeof(int)));
    }
    geraMatriz(matrizA, MAT);
    imprimeMatriz(matrizA, MAT);

    int **matrizB = malloc(MAT*(sizeof(int*)));
    for (int i=0; i<MAT; i++)
    {
        matrizB[i] = malloc(MAT*(sizeof(int)));
    }
    geraMatriz(matrizB, MAT);
    imprimeMatriz(matrizB, MAT);

    int **matrizResultado = malloc(MAT*(sizeof(int*)));
    for (int i=0; i<MAT; i++)
    {
        matrizResultado[i] = malloc(MAT*(sizeof(int)));
    }
    int *t = malloc(sizeof(int));
    *t = 0;

    produtoMatriz(matrizA, matrizB, matrizResultado, MAT, t);
    printf("Complexidade de tempo: %d\n", *t);
    printf("Complexidade: O(n^3)");
    return 0;
}

void geraMatriz (int **matriz, int linhaColuna)
{
    for (int i=0; i<linhaColuna; i++)
    {
        for (int j=0; j<linhaColuna; j++)
        {
            matriz[i][j] = (rand()%11);
            if (rand()%2 == 1 && matriz[i][j] != '0')
            {
                matriz[i][j] = matriz[i][j] * (-1);
            }
        }
    }
    return;
}

void imprimeMatriz (int **matriz, int linhaColuna)
{
    for (int i=0; i<linhaColuna; i++)
    {
        for (int j=0; j<linhaColuna; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void produtoMatriz (int **matA, int **matB, int **matR, int ordem, int *t)
{
    for (int i=0; i<ordem; i++)
    {
        for (int j=0; j<ordem; j++)
        {
            int produto = 0;
            for (int c=0; c<ordem; c++)
            {
                produto += matA[i][c] * matB[c][j];
                (*t)++;
            }
            matR[i][j] = produto;
        }
    }
    imprimeMatriz(matR, ordem);
    return;
}
