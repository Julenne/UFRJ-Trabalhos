/*
Programa : maisVelho.c
Autor : Arlene Pelenda Julienne
DRE: 121089214
Email: arlenej011@gmail.com
Data : 26/07/2021
Descricao : Este programa diz qual é o mais velho.
*/
#include <stdio.h>
int main(void){
  int dia1, dia2, mes1, mes2, ano1, ano2, anoAtual = 2021, verifica = 0, aux;
  while(verifica == 0){
    printf("Digite o dia mês e ano de nascimento da primeira pessoa: \n");
    scanf("%d%d%d",&dia1,&mes1,&ano1);
    if(dia1 > 31 || mes1 > 12 || ano1 > anoAtual){
      printf("Data inválida, por favor digite a data correta!\n");
    }else {
      if(mes1 == 2){
        if(dia1 > 29){
          printf("Fevereiro não possui mais de 29 dias.\n");
        }
      } else {
        if(dia1 == 29 && mes1 == 2){
          if((ano1%400 != 0) || (ano1%4 != 0 && ano1%100 == 0)){
            printf("O ano %d não é um ano bissexto, portanto o mês de fevereiro desse ano não possui 29 dias.\n", ano1);
          }
        } else {
          aux = mes1 % 2;
          if(aux == 0 && dia1 > 30){
            printf("Data inválida, por favor digite a data correta.\n");
          } 
        }
      }
    }
    while(verifica == 0){
      printf("Digite o dia mês e ano de nascimento da segunda pessoa: \n");
      scanf("%d%d%d",&dia2,&mes2,&ano2);
      if(dia2 > 31 || mes2 > 12 || ano2 > anoAtual){
        printf("Data inválida, por favor digite a data correta!\n");
      }else {
        if(mes2 == 2){
          if(dia2 > 29){
            printf("Fevereiro não possui mais de 29 dias.\n");
          }
        } else {
          if(dia2 == 29 && mes2 == 2){
            if((ano2%400 != 0) || (ano2%4 != 0 && ano2%100 == 0)){
              printf("O ano %d não é um ano bissexto, portanto o mês de fevereiro desse ano não possui 29 dias.\n", ano1);
            }
          } else {
            aux = mes2 % 2;
            if(aux == 0 && dia2 > 30){
              printf("Data inválida, por favor digite a data correta.\n");
            } 
          }
        }
      }
    }
  } 
  if(ano1 != ano2){
    if(ano1 > ano2){
      printf("segundo");
      return 0;
    } else {
      printf("primeiro");
      return 0;
    }
  } else { 
    if(mes1 != mes2){
      if(mes1 > mes2){
        printf("segundo");
        return 0;
      } else {
        printf("primeiro");
        return 0;
      }
    } else { 
      if(dia1 != dia2){
        if(dia1>dia2){
          printf("segundo");
          return 0;
        } else {
          printf("primeiro");
          return 0;
        }
      } else { 
        printf("mesmo dia");
        return 0;
      }
    }
  }
}