/**
    Tradutor de código morse

                    - José Leandro
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "listaencadeada.h"

char* winstonSmith(char str[])   //função temporária.
{
    int i;
    for (i = 0; i < strlen(str); ++i)
    {
        str[i] += 5;
    }

    return str;
}

void testeHash()
{
    TabelaHash* tab = criarTabelaHash();

    put(tab, "jose", "esoj");
    //remover(tab, "jose");
    printf("%s\n", get(tab, "jose"));
    //imprimirTabela(tab);
}

void testeLista()
{
    Elemento* x = init_El("jose", "esoj");
    Elemento* y = init_El("maria", "airam");

    No* P = criarLista();

    P = inserirNo(P, x);
    P = inserirNo(P, y);

    imprimirLista(P);
}

int main()
{
    //testeHash();
    //testeLista();

    return 0;
}
