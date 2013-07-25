#include <string.h>
#include "balanceamento.h"
#include "pilha.h"

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
