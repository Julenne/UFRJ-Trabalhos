//ARLENE PELENDA JULIENNE - DRE:121089214
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

void criaVetor(int *v, int n){

	for (int i = 0; i < n; ++i) 
		v[i] = rand()%10000;

}

void mergeSort2(int *v, int inicio,int meio, int fim){
	int i = inicio, j = meio, pos=0;
	int *temp = malloc((fim-inicio)* sizeof(int));
	while (i<meio && j<fim)
	{
		if(v[i]<v[j]){
			temp[pos] = v[i];
			i++;
		}else{
			temp[pos]=v[j];
			j++;
		}
		pos++;
	}
	while(i<meio){
		temp[pos]=v[i];
		i++;
		pos++;
	}		
	while(j<fim){
		temp[pos]=v[j];
		j++;
		pos++;
	}
	for (int i = 0; i < pos; i++)
		v[inicio+i]=temp[i];
	free(temp);
}

void mergeSort1(int *v,int inicio, int fim){
	int meio;
	if(fim-inicio > 1) {
		meio = (inicio + fim)/2;
		mergeSort1(v, inicio, meio);
		mergeSort1(v, meio, fim);
		mergeSort2(v,inicio, meio, fim);
	}
}

void troca(int *v, int i1, int i2){
	int aux;
	aux = v[i1];
	v[i1] = v[i2];
	v[i2] = aux;
}

void quickSort(int *v, int inicio, int fim){
	
	if(fim-inicio > 1){
		int aux;
		int pivot = v[inicio], i = inicio+1, j=fim-1;
		while(i<j){
			while(i<fim && v[i]<pivot)
				i++;
			while(j>inicio && v[j]>pivot)
				j--;
			if(i<j){
				aux = v[i];
				v[i]=v[j];
				v[j]=aux;
			}
				//troca(v,i,j);
		}
		aux = v[inicio];
		v[inicio]=v[j];
		v[j]=aux;
		//troca(v,inicio,j);
		quickSort(v,inicio,j);
		quickSort(v, i, fim);
	}
}

void sort(int *v, int fim){
	int aux;
	for(int i=0 ; i<fim; i++){
    for(int j=0; j<fim;j++){
      aux = v[j];
      if(v[j] > v[i]){
        v[j] = v[i];
        v[i] = aux;
			}
		}
	}
}

int main(){
	int *v, n, inicio=0, fim, aux; 
	char tipo[3], cria[3];
	//clock_t Ticks[2];
	srand(time(NULL));

	printf("Digite a entrada:");
  scanf("%s%d%s",cria, &n, tipo);
	//Ex. de entrada: -n 1000 -m	

	v = malloc(n * sizeof (int));

	for(aux = 0; aux < strlen(tipo); aux++) {
        if(tipo[aux] == ' ') {
            tipo[aux] = tipo[aux + 1];
        }
  }
	if(strcmp(tipo, "-m") == 0){
			//MERGE SORT
		criaVetor(v,n);
		fim = n;
		mergeSort1(v, inicio, fim);
		printf("-------------MergeSort------------\n");
		for (int i = 0; i < fim; ++i)
			printf("%d\n", v[i]);
	} else if(strcmp(tipo, "-q") == 0){
		//QUICKSORT
		criaVetor(v,n);
		fim = n;
		quickSort(v,inicio,fim);
		printf("------------QuickSort-------------\n");
		for (int i = 0; i < fim; ++i)
			printf("%d\n", v[i]);
	} else if(strcmp(tipo, "-n") == 0){
			//SORT
		criaVetor(v,n);
		fim = n;
		sort(v,fim);
			printf("--------------Sort----------------\n");
		for (int i = 0; i < fim; ++i)
			printf("%d\n", v[i]);
	}

	/*Ticks[0] = clock();
	Ticks[1] = clock();
  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0/CLOCKS_PER_SEC;
	printf("Tempo gasto: %g ms.\n", Tempo);*/

	free(v);
	return 0;
}
