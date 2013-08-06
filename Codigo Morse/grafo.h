#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

/**
    Defini��o do tipo ListaAdj contendo quatro elementos: id(int), item(char), visitado(int) e um
    ponteiro para o pr�ximo vertice.
*/
typedef struct listaAdj ListaAdj;

/** Defini��o do tipo Grafo contendo um array de ListaAdj*. */
typedef struct grafo Grafo;

/** Cria um novo grafo. */
Grafo* criarGrafo();

/** Adiciona um novo vertice ao grafo */
void addAresta(Grafo* grafo, int verticeX, int verticeY);

/** Imprime o grafo */
void imprimirGrafo(Grafo* grafo);

/** Desenha o grafo [N�o est� completa] */
void desenharGrafo(Grafo* g);

#endif // GRAFO_H_INCLUDED
