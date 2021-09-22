//Autor: Eude Monteiro da Hora

#include <stdlib.h>

typedef struct Tree {
  struct Tree *left, *right;
  int    key;
} Tree;

Tree *generate_Tree();

//Implementações obrigatórias
void insertElement(Tree *T, int k);
Tree *removeElement(Tree *T, int k);
Tree *searchElement(Tree *T, int k);
void printElementsInOrder(Tree *T);


//Implementações extras
int  Nodes_with_Two_Childs(Tree *T);
int  number_of_leaves(Tree* T);
int  treeHeight(Tree * T);
void MaxMinValues(Tree *T);
void printTree(Tree *T);
