//Autor: Eude Monteiro da Hora

#include <stdio.h>
#define MaxTam 1000

//Especificação das estruturas e funções

typedef int  TipoApontador;
typedef char TipoChave;

typedef struct tipoItem{
  TipoChave Chave;
} TipoItem;

typedef struct tipoPilha {
  TipoItem Item[MaxTam];
  TipoApontador Topo;

}TipoPilha;

void FPVazia(TipoPilha *Pilha);
int Vazia(TipoPilha *Pilha);
void Empilha(TipoItem x, TipoPilha *Pilha);
TipoItem Desempilha(TipoPilha *Pilha);
int Tamanho(TipoPilha *Pilha);
