#define VALOR 5
#include <stdio.h>
int main(){
  int i,j,z, x[VALOR],y[VALOR], result[VALOR],result2[VALOR*2],aux=0;
  char opcao;
  for(i=0;i<VALOR;i++){
    printf("Digite um número para x(%do): \n", i+1);
    scanf("%d", &x[i]);
  }
  for(i=0;i<VALOR;i++){
    printf("Digite um número para y(%do): \n", i+1);
    scanf("%d", &y[i]);
  }
  for(i=0;i<VALOR*2;i++){
    result2[i] = 0;
  }
  printf("Escolha uma das opções:\na\nb\nc\nd\ne\n");
  printf("Opção escolhida: ");
  scanf(" %c", &opcao);
  switch (opcao)
  {
  case 'a':
    for(i=0;i<VALOR;i++){
      result[i] = x[i]+y[i];
    }
    printf("========SOMA========\n");
    for(i=0;i<VALOR;i++){
      printf("%d\t", result[i]);
    }
    break;
  case 'b':
    for(i=0;i<VALOR;i++){
      result[i] = x[i]*y[i];
    }
    printf("========PRODUTO========\n");
    for(i=0;i<VALOR;i++){
      printf("%d\t", result[i]);
    }
    break;
  case 'c':
    i=0;
    z=0;
    while(i < VALOR-1){
      aux=0;
      for(j=0;j<VALOR;j++)
        if(x[i] == y[j])
          aux++;
      if(aux == 0){
        result[z] = x[i];
        z++;
      } 
      i++; 
    } 
    printf("========DIFERENÇA========\n");
    for(i=0;i<z;i++){
      printf("%d\t", result[i]);
    }
    break;
  case 'd':
    i=0;
    z=0;
    while(i < VALOR-1){
      aux=0;
      for(j=0;j<VALOR;j++)
        if(x[i] == y[j])
          aux++;
      if(aux != 0){
        result[z] = x[i];
        z++;
      } 
      i++; 
    } 
    printf("========INTERSEÇÃO========\n");
    for(i=0;i<z;i++){
      printf("%d\t", result[i]);
    }
    break;
  case 'e':
    i=0;
    z=0;
    while(i < VALOR-1){
      aux=0;
      for(j=0;j<VALOR;j++)
        if(x[j] == y[i])
          aux++;
      if(aux == 0){
        result2[z] = y[i];
        z++;
      } 
      i++; 
    }  
    for(i=0;i<VALOR;i++){
      result2[z] = x[i];
      z++;
    }
    printf("========DIFERENÇA========\n");
    for(i=0;i<z;i++){
      printf("%d\t", result2[i]);
    }
    break;
  default:
    break;
  }
}