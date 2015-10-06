#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

/*
  Função auxiliar de criação de um novo filho em uma AVL

  @parâmetros:
    -Avl* pai: ponteiro para o pai do novo nó a ser criado
    -chave: valor inteiro a ser inserido no nó criado
*/
Avl* avl_novoFilho(Avl* pai, int chave) {
  Avl* no = (Avl*)malloc(sizeof(Avl));

  no->chave = chave;
  no->pai = pai;
  no->fb = 0;
  no->esq = NULL;
  no->dir = NULL;

  return no;
}

/*
  Função de inserção de um nó em uma AVL com seu valor chave

  @parâmetros:
    -Avl* no: raiz da árvore que deseja fazer a inserção
    -chave: valor inteiro que deseja incluir no nó a ser inserido
*/
Avl* avl_insere(Avl* no, int chave) {
  if(no == NULL) // não há árvore, então a criamos a partir de um novo filho
    return avl_novoFilho(no, chave);

  else if(chave < no->chave) {
    if(no->esq == NULL)
      no->esq = avl_novoFilho(no, chave);
    else
      no->esq = avl_insere(no->esq, chave);
  }

  else if(chave > no->chave) {
    if(no->dir == NULL)
      no->dir = avl_novoFilho(no, chave);
    else
      no->dir = avl_insere(no->dir, chave);
  }
  return no;
}

/*
  Função de remoção de um nó de uma AVL a partir de sua chave

  @parâmetros
    -Avl* no: raiz da árvore que deseja fazer a remoção
    -chave: valor chave do nó que deseja remover
*/
Avl* avl_remove(Avl* no, int chave) {
  Avl* aux = avl_busca(no, chave);
  if(aux == NULL) // nó não encontrado, logo não fazemos a remoção
    return no;

  else if(aux->dir == NULL && aux->esq == NULL) { // nó folha, sem filhos
      if(aux->pai != NULL) {
        if(aux == aux->pai->esq)
          aux->pai->esq = NULL;
        else
          aux->pai->dir = NULL;
      }
      free(aux);
      return no;
  }

  else if(aux->dir != NULL && aux->esq == NULL) {
    if(aux->pai != NULL) {
      if(aux == aux->pai->esq)
        aux->pai->esq = aux->dir;
      else
        aux->pai->dir = aux->dir;
    }
    aux->dir->pai = aux->pai;
    free(aux);
    return no;
  }

  else {
    Avl* sucessor = aux->dir;
    int temp;
    while(sucessor->esq != NULL)
      sucessor = sucessor->esq;
    temp = sucessor->chave;
    no = avl_remove(no, temp);
    aux->chave = temp;
    return no;
  }
}

/*
  Busca recursiva

  @parâmetros
    -Avl* no: raiz da árvore que deseja realizar a busca
    -chave: valor inteiro que deseja buscar na dada árvore
*/
Avl* avl_busca(Avl* no, int chave) {
  if(no == NULL) // árvore vazia, logo não há o que buscar
    return NULL;

  else if(chave < no->chave)
    return avl_busca(no->esq, chave);
  else if(chave > no->chave)
    return avl_busca(no->dir, chave);
  else
    return no;
}

/*
  Função de rotação de uma árvore p/ direita,
  visando o balanceamento da mesma

  @parâmetros
    -Avl* no: nó raiz da árvore a ser rotacioanda
*/
Avl* avl_rodaDireita(Avl* no) {
  Avl* pai = no->pai;
  Avl* aux_esq = no->esq;
  Avl* aux_dir = aux_esq->dir;

  aux_esq->dir = no;
  no->pai = aux_esq;
  no->esq = aux_dir;
  if(aux_dir != NULL)
    aux_dir->pai = no;

  aux_esq->pai = pai;
  if(pai != NULL) {
    if(pai->dir == no)
      pai->dir = aux_esq;
    else
      pai->esq = aux_esq;
  }
  aux_esq->fb = no->fb = 0;
  return aux_esq;
}

/*
  Computa recursivamente a altura
  de uma dada árvore.

  @parâmetros
    -Avl* no: raiz da árvore que deseja fazer o cálculo
*/
int avl_altura(Avl* no) {
  int altura = -1;

  while(no != NULL) {
    altura++;
    if(no->fb < 0)
      no = no->esq;
    else
      no = no->dir;
  }
  return altura;
}

/*
  Testa uma dada árvore AVL checando, para cada nó,
  seus fatores de balanceamento, ordem, se está ou não balanceada,
  e suas alturas.

  @parâmetros
    -Avl* no: nó raiz a da árvore que se deseja fazer o teste
*/
void avl_testa(Avl* no) {
  if(no == NULL) // árvore vazia, logo não há o que testar
    return;

  else {
    int ordem = 1;
    int fb_correto = 1;
    int balanceado = 1;
    int altura_esq = avl_altura(no->esq);
    int altura_dir = avl_altura(no->dir);
    int fb = altura_dir - altura_esq;

    if(no->esq != NULL && no->esq->chave >= no->chave)
      ordem = 0;
    if(no->dir != NULL && no->dir->chave <= no->chave)
      ordem = 0;
    if(fb != no->fb)
      fb_correto = 0;
    if(fb < -1 || fb > 1)
      balanceado = 0;

    printf("No %d, Ordem: %1d, Fator de Balanceamento correto: %1d, Balanceado: %1d, Altura esq: %d, Altura dir: %d\n", no->chave, ordem, fb_correto, balanceado, altura_esq, altura_dir);
    avl_testa(no->esq);
    avl_testa(no->dir);
  }
}

/*
  Função que imprime em uma estrutura linear uma dada árvore AVL

  @parâmetros
    -Avl* no: nó raiz da árvore que se deseja imprimir
*/
void avl_imprime(Avl* no) {
  if(no != NULL) {
    printf("<");
    avl_imprime(no->esq);
    printf("%d ", no->chave);
    avl_imprime(no->dir);
    printf(">");
  }
}
