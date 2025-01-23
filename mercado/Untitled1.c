/* Fa�a um controle de estoque com inclus�o de produto, compra, venda,
 * posi��o geral de estoque, consulta estoque de um produto, exclus�o de um produto.
 * Estrutura dos produtos:
 * C�digo: inteiro (chave prim�ria) (n�o pode repetir um c�digo)
 * Nome: string
 * Quantidade em estoque: inteiro (>=0)
 * Armazenamento dos produtos: lista encadeada com inser��o no in�cio da lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 20

typedef struct estoque
{
    int codigo, quantidade;
    char *nome;
    struct estoque *proximo;
} Estoque;

void imprimeMenu();
Estoque *inclusao (Estoque *atual);
Estoque *compra (Estoque *atual);
Estoque *venda (Estoque *atual);
void posicaoGeral (Estoque *atual);
void consulta (Estoque *atual);
Estoque *exclui (Estoque *atual);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Estoque *listaProdutos = (Estoque*) malloc(sizeof(Estoque));
    if(listaProdutos == NULL)
    {
        printf("N�o foi poss�vel alocar mem�ria!\n");
        return 0;
    }

    int opcao;
    do
    {
        imprimeMenu();
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            listaProdutos = inclusao(listaProdutos);
            break;
        case 2:
            listaProdutos = compra(listaProdutos);
            break;
        case 3:
            listaProdutos = venda(listaProdutos);
            break;
        case 4:
            posicaoGeral(listaProdutos);
            break;
        case 5:
            consulta(listaProdutos);
            break;
        case 6:
            listaProdutos = exclui(listaProdutos);
            break;
        case 7:
            printf("Programa encerrado...\n");
            break;
        default:
            printf("Op��o inv�lida! Escolha uma op��o v�lida...");
        }
    }
    while(opcao != 7);

    Estoque *temp;
    while(listaProdutos != NULL)
    {
        temp = listaProdutos;
        listaProdutos = listaProdutos->proximo;
        free(temp);
    }

    return 0;
}

void imprimeMenu()
{
    printf("\n=======================");
    printf("\nMenu");
    printf("\n=======================");
    printf("\n1 - Inclus�o");
    printf("\n2 - Compra");
    printf("\n3 - Venda");
    printf("\n4 - Posi��o geral");
    printf("\n5 - Consulta");
    printf("\n6 - Exclui");
    printf("\n7 - Sai");
    printf("\n=======================");
    printf("\nEscolha sua op��o: ");
    return;
}

Estoque *inclusao (Estoque *atual)
{
    Estoque *novo = (Estoque*) malloc(sizeof(Estoque));
    if(novo == NULL)
    {
        printf("N�o foi poss�vel alocar mem�ria!\n");
        return NULL;
    }

    printf("C�digo do produto: ");
    scanf("%d", &novo->codigo);

    if(atual != NULL)
    {
        Estoque *temp = atual;
        while(temp->proximo != NULL)
        {
            if(temp->codigo == novo->codigo)
            {
                printf("Produto j� cadastrado, n�o � poss�vel cadastrar novamente!\n");
                free(novo);
                return atual;
            }
            temp = temp->proximo;
        }
    }

    printf("Quantidade a ser adicionado: ");
    scanf("%d", &novo->quantidade);

    novo->nome = malloc(TAM * (sizeof(char)));
    if(novo->nome == NULL)
    {
        printf("N�o foi poss�vel alocar mem�ria!\n");
        return atual;
    }
    while (getchar() != '\n');   // Limpa o buffer de entrada
    printf("Nome do produto: ");
    fgets(novo->nome, TAM, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0'; // Remo��o do caractere '\n' (nova linha) caso ele tenha sido lido

    if(atual == NULL)
    {
        novo->proximo = NULL;
    }
    else
    {
        novo->proximo = atual;
    }

    return novo;
}

Estoque *compra (Estoque *atual)
{
    Estoque *temp = atual;
    int codigo;
    printf("Digite o c�digo do produto: ");
    scanf("%d", &codigo);
    while(temp->proximo != NULL)
    {
        if(temp->codigo == codigo)
        {
            int quantidade;
            printf("Quantidade a ser adicionada: ");
            scanf("%d", &quantidade);
            temp->quantidade += quantidade;
            printf("Comprado com sucesso!\n");
            return atual;
        }
        temp = temp->proximo;
    }
    printf("C�digo n�o cadastrado!\n");
    return atual;
}

Estoque *venda (Estoque *atual)
{
    Estoque *temp = atual;
    int codigo;
    printf("Digite o c�digo do produto: ");
    scanf("%d", &codigo);
    while(temp->proximo != NULL)
    {
        if(temp->codigo == codigo)
        {
            int quantidade;
            printf("Quantidade a ser removida: ");
            scanf("%d", &quantidade);
            if (quantidade > temp->quantidade)
            {
                printf("Quantidade insufici�nte em estoque!\n");
                return atual;
            }
            temp->quantidade -= quantidade;
            printf("Vendido com sucesso!\n");
            return atual;
        }
        temp = temp->proximo;
    }
    printf("C�digo n�o cadastrado!\n");
    return atual;
}

void posicaoGeral (Estoque *atual)
{
    if(atual->proximo == NULL)
    {
        printf("Estoque vazio!\n");
        return;
    }
    Estoque *leitura = atual;
    while(leitura->proximo != NULL)
    {
        printf("Nome: %s\t", leitura->nome);
        printf("C�digo: %d\t", leitura->codigo);
        printf("Quantidade: %d\n", leitura->quantidade);
        leitura = leitura->proximo;
    }
    return;
}

void consulta (Estoque *atual)
{
    Estoque *consultar = atual;
    int codigo;
    printf("Digite o c�digo do produto a ser consultado: ");
    scanf("%d", &codigo);
    while(consultar->proximo != NULL)
    {
        if(consultar->codigo == codigo)
        {
            printf("Nome: %s\t", consultar->nome);
            printf("C�digo: %d\t", consultar->codigo);
            printf("Quantidade: %d\n", consultar->quantidade);
            return;
        }
        consultar = consultar->proximo;
    }
    printf("Produto n�o cadastrado!\n");
    return;
}

Estoque *exclui (Estoque *atual)
{
    if (atual == NULL)
    {
        printf("Estoque vazio! Nada a excluir.\n");
        return NULL;
    }

    int codigo;
    printf("Digite o c�digo do produto a ser exclu�do: ");
    scanf("%d", &codigo);

    if(codigo == atual->codigo)
    {
        Estoque *temp = atual;
        atual = atual->proximo;
        free(temp);
        printf("Produto exclu�do com sucesso!\n");
        return atual;
    }

    Estoque *temp = atual->proximo;
    Estoque *aux = atual;
    while(temp != NULL)
    {
        if(temp->codigo == codigo)
        {
            aux->proximo = temp->proximo;
            free(temp);
            printf("Produto exclu�do com sucesso");
            return atual;
        }
        aux = aux->proximo;
        temp = temp->proximo;

    }
    printf("Produto Inexistente!\n");
    return atual;
}
