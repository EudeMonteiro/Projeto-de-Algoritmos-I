//Autor: Eude Monteiro da Hora

#include <stdio.h>
#include "pilha.h"

// Implementação das funções
// **Apenas as funções Empilha e Desempilha são
//   utilizadas para o exercício**

void FPVazia(TipoPilha *Pilha) {
  Pilha -> Topo = 0;
}

int Vazia(TipoPilha *Pilha) {
  return (Pilha -> Topo == 0);
}

void Empilha(TipoItem x, TipoPilha *Pilha) {
  
  if (Pilha -> Topo == MaxTam) {
    printf("A pilha está cheia");
  }
  
  else {
    Pilha -> Item[Pilha -> Topo] = x;
    Pilha -> Topo++;
  }
}

TipoItem Desempilha(TipoPilha *Pilha) {
  
  if (Vazia(Pilha)) {
    printf("A pilha está vazia");
  }
  
  else {
    Pilha -> Topo--;
  }
  
  return Pilha -> Item[Pilha -> Topo];
}

int Tamanho(TipoPilha *Pilha) {
  return Pilha -> Topo;    
}
