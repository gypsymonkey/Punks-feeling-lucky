/**
    Tradutor de código morse

                    - José Leandro
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "listaencadeada.h"

char* winstonSmith(char* str, char* vlr)   //função temporária.
{
    int i;
    int size = strlen(str);
    for (i = 0; i < size; ++i)
    {
        vlr[i] = str[i] + 5;
    }

    return vlr;
}

char* entrada(char* s)
{
    s = (char*) malloc(7*sizeof(char));
    scanf("%7s", s);

    return s;
}

void testeHash()
{
    TabelaHash* tab = criarTabelaHash();

    char* e;
    //char e2[7];

    //put(tab, "7", "17");
    //scanf("%s", entrada);//, entrada2);
    e = entrada(e);

    //printf("%s: %d\n%s: %d", entrada, funcaoHash(entrada), entrada2, funcaoHash(entrada2));
    while(e)
    {
        if (!strcmp(e, "s"))
        {
            break;
        }
        system("cls");
        put(tab, e, "17");
        imprimirTabela(tab);

        e = entrada(e);
    }

    //remover(tab, "jose");
    //printf("%s\n", get(tab, "jose"));
}

void testeCache()
{
    TabelaHash* cache = criarTabelaHash();
    char entrada[7];
    char valor[7] = "bump";

    scanf("%s", entrada);
    while (entrada)
    {
        char* aux = get(cache, entrada);
        if (strcmp(aux, "/b/"))
        {
            printf("Em cache!\n");
            imprimirTabela(cache);
        }
        else
        {
            printf("Nova Palavra!\n");
            winstonSmith(entrada, valor);
            put(cache, entrada, valor);
            imprimirTabela(cache);
        }

        scanf("%s", entrada);
    }
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

int main()
{
    //testeBalanceamento();
    testeHash();
    //testeLista();
    //testeCache();
    return 0;
}
