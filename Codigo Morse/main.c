/**
    Tradutor de código morse

                    - José Leandro
                    - Wylliam
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "listaencadeada.h"
#include "grafo.h"
#include "codigomorse.h"
#include "arvore.h"

#define ALT 10
#define LAR 20

char* winstonSmith(char* str)   //função temporária com propósito de testes.
{
    int i;
    int size = strlen(str);
    char* vlr = (char*) malloc(size*sizeof(char));
    printf("%d", size);
    for (i = 0; i < size; ++i)
    {
        vlr[i] = str[i] + 2;
        printf("%c", vlr[i]);
    }

    return vlr;
}

char* pegarEntrada()
{
    char* s = (char*) malloc(7*sizeof(char));
    scanf("%7s", s);

    return s;
}

/** TESTES */

void testeHash()
{
    TabelaHash* tab = criarTabelaHash();

    char* e;

    e = pegarEntrada();

    while(e)
    {
        if (!strcmp(e, "s"))
        {
            break;
        }
        system("cls");
        if(!strcmp(get(tab, e), "/b/"))
        {
            put(tab, e, "17");
        }

        imprimirTabela(tab);

        e = pegarEntrada(e);
    }
}

void testeCache()
{
    TabelaHash* cache = criarTabelaHash();
    char* entrada;
    char* valor;

    entrada = pegarEntrada();
    while (strcmp(entrada, "sair"))
    {
        char* aux = get(cache, entrada);
        printf("%s\n", aux);
        if (strcmp(aux, "/b/"))
        {
            printf("Em cache!\n");
            imprimirTabela(cache);
        }
        else
        {
            printf("%s\n", aux);
            printf("Nova Palavra!\n");

            valor = winstonSmith(entrada);
            put(cache, entrada, valor);
            imprimirTabela(cache);
        }

        entrada = pegarEntrada();
    }
}

void testeLista()
{
    Elemento* x = init_El("jose", "esoj");
    Elemento* y = init_El("maria", "airam");
    Elemento* z = init_El("astolfo", "tofalso");

    No* P = criarLista();

    P = inserirNo(P, x);
    P = inserirNo(P, y);
    P = inserirNo(P, z);

    imprimirLista(P);
}

void testeBalanceamento()
{
    char palavra[7];

    scanf("%s", palavra);

    while (strcmp(palavra,"sair"))
    {
        if(balanceado(palavra))
            printf("Balanceados!\n");
        else
            printf("Nao balanceados!\n");

        scanf ("%s", palavra);
    }
}
void testeGrafo()
{
    Grafo* g = criarGrafo();

    addAresta(g, 1, 2);
    addAresta(g, 1, 5);
    addAresta(g, 2, 1);
    addAresta(g, 2, 5);
    addAresta(g, 2, 3);
    addAresta(g, 2, 4);
    addAresta(g, 3, 2);
    addAresta(g, 3, 4);
    addAresta(g, 4, 2);
    addAresta(g, 4, 5);
    addAresta(g, 4, 3);
    addAresta(g, 5, 4);
    addAresta(g, 5, 1);
    addAresta(g, 5, 2);

    imprimirGrafo(g);

    free(g);
}

void testeArvore()
{
    ArvoreBinaria* ab = criarArvoreBinaria('*', NULL, NULL);


    ab = inserirNoAB(ab, 'A', "·-");
    ab = inserirNoAB(ab, 'B', "-···");
    ab = inserirNoAB(ab, 'C', "-·-·");
    ab = inserirNoAB(ab, 'D', "-··");
    ab = inserirNoAB(ab, 'E', "·");
    ab = inserirNoAB(ab, 'F', "··-·");
    ab = inserirNoAB(ab, 'G', "--·");
    ab = inserirNoAB(ab, 'H', "····");
    ab = inserirNoAB(ab, 'I', "··");
    ab = inserirNoAB(ab, 'J', "·---");
    ab = inserirNoAB(ab, 'K', "-·-");
    ab = inserirNoAB(ab, 'L', "·-··");
    ab = inserirNoAB(ab, 'M', "--");
    ab = inserirNoAB(ab, 'N', "-·");
    ab = inserirNoAB(ab, 'O', "---");
    ab = inserirNoAB(ab, 'P', "·--·");
    ab = inserirNoAB(ab, 'Q', "--·-");
    ab = inserirNoAB(ab, 'R', "·-·");
    ab = inserirNoAB(ab, 'S', "···");
    ab = inserirNoAB(ab, 'T', "-");
    ab = inserirNoAB(ab, 'U', "··-");
    ab = inserirNoAB(ab, 'V', "···-");
    ab = inserirNoAB(ab, 'W', "·--");
    ab = inserirNoAB(ab, 'X', "-··-");
    ab = inserirNoAB(ab, 'Y', "-·--");
    ab = inserirNoAB(ab, 'Z', "--··");

    //printf("%c\n", busca(ab, "--.."));
    imprimirEmOrdem(ab);
}

/** MAIN */

int main()
{
    //testeBalanceamento();
    //testeHash();
    //testeLista();
    //testeCache();
    //testeGrafo();    //Não funciona direito
    //testeArvore();
    interface();

    return 0;
}
