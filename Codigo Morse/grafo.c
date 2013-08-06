#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafo.h"

#define TAMANHO_MAXIMO_G 6

struct listaAdj {
    int item;
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

void addAresta(Grafo* grafo, int verticeX, int verticeY)
{

    ListaAdj* vertice = (ListaAdj*) malloc(sizeof(ListaAdj*));

    vertice->item = verticeY;
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
            printf("->%d", atual->item);

            atual = atual->proximoVertice;
        }

        printf("\n");
    }
}

void desenharGrafo(Grafo* g)
{

    printf("+-------------------+\n");
    printf("|                   |\n");
    printf("|     (1)---(2)     |\n");
    printf("|      |   / |      |\n");
    printf("|      |  /  |      |\n");
    printf("|      | /   |      |\n");
    printf("|     (3)---(4)     |\n");
    printf("|       \\   /       |\n");
    printf("|        (5)        |\n");
    printf("|                   |\n");
    printf("+-------------------+\n");
}
