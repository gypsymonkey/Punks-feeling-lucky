#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"

struct arvoreBinaria {
    char valor;
    ArvoreBinaria* esquerda;
    ArvoreBinaria* direita;
};

ArvoreBinaria* criarArvoreBinariaVazia()
{
    return NULL;
}

ArvoreBinaria* criarArvoreBinaria(char valor, ArvoreBinaria* esquerda, ArvoreBinaria* direita)
{
    ArvoreBinaria* ab = (ArvoreBinaria*) malloc(sizeof(ArvoreBinaria));

    ab->valor = valor;
    ab->esquerda = esquerda;
    ab->direita = direita;

    return ab;
}

int arvoreVazia(ArvoreBinaria* ab)
{
	return (ab == NULL);
}

int temFolhaEsquerda(ArvoreBinaria* ab)
{
    return (ab->esquerda != NULL);
}

int temFolhaDireira(ArvoreBinaria* ab)
{
    return (ab->direita != NULL);
}

ArvoreBinaria* inserirNoAB(ArvoreBinaria* ab, char valor, char* morse)
{
    int i;
    int tamanho = strlen(morse);
    char subString;
    ArvoreBinaria* aux = ab;

    for (i = 0; i < tamanho; ++i)
    {
        subString = morse[i];

        if(subString == '-')
        {
            if(temFolhaEsquerda(aux))
            {
                aux = aux->esquerda;
            }
            else
            {
                aux->esquerda = criarArvoreBinaria('#', NULL, NULL);
                aux = aux->esquerda;
            }
        }
        else
        {
            if(temFolhaDireira(aux))
            {
                aux = aux->direita;
            }
            else
            {
                aux->direita = criarArvoreBinaria('#', NULL, NULL);
                aux = aux->direita;
            }
        }
    }

    aux->valor = valor;

    return ab;
}

void imprimirEmOrdem(ArvoreBinaria* ab)
{
    //, ab->valor);
    if(!arvoreVazia(ab))
    {
        //printf("hey\n");

        imprimirEmOrdem(ab->esquerda);
        printf("[%c]\n", ab->valor);
        imprimirEmOrdem(ab->direita);
    }
}

char busca(ArvoreBinaria* ab, char* morse)
{
    int i;
    int tamanho = strlen(morse);
    ArvoreBinaria* atual = ab;
    //printf("%c", ab->esquerda->valor);
    for (i = 0; i < tamanho; ++i)
    {
        if(morse[i] == '-')
        {
            //printf("Hey listen\n");
            atual = atual->esquerda;
        }
        else if(morse[i] == '.')
        {
            atual = atual->direita;
        }
    }
    //printf("ahauahsk\n");

    return atual->valor;
}
