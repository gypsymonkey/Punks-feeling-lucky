#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codigomorse.h"
#include "pilha.h"
#include "grafo.h"
#include "hash.h"
#include "arvore.h"

int correspondente(char caractere1, char caractere2)
{
    if (caractere1 == '(' && caractere2 == ')')
        return 1;
    if (caractere1 == '[' && caractere2 == ']')
        return 1;
    if (caractere1 == '{' && caractere2 == '}')
        return 1;
    else
        return 0;
}

int balanceado(char palavra[])
{
    int i;
    int tamanho_p = strlen(palavra);
    Pilha* pilha = criarPilha();

    for (i = 0; i < tamanho_p; ++i)
    {
        if (palavra[i] == '(' || palavra[i] == '[' || palavra[i] == '{' )
            push(pilha, palavra[i]);

        if (palavra[i] == ')' || palavra[i] == ']' || palavra[i] == '}')
        {
            if(correspondente(peek(pilha), palavra[i]))
                pop(pilha);
            else
                return 0;
        }
    }

    return pilhaVazia(pilha);
}

void verBalanceamento()
{
    char palavra[7];

    system("cls");
    printf("Digite uma expressao (ou v para voltar ao menu)\n\n");
    printf(">");
    scanf("%s", palavra);

    while (strcmp(palavra,"v"))
    {
        if(balanceado(palavra))
            printf("Balanceados!\n");
        else
            printf("Nao balanceados!\n");

        printf(">");
        scanf ("%s", palavra);
    }
}

void mensArquivadas()
{
    /* ... */
}

int verDicionario(TabelaHash* dicionario, char* morse)
{
    return (!strcmp(get(dicionario, morse), "/b/"));
}

void decodificar(ArvoreBinaria* ab, TabelaHash* dicionario)
{
    system("cls");
    printf("Digite uma mensagem em codigo morse ('.-.-.' representa o fim da mensagem):\n>");

    char morse[7];
    char palavra[100];
    int i = 0;

    scanf("%s", morse);

    while (strcmp(morse, ".-.-.") || i == 100)
    {
        palavra[i] =  busca(ab, morse);
        ++i;

        scanf("%s", morse);
    }
    palavra[i] = '\0';

    printf("%s\n", palavra);

    getch();
}

ArvoreBinaria* inicializarArvore()
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

    return ab;
    //strcpy(mensagem, "3 ... --- ...");

    //printf("%s", decodificar(ab, entrada));
    //printf("%c\n", busca(ab, "--.."));
    //imprimirEmOrdem(ab);
}

void interface()
{
    int entrada = 1;

    ArvoreBinaria* ab = inicializarArvore();
    TabelaHash* dicionario = criarTabelaHash();

    while (entrada != 0)
    {
        system("cls");

        printf("Codigo Morse\n\n");
        printf("1 - Decodificar\n");
        printf("2 - Verificar balanceamento\n");
        printf("3 - Mensagens arquivadas\n\n");
        printf("0 - Sair\n\n>");

        scanf("%d", &entrada);
        switch (entrada)
        {
            case 1:
                decodificar(ab, dicionario);
                break;
            case 2:
                verBalanceamento();
                break;
            case 4:
                /* ... */
                break;
            default:
                break;

        }
    }
}



