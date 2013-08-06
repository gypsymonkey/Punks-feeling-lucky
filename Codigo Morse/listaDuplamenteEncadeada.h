#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED

typedef struct noListDu NoListDu;

NoListDu* criarListaDuplamenteEncadeada();

int listaVazia_ListDu(NoListDu* primeiro);

NoListDu* inserirNo_ListDu(NoListDu* primeiro, int item);

NoListDu* removerNo_ListDu(NoListDu* primeiro, int item);

void imprimirListaDuplamenteEncadeada(NoListDu* primeiro);

#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED
