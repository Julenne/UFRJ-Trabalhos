#define TAM 3
#include <stdio.h>
//fazer as verificações depois.
int main(){
  char string1[TAM], string2[TAM], invertido1[TAM], invertido2[TAM],concat[121], opcao,c;
  int i, j, cont1=0, cont2=0,total=0,aux=0,r;
  printf("Digite uma palavra: \n");
  scanf("%s", string1);
  for (i = 0; string1[i] != '\0' ; i++) cont1++;
  if(cont1 > TAM){
    printf("Você digitou mais caracteres do que o máximo (60)!!");
    return 0;
  }
  printf("Digite uma outra palavra: \n");
  scanf("%s", string2);
  for (i = 0; string2[i] != '\0' ; i++) cont2++;
  if(cont2 > TAM){
    printf("Você digitou mais caracteres do que o máximo (60)!!");
    return 0;
  }
  printf("Escolha uma das opções a seguir:\na\nb\nc\nd\ne\n");
  scanf(" %c",&opcao);
  fflush(stdin);
  switch (opcao)
  {
  case 'a'://Mostre as strings invertidas;
    for (i = 0; string1[i] != '\0' ; i++) cont1++;
    for (i = 0; string2[i] != '\0' ; i++) cont2++;
    j=0;
    i=cont1-1;
    while(i>=0){
        invertido1[j] = string1[i];
      j++;
      i--;
    }
    j=0;
    i=cont2-1;
    while(i>=0){
        invertido2[j] = string2[i];
      j++;
      i--;
    }
    printf("String 1 invertida: %s\nString 2 invertida: %s", invertido1, invertido2);
    break;
  case 'b'://Copie (ou concatene) as duas strings em outro vetor, imprimindo a resposta;
    for (i = 0; string1[i] != '\0' ; i++) cont1++;
    for (i = 0; string2[i] != '\0' ; i++) cont2++;
    total = cont1+cont2;
    for(i=0; i<total; i++){
      if(i<cont1)
        concat[i] = string1[i];
      else{
        for(j=0; j<cont2; j++){
          concat[i] = string2[j];
          i++;
        }
        break;
      }
    }
    printf("Palavra concatenada: %s", concat);
    break;
  case 'c'://Compare as duas strings e informe quem é a string maior;
    for (i = 0; string1[i] != '\0' ; i++) cont1++;
    for (i = 0; string2[i] != '\0' ; i++) cont2++;
    if(cont1==cont2)
      printf("As duas strings tem o mesmo tamanho.");
    else
      (cont1>cont2)?printf("A string de maior tamanho é: %s e a de menor tamanho é: %s", string1,string2)
      :printf("A string de maior tamanho é: %s e a de menor tamanho é: %s", string2, string1);
    break;
  case 'd'://Informe a string de maior tamanho;
    for (i = 0; string1[i] != '\0' ; i++) cont1++;
    for (i = 0; string2[i] != '\0' ; i++) cont2++;
    if(cont1==cont2)
      printf("As duas strings tem o mesmo tamanho.");
    else
      (cont1>cont2)?printf("A string de maior tamanho é: %s ", string1)
      :printf("A string de maior tamanho é: %s ", string2);
    break;
  case 'e'://Identifique a ocorrência de determinado caractere na string e informa sua posição (não se esqueça de solicitar o caractere);
    printf("Digite um caractere: \n");
    scanf(" %c",&c);
    for (i = 0; string1[i] != '\0' ; i++) cont1++;
    for (i = 0; string2[i] != '\0' ; i++) cont2++;
    for(i=0;i<cont1;i++)
      if(c == string1[i]) aux++;
    printf("Ocorrência da letra %c na String %s é: %d\n",c,string1,aux);
    aux = 0;
    for(i=0;i<cont2;i++)
      if(c == string2[i]) aux++;
    printf("Ocorrência da letra %c na String %s é: %d\n",c,string2,aux);
    break;
  }
  return 0;
}