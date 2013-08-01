#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafo.h"

#define TAMANHO_MAXIMO_G 11

struct listaAdj {
    int id;
    char* item;
    int* visitado;
    ListaAdj* proximoVertice;
};

struct grafo {
    ListaAdj* vertices[TAMANHO_MAXIMO_G];
};

Grafo* criarGrafo()
{
    Grafo* novoGrafo = (Grafo*) malloc(sizeof(Grafo));
    int i;

    for (i = 0; i < TAMANHO_MAXIMO_G; ++i)
    {
        novoGrafo->vertices[i] = NULL;
    }

    return novoGrafo;
}

void addVertice(Grafo* grafo, int verticeX, int verticeY, char* item)
{
    ListaAdj* vertice = (ListaAdj*) malloc(sizeof(ListaAdj*));

    vertice->id = verticeY;
    strcpy(vertice->item, item);
    vertice->proximoVertice = grafo->vertices[verticeX];

    grafo->vertices[verticeX] = vertice;
}

