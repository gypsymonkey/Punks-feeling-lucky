#ifndef PINHA_H_INCLUDED
#define PINHA_H_INCLUDED

/**  Defini��o do tipo pilha */
typedef struct pilha Pilha;

/**  Cria uma nova pilha vazia. */
Pilha* criarPilha();

/**  Adiciona um novo elemento(item) ao topo da pilha dada como primeiro par�metro.  */
void push(Pilha* pilha, int item);

/**  Verifica se a pilha em quest�o est� vazia   */
int pilhaVazia(Pilha* pilha);

/**  Remove o elemento do topo da pinha  */
int pop(Pilha* pilha);

/**  Retorna o elemento do topo da pilha, sem remove-lo. */
int peek(Pilha* pilha);

/**  Imprime o conteudo da pilha. [N�o implementada]  */
void imprimirPilha(Pilha* pilha);

#endif // PINHA_H_INCLUDED
