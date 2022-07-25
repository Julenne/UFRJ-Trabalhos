#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main(void){
  int i, dentro ;
  double x,y,distancia,X;
  srand(time(NULL));
  for(i=0;i<1000000;i++){
   //SE O RAND() retornar 0 o resultado da divisão será 0 (menor)
   //se retornar rand_max o resultado da divisão será 1 porque RAND_MAX/RAND_MAX =  1 (maior)
    x = (double) rand() / (double) RAND_MAX; 
    y = (double) rand() / (double) RAND_MAX;
    distancia = x*x + y*y;
    //printf("%lf\n",distancia);
    if(distancia <= 1.0){
      dentro++;
    }
  }
  X = (float) 4 * dentro / (float) 1000000 ; 
  printf("%f\n", X); //Sempre retorna 3.0
  return 0;
}
