#ifndef CODIGOMORSE_H_INCLUDED
#define CODIGOMORSE_H_INCLUDED

/**
    Verifica se caractere1 é a contraparte correspondente de caractere2
    (Ex.: "[" é correspondente de "]").
*/
int correspondente(char caractere1, char caractere2);

/**
    Retorna 0 caso os parenteses da entrada não estejam balanceados. Retorna algo maior
    que zero no caso contrário.
*/
int balanceado(char palavra[]);

/** Pega expressões do fluxo de entrada padrão e verifica se os parenteses estão balanceados. */
void verBalanceamento();

/** Exibe as mensagens arquivadas, permitindo navegar entre elas */
void mensArquivadas();

/** Desenha a interface */
void interface();

#endif // CODIGOMORSE_H_INCLUDED
