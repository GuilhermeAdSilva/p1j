/* Faça um controle de estoque com inclusão de produto, compra, venda,
 * posição geral de estoque, consulta estoque de um produto, exclusão de um produto.
 * Estrutura dos produtos:
 * Código: inteiro (chave primária) (não pode repetir um código)
 * Nome: string
 * Quantidade em estoque: inteiro (>=0)
 * Armazenamento dos produtos: lista encadeada com inserção no início da lista
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
        printf("Não foi possível alocar memória!\n");
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
            printf("Opção inválida! Escolha uma opção válida...");
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
    printf("\n1 - Inclusão");
    printf("\n2 - Compra");
    printf("\n3 - Venda");
    printf("\n4 - Posição geral");
    printf("\n5 - Consulta");
    printf("\n6 - Exclui");
    printf("\n7 - Sai");
    printf("\n=======================");
    printf("\nEscolha sua opção: ");
    return;
}

Estoque *inclusao (Estoque *atual)
{
    Estoque *novo = (Estoque*) malloc(sizeof(Estoque));
    if(novo == NULL)
    {
        printf("Não foi possível alocar memória!\n");
        return NULL;
    }

    printf("Código do produto: ");
    scanf("%d", &novo->codigo);

    if(atual != NULL)
    {
        Estoque *temp = atual;
        while(temp->proximo != NULL)
        {
            if(temp->codigo == novo->codigo)
            {
                printf("Produto já cadastrado, não é possível cadastrar novamente!\n");
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
        printf("Não foi possível alocar memória!\n");
        return atual;
    }
    while (getchar() != '\n');   // Limpa o buffer de entrada
    printf("Nome do produto: ");
    fgets(novo->nome, TAM, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0'; // Remoção do caractere '\n' (nova linha) caso ele tenha sido lido

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
    printf("Digite o código do produto: ");
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
    printf("Código não cadastrado!\n");
    return atual;
}

Estoque *venda (Estoque *atual)
{
    Estoque *temp = atual;
    int codigo;
    printf("Digite o código do produto: ");
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
                printf("Quantidade insuficiênte em estoque!\n");
                return atual;
            }
            temp->quantidade -= quantidade;
            printf("Vendido com sucesso!\n");
            return atual;
        }
        temp = temp->proximo;
    }
    printf("Código não cadastrado!\n");
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
        printf("Código: %d\t", leitura->codigo);
        printf("Quantidade: %d\n", leitura->quantidade);
        leitura = leitura->proximo;
    }
    return;
}

void consulta (Estoque *atual)
{
    Estoque *consultar = atual;
    int codigo;
    printf("Digite o código do produto a ser consultado: ");
    scanf("%d", &codigo);
    while(consultar->proximo != NULL)
    {
        if(consultar->codigo == codigo)
        {
            printf("Nome: %s\t", consultar->nome);
            printf("Código: %d\t", consultar->codigo);
            printf("Quantidade: %d\n", consultar->quantidade);
            return;
        }
        consultar = consultar->proximo;
    }
    printf("Produto não cadastrado!\n");
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
    printf("Digite o código do produto a ser excluído: ");
    scanf("%d", &codigo);

    if(codigo == atual->codigo)
    {
        Estoque *temp = atual;
        atual = atual->proximo;
        free(temp);
        printf("Produto excluído com sucesso!\n");
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
            printf("Produto excluído com sucesso");
            return atual;
        }
        aux = aux->proximo;
        temp = temp->proximo;

    }
    printf("Produto Inexistente!\n");
    return atual;
}
