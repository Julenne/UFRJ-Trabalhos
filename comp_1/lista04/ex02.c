#include <stdio.h>
int main()
{
  int idade,media=0, total=0, maior=0, menor=0;
  while (1)
  {
    printf("Digite a idade:");
    scanf("%d", &idade);
    if(idade == 0) break;
    if(idade>maior)
      maior = idade;
    if(menor == 0)
      menor = idade;
    else if(idade < menor)
      menor = idade;
    media +=idade;
    total++;
  }
  media/=total;
  printf("Número de pessoas: %d\nIdade média do grupo: %d\nMenor idade: %d\nMaior idade: %d\n",
          total,media,menor,maior);
}