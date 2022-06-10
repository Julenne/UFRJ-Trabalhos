//INFELIZMENTE NÃO CONSEGUI FAZER COM PARENTESES, POR ISSO O CÓDIGO SÓ FUNCIONA
//COM OS OPERADORES E OS NUMEROS

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
	exp = NULL;
	printf("Digite a expressão: \n");
	//scanf("%s",exp);
	exp = "(5-6)*4";
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

	pilha *invertido;
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
	free(novo);
	free(npolo);

	pilha *resultado
	while(invertido){
		if(isdigit(invertido->chave)){

		}
	}

/*
	while(s != NULL) {
		if(isdigit(s[0])){
			
			novo = (pilha*)malloc(sizeof(pilha));
			novo -> chave = s;
			novo -> prox = p;
			p = novo;
			tamp++;
			while(tamp >= 2){
				if(strcmp(op->chave,"*")==0 || strcmp(op->chave,"/")==0){
					pilha *prox = malloc(sizeof(pilha));
					prox = p->prox;
					int x,y; 
					sscanf(p->chave, "%d", &x);
					sscanf(prox->chave, "%d", &y);
					int a;
					if(strcmp(op->chave,"/") == 0)
						a = x/y;
					else if(strcmp(op->chave,"*") == 0)
						a = x*y;

					pilha *aux = NULL;
					aux = p;
					p= p->prox->prox;

					tamp-=2;
					free(aux);

					pilha *aux2 = NULL;
					aux2 = op;
					op= op->prox;

					free(aux2);

					pilha *novo3 = (pilha*)malloc(sizeof(pilha));
					char *str = (char *) malloc(TAM * sizeof(char));;
					sprintf(str,"%d",a);
						//printf("%d\n", a);
					novo3 -> chave = str;
					novo3 -> prox = p;
					p = novo3;
					tamp++;
				}else{
					break;
				}			
			}
		} else {
			novo2 = (pilha*)malloc(sizeof(pilha));
			novo2 -> chave = s;
			novo2 -> prox = op;
			op = novo2;
		}
		s = strtok(NULL, ",");
	}
	
	while(tamp >=2){
		if(strcmp(op->chave,"+")==0 || strcmp(op->chave,"-")==0){
			pilha *prox = malloc(sizeof(pilha));
			prox = p->prox;
			int x,y; 
			sscanf(p->chave, "%d", &x);//13
			sscanf(prox->chave, "%d", &y);//10
			int a;
			if(strcmp(op->chave,"+") == 0)
				a = x+y;
			else if(strcmp(op->chave,"-") == 0)
				a = x-y;

			pilha *aux = NULL;
			aux = p;
			p= p->prox->prox;

			tamp-=2;
			free(aux);

			pilha *aux2 = NULL;
			aux2 = op;
			op= op->prox;

			free(aux2);

			pilha *novo3 = (pilha*)malloc(sizeof(pilha));
			char *str = (char *) malloc(TAM * sizeof(char));;
			sprintf(str,"%d",a);
			//printf("%s\n", str);
			novo3 -> chave = str;
			novo3 -> prox = p;
			p = novo3;
			tamp++;
		}
	}
*/
	free(s);
	
	pilha *tmp = outra;
	//PRINTANDO NA TELA O RESULTADO:
	while (tmp != NULL){
		printf("%s", tmp->chave);
		tmp = tmp->prox;
	}
	free(tmp);
	free(npolo);

}