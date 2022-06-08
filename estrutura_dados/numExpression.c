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
	/*CONVERTER
	char c = '1';
	int a = c - '0';
	*/
	//char *expString;
	pilha *p;
	char *exp;
	exp = (char*)malloc(TAM * sizeof(char));
	

	exp = NULL;
	exp = "((10+13)*9)*29";

	//printf("Tudo ae: %s\n", exp); 

	char expString[TAM];
	int j=0;
	for(int i=0; i<TAM;i++){
		expString[i] = ' ';
	}
	for(int i=0; i<strlen(exp); i++){
		if(isdigit(exp[i])){
			expString[j++] = exp[i];
		} else {
			expString[j++] = ',';
			expString[j++] = exp[i];
			
			if(isdigit(exp[i+1])) expString[j++] = ',';
		}
	}

	//printf("Separado por vírgula: %s", expString);
	char *s = strtok(expString, ","); 
	p = NULL;
	pilha *novo;
  while(s != NULL) {
		novo = (pilha*)malloc(sizeof(pilha));
		novo -> chave = s;
		novo -> prox = p;
		p = novo;
	 	//printf("%s\n", p->chave );
    s = strtok(NULL, ",");
	}
	free(s);
	pilha *tmp = p;
	while (tmp != NULL){
		printf("%s\n", tmp->chave);
		tmp = tmp->prox;
	}
	free(p);
}