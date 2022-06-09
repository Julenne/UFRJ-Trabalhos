#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 30

typedef struct pilha{
	char* chave;
	struct pilha *prox;
}pilha;

int tam;

int main(){
	pilha *p;
	pilha *op;
	char *exp;

	exp = (char*)malloc(TAM * sizeof(char));
	exp = NULL;
	exp = "10+13+9+29+50867";

	//DIVIDINDO A STRING em tokens e colocando na pilha
	char expString[TAM];
	int j=0;
	for(int i=0; i<TAM;i++){
		expString[i] = ' ';
	}
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
	int tamp=0;

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
							sscanf(p->chave, "%d", &x);//13
							sscanf(prox->chave, "%d", &y);//10
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

	free(s);
	
	pilha *tmp = p;

	//PRINTANDO NA TELA
	while (tmp != NULL){
		printf("%s\n", tmp->chave);
		tmp = tmp->prox;
	}

	free(p);
}