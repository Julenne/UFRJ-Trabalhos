#include <stdio.h>

int main(){
  int opcao, aux, numero, quociente, resto;
  while(1){
    opcao = 0;
    printf("Entre com o número dentre as opções:\n1: decimal para hexadecimal\n2: hexadecimal para decimal\n3: decimal para octal\n4: octal para decimal\n5: Encerra\n");
    scanf("%d", &opcao);
    printf("Entre com o número na base escolhida:\n");
    switch (opcao){
    case 1:
      scanf("%d", &numero);
      printf("Conversão: %x\n", numero);
      break;
    case 2:
      scanf("%x", &numero); 
      printf("Conversão: %d\n", numero);
      break;
    case 3:
      scanf("%d", &numero); 
      printf("Conversão: %o\n", numero);    
      break;
    case 4:
      scanf("%o", &numero); 
      printf("Conversão: %d\n", numero);
      break;
    case 5:
      break;
    }
    printf("Se deseja continuar, digite 6. Senão digite 5\n");
    scanf("%d", &opcao);
    if(opcao == 5)
      break;
  }
}