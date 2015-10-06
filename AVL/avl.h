typedef struct avl {
  int chave;
  int fb; // fator de balanceamento
  struct avl* pai;
  struct avl* esq;
  struct avl* dir;
} Avl;

Avl* avl_novoFilho(Avl* pai, int chave);
Avl* avl_insere(Avl* no, int chave);
Avl* avl_remove(Avl* no, int chave);
Avl* avl_busca(Avl* no, int chave);
Avl* avl_rodaDireita(Avl* no);
int avl_altura(Avl* no);

void avl_testa(Avl* no);
void avl_imprime(Avl* no);
