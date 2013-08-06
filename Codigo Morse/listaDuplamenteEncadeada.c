#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

struct noListDu{
    int item;
    NoListDu* proximo;
    NoListDu* anterior;
};

NoListDu* criarListaDuplamenteEncadeada()
{
    return NULL;
}

int listaVazia_ListDu(NoListDu* primeiro)
{
    return (primeiro == NULL);
}

NoListDu* inserirNo_ListDu(NoListDu* primeiro, int item)
{
    NoListDu* novoNo = (NoListDu*) malloc(sizeof(NoListDu*));
    novoNo->item = item;
    novoNo->anterior = NULL;
    novoNo->proximo = primeiro;

    if (primeiro == NULL)
    {
        primeiro->anterior = novoNo;
    }

    return novoNo;
}

NoListDu* removerNo_ListDu(NoListDu* primeiro, int item)
{
    NoListDu* atual = primeiro;

    while (atual != NULL && atual->item != item)
    {
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        return primeiro;
    }

    if (primeiro == atual)
    {
        primeiro = atual->proximo;
    }
    else
    {
        atual->anterior->proximo = atual->proximo;
    }

    if (atual->proximo != NULL)
    {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);

    return primeiro;
}

void imprimirListaDuplamenteEncadeada(NoListDu* primeiro)
{
    NoListDu* atual = primeiro;
    printf("[chave][valor]\n");
    while (atual != NULL)
    {
        printf("[%d] <=> ", atual->item);

        atual = atual->proximo;
    }
    printf("NULL\n");
}
