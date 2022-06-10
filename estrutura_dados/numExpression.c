//Feito por: Arlene Pelenda 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define TAM 1000

typedef struct pilha{
	char* chave;
	struct pilha *prox;
}pilha;

int tam;

bool precedencia(char *s1, char *s2){
	if(strcmp(s1, "+")==0||strcmp(s1,"-")==0)
		if(strcmp(s2,"*")==0||strcmp(s2,"/")==0)
			return true; //a precedencia é menor
		else
			return false;
	else 
		return false;
}

int main(){
	pilha *p;
	pilha *op;
	char *exp;

	exp = (char*)malloc(TAM * sizeof(char));

	printf("Digite a expressão: \n");
	scanf("%s",exp);

	//DIVIDINDO A STRING em tokens e colocando na pilha
	char *expString = (char*)malloc(TAM * sizeof(char));
	
	int j=0;
	for(int i=0; i<strlen(exp); i++){
		if(isdigit(exp[i])){//verifica se é um algarismo
			expString[j++] = exp[i];
		} else {
			expString[j++] = ',';
			expString[j++] = exp[i];
			
			if(isdigit(exp[i+1])) expString[j++] = ',';
		}
	}

	char *s = strtok(expString, ","); 
	p = NULL;
	op = NULL;
	pilha *novo;
	pilha *novo2;
	pilha *simb;
	pilha *npolo;
	simb = NULL;
	npolo = NULL;
	int tamp=0;
	int x = 0;
	char *vetor = (char*)malloc(TAM * sizeof(char));
	while(s){
		if(isdigit(s[0])){
			novo = (pilha*)malloc(sizeof(pilha));
			novo -> chave = s;
			novo -> prox = npolo;
			npolo = novo;
			tamp++;
		  }else if(strcmp(s,"(")==0){
				novo2 = (pilha*)malloc(sizeof(pilha));
				novo2 -> chave = s;
				novo2 -> prox = simb;
				simb = novo2;
			}else if(strcmp(s,")")==0){ //fechamento de parenteses
				while(!(strcmp(simb->chave,"(")==0)){
					pilha *aux = NULL;
					aux = simb;
					simb= simb->prox;

					novo2 = (pilha*)malloc(sizeof(pilha));
					novo2 -> chave = aux->chave;
					novo2 -> prox = npolo;
					npolo = novo2;
					tamp++;
					free(aux);
				}
				pilha *aux2 = NULL;//tirar a abertura de parenteses
				aux2 = simb;
				simb= simb->prox;
				free(aux2);
			}else { //é um operador, certeza
				if(simb != NULL){
					while(precedencia(s,simb->chave)){
						pilha *aux2 = NULL;
						aux2 = simb;
						simb= simb->prox;

						novo = (pilha*)malloc(sizeof(pilha));
						novo -> chave = aux2->chave;
						novo -> prox = npolo;
						npolo = novo;


						free(aux2);
						if(simb == NULL) break;
					}
				}
				novo2 = (pilha*)malloc(sizeof(pilha));
				novo2 -> chave = s;
				novo2 -> prox = simb;
				simb = novo2;
				tamp++;
			}		
		s = strtok(NULL, ",");
	}
	while(simb!=NULL){
		pilha *aux = NULL;
		aux = simb;
		simb= simb->prox;

		novo = (pilha*)malloc(sizeof(pilha));
		novo -> chave = aux->chave;
		novo -> prox = npolo;
		npolo = novo;
		free(aux);
	}

	pilha *invertido = NULL;
	while(npolo){
		pilha *aux = NULL;
		aux = npolo;
		npolo= npolo->prox;

		novo = (pilha*)malloc(sizeof(pilha));
		novo -> chave = aux->chave;
		novo -> prox = invertido;
		invertido = novo;
		free(aux);
		
	}

	pilha *resultado = NULL;
	while(invertido){
		if(isdigit(invertido->chave[0])){
			pilha *aux = NULL;
			aux = invertido;
			invertido= invertido->prox;

			novo = (pilha*)malloc(sizeof(pilha));
			novo -> chave = aux->chave;
			novo -> prox = resultado;
			resultado = novo;
		} else {
			if(strcmp(invertido->chave,"-")==0){
				pilha *aux = NULL;
				aux = invertido;
				invertido= invertido->prox;

				pilha *prox = malloc(sizeof(pilha));
				prox = resultado->prox;
				int x,y; 
				sscanf(prox->chave, "%d", &x);
				sscanf(resultado->chave, "%d", &y); 
				int a;
				a = x-y;

				pilha *aux2 = NULL;
				aux2 = resultado;
				resultado= resultado->prox->prox;

				pilha *novo2 = (pilha*)malloc(sizeof(pilha));
				char *str = (char *) malloc(TAM * sizeof(char));
				
				sprintf(str,"%d",a);
						//printf("%d\n", a);
				novo2 -> chave = str;
				novo2 -> prox = resultado;
				resultado = novo2;

				free(aux);
				free(aux2);
				continue;
			}
			if(strcmp(invertido->chave,"+")==0){
				pilha *aux = NULL;
				aux = invertido;
				invertido= invertido->prox;

				pilha *prox = malloc(sizeof(pilha));
				prox = resultado->prox;
				int x,y; 
				sscanf(prox->chave, "%d", &x);
				sscanf(resultado->chave, "%d", &y); 
				int a;
				a = x+y;

				pilha *aux2 = NULL;
				aux2 = resultado;
				resultado= resultado->prox->prox;

				pilha *novo2 = (pilha*)malloc(sizeof(pilha));
				char *str = (char *) malloc(TAM * sizeof(char));;
				sprintf(str,"%d",a);
						//printf("%d\n", a);
				novo2 -> chave = str;
				novo2 -> prox = resultado;
				resultado = novo2;

				free(aux);
				free(aux2);
				continue;
			}
			if(strcmp(invertido->chave,"*")==0){
				pilha *aux = NULL;
				aux = invertido;
				invertido= invertido->prox;

				pilha *prox = malloc(sizeof(pilha));
				prox = resultado->prox;
				int x,y; 
				sscanf(prox->chave, "%d", &x);
				sscanf(resultado->chave, "%d", &y); 
				int a;
				a = x*y;

				pilha *aux2 = NULL;
				aux2 = resultado;
				resultado= resultado->prox->prox;

				pilha *novo2 = (pilha*)malloc(sizeof(pilha));
				char *str = (char *) malloc(TAM * sizeof(char));;
				sprintf(str,"%d",a);
						//printf("%d\n", a);
				novo2 -> chave = str;
				novo2 -> prox = resultado;
				resultado = novo2;

				free(aux);
				free(aux2);
				continue;
			}
			if(strcmp(invertido->chave,"/")==0){
				pilha *aux = NULL;
				aux = invertido;
				invertido= invertido->prox;

				pilha *prox = malloc(sizeof(pilha));
				prox = resultado->prox;
				int x,y; 
				sscanf(prox->chave, "%d", &x);
				sscanf(resultado->chave, "%d", &y); 
				int a;
				a = x/y;

				pilha *aux2 = NULL;
				aux2 = resultado;
				resultado= resultado->prox->prox;

				pilha *novo2 = (pilha*)malloc(sizeof(pilha));
				char *str = (char *) malloc(TAM * sizeof(char));;
				sprintf(str,"%d",a);
						//printf("%d\n", a);
				novo2 -> chave = str;
				novo2 -> prox = resultado;
				resultado = novo2;

				free(aux);
				free(aux2);
				continue;
			}
		}
	}

	free(s);
	
	pilha *tmp = resultado;
	//PRINTANDO NA TELA O RESULTADO:
	while (tmp != NULL){
		printf("A resposta é: %s", tmp->chave);
		tmp = tmp->prox;
	}
	free(tmp);
	free(npolo);

}