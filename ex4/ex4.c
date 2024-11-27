/*4) Faça um programa em C para calcular o fatorial de n. Qual a complexidade de tempo?
Conte as instruções que são função de n e compare os resultados.*/

#include <stdio.h>
#include <stdlib.h>

void calculaFatorial(int n, int *p, int *t);

int main ()
{
    int *p = malloc(sizeof(int)), *t = malloc(sizeof(int));
    calculaFatorial(5, p, t); //120
    printf("Fatorial de 5: %d\n", *p);
    printf("Complexidade de tempo: %d\n", *t);
    calculaFatorial(7, p, t); //5040
    printf("Fatorial de 7: %d\n", *p);
    printf("Complexidade de tempo: %d\n", *t);
    calculaFatorial(2, p, t); //2
    printf("Fatorial de 2: %d\n", *p);
    printf("Complexidade de tempo: %d\n", *t);
    calculaFatorial(0, p, t); //1
    printf("Fatorial de 0: %d\n", *p);
    printf("Complexidade de tempo: %d\n", *t);
    calculaFatorial(1, p, t); //1
    printf("Fatorial de 1: %d\n", *p);
    printf("Complexidade de tempo: %d\n", *t);
    calculaFatorial(4, p, t); //24
    printf("Fatorial de 4: %d\n", *p);
    printf("Complexidade de tempo: %d\n", *t);

    printf("\nComplexidade de tempo sera exatamente o numero que queremos descobrir o fatorial\n");
    printf("Complexidade da funcao: O(n)");

    return 0;
}

void calculaFatorial(int n, int *p, int *t)
{
    *p = 1;
    *t = 0;
    for (int i=1; i<=n; i++) //Complexidade: O(n)
    {
        (*t)++;
        *p = (*p) * i;
    }
    return;
}
