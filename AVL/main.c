#include <stdio.h>
#include "avl.h"

int main(void)
{
     Avl* a = NULL;
     a = avl_insere(a,5);
     a = avl_insere(a,3);
     a = avl_insere(a,8);
     a = avl_insere(a,2);
     a = avl_insere(a,4);
     a = avl_insere(a,7);
     a = avl_insere(a,10);
     a = avl_insere(a,1);
     a = avl_insere(a,6);
     a = avl_insere(a,9);
     a = avl_insere(a,11);

     printf("Arvore apos insercao de 5, 3, 8, 2, 4, 7, 10, 1, 6, 9, 11:\n");
     avl_imprime(a);
     printf("\n");
     avl_testa(a);
     printf("\n");

     a=avl_insere(a,4);
     printf("\nArvore apos mais um 4 (repetido):\n");
     avl_imprime(a);
     printf("\n");
     avl_testa(a);
     printf("\n");

     a=avl_remove(a,4);
     printf("\nArvore apos retirar o 4:\n");
     avl_imprime(a);
     printf("\n");
     avl_testa(a);
     printf("\n");

     a=avl_insere(a,4);
     printf("\nArvore apos re-insercao do 4:\n");
     avl_imprime(a);
     printf("\n");
     avl_testa(a);
     printf("\n");

     a=avl_remove(a,11);
     printf("\nArvore apos retirar o 11:\n");
     avl_imprime(a);
     printf("\n");
     avl_testa(a);
     printf("\n");

     return 0;
}
