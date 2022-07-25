#include <stdlib.h>
#include <stdio.h>

int main (void) {
  int i, n, *pvetor, cont=0;
  float media;

  scanf ("%d", &n);

  pvetor = (int *) malloc (n * sizeof(int));

  if (!pvetor) {
    puts (" Sem memória.");
    return 1;
  }

  for (i = 0; i < n; i++) {
    scanf("%d", pvetor + i);
  }

  media = 0.0;

  for (i = 0; i < n; i++) {
    media += *(pvetor + i);
  }

  media /= n;

	for(i=0; i < n; i++){
		if(*(pvetor + i) > media){
			cont++;
		}
	}
  printf ("%f\n", media);
	printf("%d\n", cont);
  free(pvetor);

  return 0;
}
