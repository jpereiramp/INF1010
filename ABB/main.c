#include <stdio.h>
#include "abb.h"

int main(void) {
  Abb* a;
  Abb* aux;
  Abb* raiz;
  int aux_inteiro;
  a = aux = raiz = NULL;
  a = abb_insere(a, 7);
  a = abb_insere(a, 4);
  a = abb_insere(a, 9);
  a = abb_insere(a, 2);
  a = abb_insere(a, 5);
  a = abb_insere(a, 6);
  a = abb_insere(a, 1);
  a = abb_insere(a, 8);
  a = abb_insere(a, 3);
  a = abb_insere(a, 10);
  raiz = abb_busca(a, 7);

  aux = abb_minimo(raiz);
  printf("Minimo: %d\n", aux->chave);
  aux = abb_maximo(raiz);
  printf("Maximo: %d\n", aux->chave);
  aux = abb_sucessor(raiz);
  printf("Sucessor: %d\n", aux->chave);
  aux = abb_antecessor(raiz);
  printf("Antecessor: %d\n", aux->chave);
  aux = abb_busca(a, 10);
  printf("Busca (10): %d\n", aux->chave);

  aux_inteiro = abb_altura(raiz);
  printf("Altura: %d\n", aux_inteiro);
  aux_inteiro = abb_qtdNos(raiz);
  printf("Qtd nos: %d\n", aux_inteiro);
  aux_inteiro = abb_largura(raiz);
  printf("Largura: %d\n", aux_inteiro);
  aux_inteiro = abb_densidade(raiz);
  printf("Densidade %d\n", aux_inteiro);

  return 0;
}
