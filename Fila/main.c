//Autor: Eude Monteiro da Hora

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
  
  TipoFila *Fila = (TipoFila*) malloc(sizeof(TipoFila));
  TipoItem *Item = (TipoItem*) malloc(sizeof(TipoItem));

  Fila -> Frente = 0;
  Fila -> Tras = 0;
  
  Dequeue(Fila);
  printf("Vazia?: %i\n", isEmpty(Fila));
  
  Item -> Chave = 0;
  
  for(int i = 0; i < MaxSize; i++){
    Enqueue(*Item, Fila);
    Item -> Chave = Item -> Chave + 10;    
  }

  showQueue(Fila);

  Dequeue(Fila);
  showQueue(Fila);

  Dequeue(Fila);

  showQueue(Fila);

  printf("\nVazia?: %i\n", isEmpty(Fila));

  Item -> Chave = 45;
  Enqueue(*Item, Fila);

  Item -> Chave = 3123;
  Enqueue(*Item, Fila);

  Item -> Chave = 4002;
  Enqueue(*Item, Fila);

  printf("\nA fila está cheia?: %i\n",isFull(Fila));
  showQueue(Fila);

  Item -> Chave = 7777;
  furarFila(Fila, Item);

  Dequeue(Fila);
  furarFila(Fila, Item);

  showQueue(Fila);

  return 0;
}
