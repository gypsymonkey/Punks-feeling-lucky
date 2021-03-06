#ifndef CODIGOMORSE_H_INCLUDED
#define CODIGOMORSE_H_INCLUDED

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

/** Pega express�es do fluxo de entrada padr�o e verifica se os parenteses est�o balanceados. */
void verBalanceamento();

/** Exibe as mensagens arquivadas, permitindo navegar entre elas */
void mensArquivadas();

/** Desenha a interface */
void interface();

#endif // CODIGOMORSE_H_INCLUDED
