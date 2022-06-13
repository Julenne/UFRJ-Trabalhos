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

	//formando o grafo no vetor
	for(int i=0;i<totVert;i++){
		printf("Digite a linha %d: ",i+1);
		fgets(nums, 1000, stdin);

		char *token = strtok (nums," "); 
		vetor[i] = (adj*)malloc(sizeof(adj));
		vetor[i] = NULL;
		grauVert[i] = 0;
		
		if(strcmp(nums, "\n") == 0) continue; 
		
		while(token){
			novo = (adj*)malloc(sizeof(adj));
			sscanf(token, "%d", &elem);
			
			printf("token: %d\n", elem);
			
			novo -> chave = elem;
			novo -> prox = vetor[i];
			vetor[i] = novo;
			token = strtok(NULL, " ");
			grauVert[i] += 1;
		}
	}
	int aux = totVert-1;
	while(aux!=0){
		
		for(int i=0;i<totVert;i++){
			if(grauVert[i] == 0){
				if(vetor[i] != NULL){
					adj *tmp = vetor[i];
					while (tmp != NULL){
						grauVert[tmp->chave]--;
						tmp = tmp->prox;
					}
				}
				for(int j = i; j < totVert; j++ )
					vetor[j] = vetor[j+1];
				totVert--;

				novo -> chave = i+1;
				novo -> prox = ord;
				ord = novo;
				aux--;
			} else{
			for(int j = i; j < totVert; j++)
				vetor[j] = vetor[j+1];
			totVert--;
				aux--;
			}
		}
	}
	
	//printf("grau: %d", grauVert[1]);
	adj *tmp = ord; // linha 2
	//PRINTANDO NA TELA O RESULTADO:
	while (tmp != NULL){	
		printf("aresta: %d\t", tmp->chave);
		tmp = tmp->prox;
	}

}