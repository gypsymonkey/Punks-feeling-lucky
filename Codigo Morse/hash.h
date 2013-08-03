#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

/**  Definição do tipo TabelaHash formado por um array de listas encadeadas. */
typedef struct tabelaHash TabelaHash;

/**  Cria uma nova tabela hash   */
TabelaHash* criarTabelaHash();

/**  [Soma dos codigos ascii dos caracteres] mod [Tamanho máximo da hashtable]   */
int funcaoHash(char* chave);

/**  Insere um elemento na tabela hash   */
void put(TabelaHash* th, char* chave, char* valor);

/**  Obtém o valor de um elemento dada sua chave */
char* get(TabelaHash *th, char* chave);

/**  Remove algum elemento a partir de sua chave */
void remover(TabelaHash *th, char* chave);

/**  Imprime toda a tabela hash. */
void imprimirTabela(TabelaHash* th);

#endif // HASH_H_INCLUDED
