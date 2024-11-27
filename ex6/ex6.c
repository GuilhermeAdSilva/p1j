/*6) Faça um programa em C que calcule o produto de matrizes quadradas de ordem n. Qual
a complexidade de tempo? Conte as instruções que são função de n e compare os
resultados.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAT 2

void geraMatriz (int **matriz, int linhaColuna);
void imprimeMatriz (int **matriz, int linhaColuna);
void produtoMatriz (int **matA, int **matB, int **matR, int ordem);
void matrizTrans (int **matrizT, int **matriz, int linhaColuna);

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

    produtoMatriz(matrizA, matrizB, matrizResultado, MAT);
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

void produtoMatriz (int **matA, int **matB, int **matR, int ordem)
{
    int **matBtrans = malloc(MAT*(sizeof(int*)));
    for (int i=0; i<MAT; i++)
    {
        matBtrans[i] = malloc(MAT*(sizeof(int)));
    }
    matrizTrans(matBtrans, matB, ordem);

    for (int i=0; i<ordem; i++)
    {
        for (int j=0; j<ordem; j++)
        {
            matR[i][j] = 0;
        }
    }
    imprimeMatriz(matR, ordem);
    return;
}

void matrizTrans (int **matrizT, int **matriz, int linhaColuna) //Complexidade O(n^2)
{
    for (int i=0; i<linhaColuna; i++)
    {
        for (int j=0; j<linhaColuna; j++)
        {
            matrizT[j][i] = matriz[i][j];
        }
    }
    return;
}
