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

char* winstonSmith(char* str)   //função temporária.
{
    int i;
    int size = strlen(str);
    char* vlr = (char*) malloc(size*sizeof(char));
    printf("%d", size);
    for (i = 0; i < size; ++i)
    {
        //printf("Hey listen!\n");
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

void testeHash()
{
    TabelaHash* tab = criarTabelaHash();

    char* e;
    //char e2[7];

    //put(tab, "7", "17");
    //scanf("%s", entrada);//, entrada2);

    e = pegarEntrada();

    //printf("%s: %d\n%s: %d", entrada, funcaoHash(entrada), entrada2, funcaoHash(entrada2));
    while(e)
    {
        if (!strcmp(e, "s"))
        {
            break;
        }
        system("cls");
        //printf("Hey listen!\n");

        //printf("%s", get(tab, e));
        if(!strcmp(get(tab, e), "/b/"))
        {
            put(tab, e, "17");
        }
        //printf("Hey listen!\n");
        imprimirTabela(tab);

        //printf("%s\n", get(tab, e));

        e = pegarEntrada(e);
    }

    //remover(tab, "jose");
    //printf("%s\n", get(tab, "jose"));
}

void testeCache()
{
    TabelaHash* cache = criarTabelaHash();
    char* entrada;
    char* valor;

    entrada = pegarEntrada(entrada);
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
            //printf("%s\n", valor);
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
    //testeHash();
    //testeLista();
    testeCache();
    return 0;
}
