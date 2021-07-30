//Autor: Eude Monteiro da Hora

#include <stdio.h>
#include <string.h>

void Palindromo(char str[])
{
  int x = 0;
  int y = strlen(str) - 1;

  while (y > x)
  {
    if (str[x++] != str[y--])
    {
      printf("%s não é um palíndromo.\n", str);
      return;
    }
  }
  printf("%s é um palíndromo. \n", str);
}

int main() {

  Palindromo("1132311");
  Palindromo("abbcdcbba");
  Palindromo("algoritmo");
  return 0;
}
