#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafo.h"

#define TAMANHO_MAXIMO_G 6
#define ALT 10
#define LAR 20

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

void addAresta(Grafo* grafo, int verticeX, int verticeY, char* item)
{

    ListaAdj* vertice = (ListaAdj*) malloc(sizeof(ListaAdj*));

    vertice->id = verticeY;
    vertice->visitado = 0;
    //vertice->item = item;
    vertice->proximoVertice = grafo->vertices[verticeX];
    grafo->vertices[verticeX] = vertice;
}

void imprimirGrafo(Grafo* grafo)
{
    int i;

    for (i = 0; i < TAMANHO_MAXIMO_G; ++i)
    {
        ListaAdj* atual = grafo->vertices[i];
        printf("[%d]", i);
        while (atual != NULL)
        {
            printf("->%d", atual->id);

            atual = atual->proximoVertice;
        }

        printf("\n");
    }
}

