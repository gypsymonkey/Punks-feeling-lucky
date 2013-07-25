#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define TAMANHO_MAXIMO 30

struct pilha {
	int tamanho;
	int itens[TAMANHO_MAXIMO];
};

struct pilha* criarPilha()
{
	struct pilha* novaPilha = (struct pilha*) malloc(sizeof(struct pilha));
	novaPilha->tamanho = 0;

	return novaPilha;
}

void push(struct pilha* pilha, int item)
{
    if (pilha->tamanho == TAMANHO_MAXIMO)
    {
        printf ("Pilha cheia!\n");
    } else {
        pilha->itens[pilha->tamanho] = item;
        ++pilha->tamanho;
    }
}

int pilhaVazia(struct pilha* pilha)
{
    return (pilha->tamanho == 0);
}

int pop(struct pilha* pilha)
{
    if (pilhaVazia(pilha))
    {
        //printf ("Pilha vazia!\n");
        return -1;
    } else {
        return pilha->itens[--pilha->tamanho];
    }
}

int peek(struct pilha* pilha)
{
    if (pilhaVazia(pilha))
    {
        //printf ("Pilha vazia!\n");
        return -1;
    } else {
        return pilha->itens[pilha->tamanho - 1];
    }
}

void imprimirPilha(struct pilha* pilha)
{
    /* ... */
}
