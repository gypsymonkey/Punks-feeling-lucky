#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

/**  Definição do tipo No, formado por um Elemento* (item) e um ponteiro para o nó seguinte.  */
typedef struct no No;

/**  Definição do tipo Elemento, formado por duas cadeias de caracteres (chave e valor).*/
typedef struct elemento Elemento;

/**  Cria uma lista encadeada vazia.  */
No* criarLista();

/**  Verifica se a lista está vazia.  */
int listavazia(No* primeiro);

/**  Insere um novo elemento na lista (Este passa a ser o primeiro). */
No* inserirNo(No* primeiro, Elemento* item);

/**  Remove algum item da lista.  */
No* removerNo(No* primeiro, char* item);

/**  Imprime alguma determinada lista.   */
void imprimirLista(No* primeiro);

/**  Retorna o valor de algum item a partir de sua chave */
char* getValor(No* primeiro, char* chave);

/**  Inicializa algum elemento atribuindo-o uma chave e um valor.    */
Elemento* init_El(char* chave, char* valor);

#endif // LISTAENCADEADA_H_INCLUDED
