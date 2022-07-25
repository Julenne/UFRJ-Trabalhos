#include <stdio.h>
int main(){
  float valor, total;
  int codigo;
  printf("Digite o valor total da compra: ");
  scanf("%f", &valor);
  printf("Digite o codigo do comprador: ");
  scanf("%d", &codigo);
  total = valor;
  switch (codigo)
  {
  case 1:
    printf("Valor total: %f", total);
    break;
  case 2:
    total = total - (total*0.1);
    printf("Valor total: %f", total);
    break;
  case 3:
    total = total - (total*0.05);
    printf("Valor total: %f", total);
    break;
  }
}