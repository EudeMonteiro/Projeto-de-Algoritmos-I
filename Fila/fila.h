//Autor: Eude Monteiro da Hora

#include <stdio.h>
#define MaxSize 8

typedef int TipoApontador;
typedef double TipoChave;

typedef struct tipoItem {
  TipoChave Chave;
}TipoItem;

typedef struct tipoFila {
  TipoItem Item[MaxSize];
  TipoApontador Frente, Tras;
}TipoFila;

void Enqueue(TipoItem x, TipoFila *Fila);
void Dequeue(TipoFila *Fila);
void showQueue(TipoFila *Fila);
int  isEmpty(TipoFila *Fila);
int  isFull(TipoFila *Fila);
void furarFila(TipoFila *Fila, TipoItem *x);
