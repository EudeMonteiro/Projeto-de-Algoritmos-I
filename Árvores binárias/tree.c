//Autor: Eude Monteiro da Hora

#include <stdio.h>
#include <math.h>
#include "tree.h"

//Geração da árvore binária
Tree *generate_Tree(int k) {
  Tree *newTree;
  newTree = (struct Tree*)malloc(sizeof(Tree));
  newTree -> left = NULL;
  newTree -> right = NULL;
  newTree -> key = k;
  return newTree;
}

//a) Inserção dos elementos na árvore binária
void insertElement(Tree *T, int k) {
  
  if(k < (T -> key)) {
    if(T -> left) {
      insertElement(T -> left, k);
    }
    
    else {
      struct Tree *newTree = generate_Tree(k);      
      T -> left = newTree;      
    }  
  }

  else {
    if (k > (T -> key)) {
      if(T -> right) {
        insertElement(T -> right, k);
      }
      
      else {
        struct Tree *newTree = generate_Tree(k);
        newTree -> key = k;
        T -> right = newTree;
      }
    }
    
    else {
      printf("O elemento %i já existe na árvore!\n", k);   
    } 
  }
}

//b) Remoção dos elementos na árvore binária
Tree *removeElement(Tree *T, int k) {
  
  // Caso Base
  if (T == NULL) {
    return T;
  }
  
  if (k < T -> key){
    T -> left = removeElement(T -> left, k);
  }
  
  else if (k > T -> key) {
    T -> right = removeElement(T -> right, k);
  }
  
  else { // Casos I e II: O nó tem 0 filhos ou apenas 1
   
    if (T->left == NULL) {
      Tree* aux = T -> right;
      return aux;
    }

    else if (T->right == NULL) {
      Tree* aux = T->left;
      return aux;
    }

    else { //Caso III: O nó tem 2 filhos
      Tree *currentTree = T -> right;
      while(currentTree && currentTree -> left != NULL){
        currentTree = currentTree -> left;
      }

      T -> key = currentTree -> key;
      T -> right = removeElement(T -> right, currentTree -> key);
    }
  }
  
  return T;
}

//c) Busca por um determinado elemento na árvore binária
Tree *searchElement(Tree *T, int k) {
  printf("Caminhando pelos elementos: ");
	
  while(T -> key != k){	
    if(T != NULL) {
      printf("%d ",T->key);
			
      if(T->key > k){
        T = T->left;
      }
    
      else {                
        T = T->right;
      }
			
      if(T == NULL){
        return NULL;
      }
    }			
  }
  return T;
}

//d) Apresentação dos valores em ordem dos elementos da árvore 
void printElementsInOrder(Tree *T) {
  if (T != NULL) {
    printElementsInOrder(T -> left);
    printf("%d ", T -> key);
    printElementsInOrder(T -> right);
  }
}



//--- Implementações Extras ---//


//Número de nós com dois filhos
int Nodes_with_Two_Childs(Tree *T){
  if(T == NULL){
    return 0;
  }  
  
  if(T -> right == NULL || T -> left == NULL) {
    return Nodes_with_Two_Childs(T -> right) + Nodes_with_Two_Childs(T -> left);
  }

  else{
    return 1 + Nodes_with_Two_Childs(T -> right) + Nodes_with_Two_Childs(T -> left);
  }  
}

//Número de folhas na árvore
int number_of_leaves(Tree* T){
  if(T == NULL){
    return 0;
  }  
  
  if(T -> right == NULL && T -> left == NULL) {
    return 1;
  }

  else{
    return number_of_leaves(T -> right) + number_of_leaves(T -> left);
  } 
}

//Valores máximos e mínimos da árvore
void MaxMinValues(Tree *T){
  Tree *T_ = T;
  Tree *Min = T_;
  Tree *Max = T;
    
  while(Min && Min -> left != NULL){
    Min = Min -> left;
  }

  while (Max && Max -> right != NULL){
    Max = Max -> right;
  }

  printf("\nValor máximo da árvore: %i \n"
  "Valor mínimo da árvore: %i", Max -> key, Min -> key);
}

//Altura da árvore
int treeHeight(Tree *T){
  if(T == NULL){
    return 0;
  }

  int leftHeight  = treeHeight(T -> left);
  int rightHeight = treeHeight(T -> right);

  if (leftHeight > rightHeight) {
    return leftHeight + 1 ;
  }
  
  else {
    return rightHeight + 1;
  }
}

void currentLevel(struct Tree* T, int level, int spc){
   
  if (T == NULL){
    for(int i = 0; i < 2*spc; i++) {printf(" ");} 
    return;
  }
  
  if (level == 1){
    
    for(int k = 0; k < spc; k++) {printf(" ");}
    printf("%03d", T -> key); //Formatação dos valores para três dígitos
    for(int m = 0; m < (spc - 3); m++) {printf(" ");}
  }
  
  else if (level > 1)
  {
    currentLevel(T->left, level - 1, floor(spc/2)); 
    currentLevel(T->right, level - 1, floor(spc/2));            
  }
}

// IMPORTANTE: A função abaixo printa o diagrama da árvore, o que pode
// fazer com que ele ultrapasse os limites da aba do console e não mostre
// o diagrama corretamente. Se isto acontecer, tente alternativas como 
// diminuir o tamanho da fonte da IDE e reduzir o tamanho da janela do 
// navegador que você está utilizando ((ctrl -) no Chrome) até o diagrama 
// caber corretamente; ou ainda, se você estiver utilizando o replit, 
// mude o layout de "side by side" para "stacked" nas configurações, oculte
// a aba "Files" que fica no lado esquerdo da tela e reduza o tamanho da
// tela do navegador como mencionado acima.


void printTree(struct Tree* T){ //printTree() chama currentLevel()
  int h = treeHeight(T), i;     //mas separando os valores da árvore em linhas
  for (i=1; i<=h+1; i++){       //conforme os níveis
  
    if(h <= 4) { //Checagem da altura da árvore para melhor visualização do diagrama
      currentLevel(T, i, pow(2, h+1));      
    }
    
    else {
      currentLevel(T, i, pow(2, h));         
    }
    
    printf("\n\n"); 
  }
}
