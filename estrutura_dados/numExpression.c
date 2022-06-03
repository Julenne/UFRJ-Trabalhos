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

void splitExpression(char *exp, pilha *p){
	char expString[TAM*2];
	int j=0;
	p = (pilha*)malloc(sizeof(pilha));
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
	//SEPARANDO A EXPRESSÃO COLOCANDO 1 CARACTERE EM CADAD POSIÇÃO.
	char *split = strtok(expString, ",");
	
	pilha *novo;
	p = NULL;
  while(split != NULL) {
		novo = (pilha*)malloc(sizeof(pilha));
		novo -> chave = split;
		novo -> prox = p;
		p = novo;
	 	//printf( "%s\n", p->chave );
    split = strtok(NULL, ",");
  }
	//free(split);
	/*pilha *tmp = p;
	
	while (tmp != NULL){
		printf("%s\n", tmp->chave);
		tmp = tmp->prox;
		if(tmp == NULL) break;
	}*/
	//return p;
}

int main(){
	/*CONVERTER
	char c = '1';
	int a = c - '0';
	*/
	//char *expString;
	pilha pi;
	pilha *p=&pi;
	int *expPilha;
	char *exp;
	//char *expString;
	exp = (char*)malloc(TAM * sizeof(char));
	//expString = (char*)malloc((TAM*2) * sizeof(char));
	
	exp = "((10+13)*9)*29";

	splitExpression(exp,&pi);
	
	//---------------INSERINDO--------------
	
	//expPilha = (char*)malloc(TAM * sizeof(char));
	pilha *tmp = p;
	while (tmp != NULL){
		printf("%s\n", tmp->chave);
		tmp = tmp->prox;
	}
	//free(p);
}