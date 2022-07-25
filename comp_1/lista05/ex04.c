/*
Faça um programa que leia duas matrizes (5x5) de números inteiros, 
calcule e imprima o resultado da multiplicação entre as duas matrizes.
*/
#define LINHA 5
#define COLUNA 5 
#include <stdio.h>
int main(){
  int mat1[LINHA][COLUNA],mat2[LINHA][COLUNA],mult[LINHA][COLUNA],i,j,k, aux=0;
  for(i=0;i<LINHA;i++){
    for(j=0;j<COLUNA;j++){
      printf("Digite o valor da posição[%d][%d] da matriz 1:\n",i,j);
      scanf("%d",&mat1[i][j]);
      printf("Digite o valor da posição[%d][%d] da matriz 2:\n",i,j);
      scanf("%d",&mat2[i][j]);
      mult[i][j] = 0;
    }
  }
  for(i=0;i<LINHA;i++){
    for(k=0;k<COLUNA;k++){
      for(j=0;j<LINHA;j++)
       mult[i][k]+= mat1[i][j]*mat2[j][k]; 
    }
  }
  printf("=========MULTIPLICAÇÃO===========\n");
  for(i=0;i<LINHA;i++){
    for(j=0;j<COLUNA;j++){
      printf("%d\t",mult[i][j]);
    }
    printf("\n");
  }
  return 0;
}