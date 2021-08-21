//Autor: Eude Monteiro da Hora

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"


int main(void) {
  
  //Divisão das palavras da frase

  char str[100];
  char palavras[50][50];
  int  IndCtr = 0;
  int  IndPalavras = 0;
  int  totalPalavras = 0;

  //Entrada da string
  printf("Digite a string: ");
  fgets(str, sizeof(str), stdin);
  str[strlen(str)-1] = '\0'; //Remoção do caractere '\n'

  printf("\nString Original: %s", str);


  //Transformação das letras maiúsculas em minúsculas

  for(int y = 0; y < strlen(str); y++) {

    if(str[y] >= 'A' && str [y] <= 'Z') {
      str[y] = str[y] + 'a' - 'A';      
    }    
  }

  //Separação das palavras da string

  for(IndCtr = 0; IndCtr <= strlen(str); IndCtr++) {
    
    if(str[IndCtr] == ' ' || str[IndCtr] == '\0') {      
      palavras[totalPalavras][IndPalavras] = '\0'; 
      totalPalavras++;     
      IndPalavras = 0;
    }

    else {
      palavras[totalPalavras][IndPalavras] = str[IndCtr];
      IndPalavras++;
    }
  }

  
  //Inversão das palavras utilizando o tipo Pilha

  TipoPilha* Pilha = (TipoPilha*) malloc(sizeof(TipoPilha));
  TipoItem *Item   = (TipoItem*)  malloc(sizeof(TipoItem));
  
  printf("\nString Nova: " );

  for (int x = 0; x < totalPalavras; x++) {
    for (int i = 0; i < strlen(palavras[x]); i++) {
      Item -> Chave = palavras[x][i];
      Empilha(*Item, Pilha);
    }

    for (int i = 0; i < strlen(palavras[x]); i++) {
      palavras[x][i] = Desempilha(Pilha).Chave;    
    } 
    
    printf("%s ", palavras[x]);
  }
  return 0;
}
