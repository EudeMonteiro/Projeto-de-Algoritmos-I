#Autor: Eude Monteiro da Hora

#include <stdio.h>
#include <string.h>

int isSegment(char* a, char* b) {

  int Cmp_a = strlen(a);
  int Cmp_b = strlen(b);

  for (int i = 0; i <= Cmp_b - Cmp_a; i++) {
    
    int j; 

    for (j = 0; j < Cmp_a; j++) {
      if (b[i+j] != a[j]) {
        break;
      }
    }
    
    if (j == Cmp_a){
      return i;
    }
  }
  return -1; 
}

int contarOcorrencia(char* a, char* b)
{
  int Cmp_a = strlen(a);
  int Cmp_b = strlen(b);
  int ctr = 0;
  
  for (int i = 0; i <= Cmp_b - Cmp_a; i++) {
  
    int j;
    for (j = 0; j < Cmp_a; j++) {
      if (b[i+j] != a[j]) {
        break;
      }
    }
    
    if (j == Cmp_a) {
      ctr++;
      j = 0;
    }
  }
  
  return ctr;
}

int main() {
  char s[] = "ab";
  char t[] = "abcdabcd";
  
  if(isSegment(s, t) == 0) {
    printf("%s é segmento de %s. \n", s, t);
  }
  
  else {
    printf("%s não é segmento de %s. \n", s, t);
  }
    
  int rst = contarOcorrencia(s, t);
  printf("Número de ocorrências de %s em %s: %i", s, t, rst);

  return 0;
}
