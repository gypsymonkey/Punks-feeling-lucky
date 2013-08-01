#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

/**
    Definição do tipo ListaAdj contendo quatro elementos: id(int, )item(char), visitado(int) e um
    ponteiro para o próximo vertice.
*/
typedef struct listaAdj ListaAdj;

/** Definição do tipo Grafo contendo um array de ListaAdj*. */
typedef struct grafo Grafo;

/** Cria um novo grafo. */
Grafo* criarGrafo();

/** Adiciona um novo vertice ao grafo */
void addVertice(Grafo* grafo, int verticeX, int verticeY, char* item);

#endif // GRAFO_H_INCLUDED
