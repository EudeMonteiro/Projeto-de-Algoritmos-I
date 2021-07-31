//Autor: Eude Monteiro da Hora

#include <stdio.h>
#include <string.h>

int Palindromo(char str[])
{
  int x = 0;
  int y = strlen(str) - 1;
  int rt = 0;

  while (y > x)
  {
    if (str[x++] != str[y--])
    {
      return rt;
    }
  }
  rt++;
  return rt;
}

int main() {
  
  int k;
  char palavras[][100] = {
    "1132311",
    "abbcdcbba",
    "projeto",
    "algoritmo",
    "arara",
    ""
  };

  for (k=0; palavras[k][0];k++) {
    printf("%s", palavras[k]);
    if (Palindromo(palavras[k])){
      printf(" é palindromo. \n");
    }

    else {
      printf(" não é palíndromo. \n");
    }
  }
  return 0;
}
