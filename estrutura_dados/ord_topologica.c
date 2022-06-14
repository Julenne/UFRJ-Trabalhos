#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000;

typedef struct adj {
	int chave;
	struct adj *prox;
}adj;

int main(){
	int totVert = 0, totArest = 0, elem;
	char *nums = (char*)malloc(1000 * sizeof(char));
	adj *ord = NULL;

	printf("Digite total de vértices e arestas: ");
	scanf("%d%d",&totVert,&totArest);

	setbuf(stdin, NULL);

	adj *vetor[totVert];//2 vertices
	adj *novo;
	int grauVert[totVert];
	for(int i=0;i<totVert;i++){
		grauVert[i]=0;
	}
	//formando o grafo no vetor
	for(int i=0;i<totVert;i++){
		printf("Vizinhos do vértice %d: ",i+1);
		fgets(nums, 1000, stdin);

		char *token = strtok (nums," "); 
		vetor[i] = (adj*)malloc(sizeof(adj));
		vetor[i] = NULL;
		
		if(strcmp(nums, "\n") == 0) continue; 
		
		while(token){
			novo = (adj*)malloc(sizeof(adj));
			sscanf(token, "%d", &elem);
			
			novo -> chave = elem;
			novo -> prox = vetor[i];
			vetor[i] = novo;
			token = strtok(NULL, " ");
			grauVert[elem-1] += 1;
		}
	}
	int cont=0;
	int verif=0;
	do{
		for(int i=0;i<totVert;i++){
			int number = i;
			adj *tmp = ord;
			while (tmp != NULL){
				int n = tmp->chave-1;
				if(n == i) {
					verif = 1;
					break;
				};
				tmp = tmp->prox;
			}
			if(verif == 1){
				verif = 0;
				continue;
			}
			if(grauVert[i] == 0){
				if(vetor[i] != NULL){
					adj *tmp2 = vetor[i];
					while (tmp2 != NULL){
						int n = tmp2->chave-1;
						grauVert[n]-=1;
						tmp2 = tmp2->prox;
					}
				}
				vetor[number] = NULL;

				novo = (adj*)malloc(sizeof(adj));
				novo -> chave = number+1;
				novo -> prox = ord;
				ord = novo;
			}
		}

		cont = 0;
		for(int i=0;i<totVert;i++)
			if(vetor[i]!=NULL)
				cont++;
	}while(cont !=0);
	
	adj *invertido = NULL;
	while(ord){
		adj *aux = NULL;
		aux = ord;
		ord= ord->prox;

		novo = (adj*)malloc(sizeof(adj));
		novo -> chave = aux->chave;
		novo -> prox = invertido;
		invertido = novo;
		free(aux);
		
	}

	adj *tmp = invertido;

	//PRINTANDO NA TELA O RESULTADO:
	printf("---------ordenação topológica----------\n");
	while (tmp != NULL){	
		printf("%d\t", tmp->chave);
		tmp = tmp->prox;
	}

}