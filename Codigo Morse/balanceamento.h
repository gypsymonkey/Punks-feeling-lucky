#ifndef BALANCEAMENTO_H_INCLUDED
#define BALANCEAMENTO_H_INCLUDED

/**
    Verifica se caractere1 � a contraparte correspondente de caractere2
    (Ex.: "[" � correspondente de "]").
*/
int correspondente(char caractere1, char caractere2);

/**
    Retorna 0 caso os parenteses da entrada n�o estejam balanceados. Retorna algo maior
    que zero no caso contr�rio.
*/
int balanceado(char palavra[]);

#endif // BALANCEAMENTO_H_INCLUDED
