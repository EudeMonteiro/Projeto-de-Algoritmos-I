//Autor: Eude Monteiro da Hora

#include <stdio.h>
#include <string.h>
#include "tree.h"

int main(void){
  
  int keyToSearch;
  struct Tree *T = NULL;  
  int values[] = {86, 11, 7, 35, 170, 2, 120, 21, 88, 152, 31, 12, 181, 28, 134, 70, 1, 85, 25, 77, 10, 128, 198};

  //Caso queira testar o código com valores diferentes, você também pode
  //utilizar os exemplos de conjuntos de valores abaixo, os substituindo 
  //na variável values[] acima:

  //{86, 11, 7, 35, 170, 2, 120, 21, 88, 152, 31, 12, 181, 28, 134, 70, 1, 85, 25, 77, 10, 128, 198}; <- Cópia dos valores originais da questão
  //{8, 3, 10, 1, 6, 14, 4, 7, 13};
  //{8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15}; <- Árvore binária de pesquisa perfeita
  
  for(int i = 0; i < sizeof(values)/sizeof(int); i++){
    if (T == NULL){
      if (values[i] < 0 || values[i] > 999){ //Validação dos valores inseridos 
        printf("Valor inválido inserido. "); //Utilizada para preservar a formatação de printTree()
        return -1;
      }
      
      else{
        T = generate_Tree(values[0]);
      }
    }
    
    else if (values[i] < 0 || values[i] > 999){
      printf("Valor inválido inserido. ");
      return -1;
    }
    
    else{
      insertElement(T, values[i]);
    }
  }

  printf("\nElementos da árvore em ordem crescente: ");
  printElementsInOrder(T);
  printf("\n\nInsira o elemento a ser pesquisado na árvore binária: ");
  scanf("%i", &keyToSearch);
  
  if(searchElement(T, keyToSearch)) {
    printf("\nO elemento %i foi encontrado na árvore.\n", keyToSearch);
  }

  else {
    printf("\nO elemento %i não foi encontrado na árvore.\n", keyToSearch);
  }

  MaxMinValues(T);  
  printf("\n\nNúmero de nós com dois filhos: %d", Nodes_with_Two_Childs(T));
  printf("\nNúmero de folhas: %i", number_of_leaves(T));
  printf("\nNúmero de níveis: %i", treeHeight(T));  
  printf("\nEstrutura da árvore binária: \n\n");
  printTree(T);

  //Demonstração de inserção e remoção de elementos
  
  //Inserção
  printf("Digite um elemento para ser inserido: ");
  int x, z; 
  char y, w;
  
  scanf("%i", &x);
  insertElement(T, x);
  printf("Deseja imprimir o diagrama da árvore? (S/N): ");
  while(1){
    scanf(" %c", &y);
    if(y == 's' || y == 'S'){
      printf("\n");
      printTree(T);
      break;
    }
    
    else if(y == 'n' || y == 'N') {break;}
    
    else{
      printf("Opção inserida inválida. Tente novamente: ");
    }
  }
  
  //Remoção
  printf("Digite um elemento para ser removido: ");
  scanf("%i", &z);
  removeElement(T, z);
  printf("Deseja imprimir o diagrama da árvore? (S/N): ");
  while(1){
    scanf(" %c", &w);
    if(w == 's' || w == 'S'){
      printf("\n");
      printTree(T);
      break;
    }
    
    else if(w == 'n' || w == 'N') {break;}
    
    else{
      printf("Opção inserida inválida. Tente novamente: ");
    }
  }

  return 0;
}
