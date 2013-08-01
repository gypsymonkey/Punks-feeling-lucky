#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"
//#include "hash.h"

struct no {
    Elemento* item;
    No* proximoNo;
};

struct elemento {
    char* chave;
    char* valor;
};

No* criarLista()
{
    return NULL;
}

int listavazia(No* primeiro)
{
    return (primeiro == NULL);
}

No* inserirNo(No* primeiro, Elemento* item)
{
    No* novoNo = (No*) malloc(sizeof(No*));
    novoNo->item = item;
    novoNo->proximoNo = primeiro;

    return novoNo;
}

No* removerNo(No* primeiro, char* chave)
{
    No* anterior = NULL;
    No* atual = primeiro;

    while (atual != NULL && atual->item->chave != chave)
    {
        anterior = atual;
        atual = atual->proximoNo;
    }

    if (atual == NULL)
    {
        return primeiro;
    }

    if (anterior == NULL)
    {
        primeiro = atual->proximoNo;
    }
    else
    {
        anterior->proximoNo = atual->proximoNo;
    }

    free(atual);

    return primeiro;
}

void imprimirLista(No* primeiro)
{
    No* atual = primeiro;
    printf("[chave][valor]\n");
    while (atual != NULL)
    {
        printf("[%s][%s] => ", atual->item->chave, atual->item->valor);

        atual = atual->proximoNo;
    }
    printf("NULL\n");
}

char* getValor(No* primeiro, char* chave)
{
    No* atual = primeiro;

    while(atual != NULL)
    {
        if (!strcmp(atual->item->chave, chave))
        {
            return atual->item->valor;
        }

        atual = atual->proximoNo;
    }

    return "/b/";
}

Elemento* init_El(char* chave, char* valor)
{
    Elemento* novoElemento = (Elemento*) malloc(sizeof(Elemento));
    novoElemento->chave = chave;
    novoElemento->valor = valor;
    return novoElemento;
}
