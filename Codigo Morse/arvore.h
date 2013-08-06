#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct arvoreBinaria ArvoreBinaria;

ArvoreBinaria* criarArvoreBinariaVazia();

ArvoreBinaria* criarArvoreBinaria(char valor, ArvoreBinaria* esquerda, ArvoreBinaria* direita);

int arvoreVazia(ArvoreBinaria* ab);

ArvoreBinaria* inserirNoAB(ArvoreBinaria* ab, char valor, char* morse);

void imprimirEmOrdem(ArvoreBinaria* ab);

char busca(ArvoreBinaria* ab, char* morse);

#endif // ARVORE_H_INCLUDED
