#define LINHA 2
#define COLUNA 3 
#include <stdio.h>
int main(){
  int mat1[LINHA][COLUNA],mat2[LINHA][COLUNA],soma[LINHA][COLUNA], i,j;
  for(i=0;i<LINHA;i++){
    for(j=0;j<COLUNA;j++){
      printf("Digite o valor da posição[%d][%d] da matriz 1:\n",i,j);
      scanf("%d",&mat1[i][j]);
      printf("Digite o valor da posição[%d][%d] da matriz 2:\n",i,j);
      scanf("%d",&mat2[i][j]);
    }
  }
  for(i=0;i<LINHA;i++){
    for(j=0;j<COLUNA;j++){
      soma[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
  printf("=========SOMA===========\n");
  for(i=0;i<LINHA;i++){
    for(j=0;j<COLUNA;j++){
      printf("%d\t",soma[i][j]);
    }
    printf("\n");
  }
  return 0;
}