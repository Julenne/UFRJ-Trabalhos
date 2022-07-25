#define VALOR 10
#include <stdio.h>
int main(){
  int vetor[VALOR], i, result=0,n;
  char opcao;
  for(i=0;i<VALOR;i++){
    printf("Digite um número(%do): \n", i+1);
    scanf("%d", &vetor[i]);
  }
  printf("Escolha uma das opções:\na\nb\nc\nd\ne\n");
  printf("Opção escolhida: ");
  scanf(" %c", &opcao);
  if(opcao == 'a'){
    for(i=0;i<VALOR;i++)
      if(vetor[i] > result)
        result = vetor[i];
    printf("O maior número é: %d", result);

  } else if (opcao == 'b'){
    result = vetor[0];
    for(i=1;i<VALOR;i++)
      if(vetor[i] < result) 
        result = vetor[i];
    printf("O menor número é: %d", result);

  } else if (opcao == 'c'){
    for(i=0;i<VALOR;i++)
      if(vetor[i]%2 == 0) result++;
    printf("Existem %d números pares.", result);

  } else if (opcao == 'd'){
    for(i=0;i<VALOR;i++) 
      result+=vetor[i];
    printf("Soma de todos os números: %d", result);

  } else if (opcao == 'e'){
    printf("Digite um outro número:\n");
    scanf("%d", &n);
    for(i=0;i<VALOR;i++)
      if(vetor[i] == n) result++;
    (result == 0)?printf("O valor %d não existe no vetor",n)
    :printf("O valor %d existe no vetor",n);
  }
}