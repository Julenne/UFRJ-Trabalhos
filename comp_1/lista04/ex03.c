#include <stdio.h>
int main()
{
  float nota, media=0;
  int aux=0;
  while(1){
  for (int i = 0; i < 3; i++)
  {
    printf("Digite a nota:");
    scanf("%f", &nota);
    if(nota < 0){
      aux++;
      break;
    } 
    media+=nota;
  }
  if(aux !=0) break;
  media/=3;
  printf("Media: %f\n", media);

  }
}