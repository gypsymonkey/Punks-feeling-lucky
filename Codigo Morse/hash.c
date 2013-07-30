#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaencadeada.h"
#include "hash.h"

#define TAMANHO_MAXIMO_H 11

struct tabelaHash {
    No* tabela[TAMANHO_MAXIMO_H];
};

TabelaHash* criarTabelaHash()
{
    TabelaHash* novaTH = (TabelaHash*) malloc(sizeof(TabelaHash));

    int i;
    for (i = 0; i < TAMANHO_MAXIMO_H; ++i)
    {
        novaTH->tabela[i] = NULL;
    }

    return novaTH;
}

int funcaoHash(char* chave)
{
    int soma = 0;
    int i;

    for (i = 0; i < strlen(chave); ++i)
    {
        soma += chave[i];
    }

    return soma % TAMANHO_MAXIMO_H;
}

void put(TabelaHash* th, char* chave, char* valor)
{
    int h = funcaoHash(chave);

    th->tabela[h] = inserirNo(th->tabela[h], init_El(chave, valor));
}

char* get(TabelaHash *th, char* chave)
{
    int h = funcaoHash(chave);

    return getValor(th->tabela[h], chave);
}

void remover(TabelaHash *th, char* chave)
{
    int h = funcaoHash(chave);

    th->tabela[h] = removerNo(th->tabela[h], chave);
}

void imprimirTabela(TabelaHash* th)
{
    int i;
    for (i = 0; i < TAMANHO_MAXIMO_H; ++i)
    {
        imprimirLista(th->tabela[i]);
    }
}
