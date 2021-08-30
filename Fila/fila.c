//Autor: Eude Monteiro da Hora

#include <stdio.h>
#include "fila.h"

int isFull(TipoFila *Fila){
  
  if ((Fila -> Tras + 1) % MaxSize == Fila -> Frente){    
    return 1;
  } 
  return 0;
}

int isEmpty(TipoFila *Fila){
  return (Fila -> Frente == Fila -> Tras); 
}

void Enqueue(TipoItem x, TipoFila *Fila){
  if (isFull(Fila)){
    printf("\nA fila está cheia!\n");
  }

  else {
    Fila -> Item[Fila -> Tras] = x;
    Fila -> Tras = (Fila -> Tras + 1) % MaxSize;
    printf("\nO item %.2f foi inserido na fila", x.Chave);
  }   
}

void Dequeue(TipoFila *Fila) {
  TipoItem DequeuedItem;
  
  if (isEmpty(Fila)){
    printf("\nA fila está vazia\n");
  }

  else {
    int index = Fila -> Frente;
    Fila->Frente = (Fila -> Frente + 1) % MaxSize;
    printf("\nO item %.2f foi removido da fila\n", Fila -> Item[index].Chave);
  } 
}

void showQueue(TipoFila *Fila){
  
  int i;
  if (isEmpty(Fila)){
    printf("\nFila Vazia\n");
  }

  else {
    printf("\nFrente -> %d ", Fila -> Frente);
    printf("\nFila   -> [ ");
    for (i = Fila -> Frente; i != Fila -> Tras; i = (i + 1) % MaxSize) {
      printf("%.2f ", Fila -> Item[i].Chave);
    }
    
    printf("]");
    printf("\nTras   -> %d \n", Fila -> Tras);
  }
}

void furarFila(TipoFila *Fila, TipoItem *x){
  
  if(isFull(Fila)) {
    printf("\nA fila está cheia! Não é possível a furar\n");
  }

  else{
    Fila -> Frente = (Fila -> Frente - 1) % MaxSize;
    Fila -> Item[Fila -> Frente] = *x;
    printf("\nO item %.2f furou a fila e foi inserido na frente!\n", Fila -> Item[Fila -> Frente].Chave);
  }  
}
