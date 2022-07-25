#define LINHA 5
#define COLUNA 4
#include <stdio.h>
int main(){
  float d[LINHA][COLUNA],soma[LINHA][COLUNA], maior = 0, media=0;
  int i,j,aluno10;
  for(i=0;i<LINHA;i++){
    for(j=0;j<COLUNA-1;j++){
      if(j == 0){
        printf("Digite o numero de matricula do %do aluno:\n",i+1);
        scanf("%f",&d[i][j]);
      } else if(j==1){
        printf("Digite a media das provas do %do aluno:\n",i+1);
        scanf("%f",&d[i][j]);
      } else if(j==2){
        printf("Digite a media dos trabalhos do %do aluno:\n",i+1);
        scanf("%f",&d[i][j]);
      }
    }
    printf("================%d ALUNO CONCLUIDO=================\n",i+1);
  }
  printf("===============FIM DA LEITURA====================\n");
  for(i=0;i<LINHA;i++){
    for(j=1;j<COLUNA-2;j++)
      soma[i][COLUNA] = d[i][j] + d[i+1][j+2];
    media +=soma[i][COLUNA]; 
    if(maior < soma[i][COLUNA]){
      maior = soma[i][COLUNA];
      aluno10 = d[i][0];
    }
  } 
  media/=LINHA; 
  printf("O aluno que obteve a maior nota é: %d\n", aluno10);
  printf("A média aritmética das notas finais é: %f\n", media);
  return 0;
}