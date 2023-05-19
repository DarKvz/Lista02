#include <stdio.h>
#include <conio.h>
int main(void)
{
  int valor = 27;
  
  int *ptr;

  ptr = &valor;

  printf("Utilizando ponteiros\n\n");
  printf ("Conteudo da variavel valor: %d\n", valor);
  printf ("Endereço da variavel valor: %x \n", &valor);
  printf ("Conteudo da variavel ponteiro ptr: %x", ptr);
  
  getch();
  return(0);
}