/*3) Faça um programa em C para calcular a matriz transposta de uma matriz quadrada de
ordem n. Qual a complexidade de tempo? Conte as instruções que são função de n e
compare os resultados.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAT 4

void geraMatriz (int **matriz, int linhaColuna);
void imprime (int **matriz, int linhaColuna);
void matrizTrans (int **matrizT, int **matriz, int linhaColuna, int *tempo);

int main ()
{
    srand(time(NULL));
    int *tempo = malloc(sizeof(int));
    *tempo = 0;

    int **matriz = malloc(MAT*(sizeof(int*)));
    for (int i=0; i<MAT; i++)
    {
        matriz[i] = malloc(MAT*sizeof(int));
    }

    geraMatriz(matriz, MAT);
    imprime(matriz, MAT);

    int **matrizT = malloc(MAT*(sizeof(int*)));
    for (int t=0; t<MAT; t++)
    {
        matrizT[t] = malloc(MAT*sizeof(int));
    }


    printf("\nMatriz Transposta:\n");
    matrizTrans(matrizT, matriz, MAT, tempo);
    imprime(matrizT, MAT);

    printf("\nComplexidade de tempo: %d\n", *tempo);
    printf("Complexidade: O(n^2)");

    return 0;
}

void geraMatriz (int **matriz, int linhaColuna)
{
    for (int i=0; i<linhaColuna; i++)
    {
        for (int j=0; j<linhaColuna; j++)
        {
            matriz[i][j] = (rand()%10)+1;
        }
    }
    return;
}

void imprime (int **matriz, int linhaColuna)
{
    for (int i=0; i<linhaColuna; i++)
    {
        for (int j=0; j<linhaColuna; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    return;
}

void matrizTrans (int **matrizT, int **matriz, int linhaColuna, int *tempo) //Complexidade O(n^2)
{
    int *p = malloc((linhaColuna*linhaColuna)*sizeof(int)), cont = 0;
    for (int i=0; i<linhaColuna; i++)
    {
        for (int j=0; j<linhaColuna; j++)
        {
            *(p+cont) = matriz[i][j];
            cont++;
        }
    }
    cont = 0;
    for (int i=0; i<linhaColuna; i++) //Complexidade O(n)
    {
        for (int j=0; j<linhaColuna; j++) //Complexidade O(n)
        {
            matrizT[j][i] = *(p+cont);
            cont++;
            (*tempo)++; //complexidade de tempo
        }
    }
    return;
}
