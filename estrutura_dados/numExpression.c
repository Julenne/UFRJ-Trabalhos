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
void empilha(pilha *pi, char *x){
		pilha *novo;
		novo = (pilha*)malloc(sizeof(pilha));
		novo -> chave = x;
		novo -> prox = pi;
		pi = novo;
}

int operacao(pilha *p, pilha *op){
	pilha *prox = malloc(sizeof(pilha));
	prox = p->prox;
	printf("eai: %s",prox->chave);
	int x,y; 
	sscanf(p->chave, "%d", &x);
	sscanf(prox->chave, "%d", &y);

	if(strcmp(op->chave,"/") == 0)
		return x/y;
	else if(strcmp(op->chave,"*") == 0){
		printf("%d",x*y);
		return x*y;

	}
	else if(strcmp(op->chave,"+")== 0 )
		return x+y;
	else if(strcmp(op->chave,"-")==0)
		return x-y;
	return 0;
}
int main(){
	//EXPRESSÕES NÚMERICAS SEM PARENTESES POIS NÃO CONSEGUI FAZER COM ELAS.
	/*CONVERTER
	char c = '1';
	int a = c - '0';
	*/
	//char *expString;
	pilha *p;
	pilha *op;
	char *exp;

	exp = (char*)malloc(TAM * sizeof(char));
	exp = NULL;
	exp = "10*13*9*29";
	//char *operador[TAM];
	//printf("Tudo ae: %s\n", exp); 

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

	//printf("Separado por vírgula: %s", expString);
	char *s = strtok(expString, ","); 
	p = NULL;
	op = NULL;
	pilha *novo;
	pilha *novo2;
	int tamp=0;
  /*while(s != NULL){
		novo = (pilha*)malloc(sizeof(pilha));
				novo -> chave = s;
				novo -> prox = p;
				p = novo;
		s = strtok(NULL, ",");
	}*/
	while(s != NULL) {
		if(isdigit(s[0])){//vou considerar que sempre é um digito
			
				novo = (pilha*)malloc(sizeof(pilha));
				novo -> chave = s;
				novo -> prox = p;
				p = novo;
				tamp++;
				
				
					while(tamp >= 2){
					
						if(strcmp(op->chave,"*") || strcmp(op->chave,"/")){
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

							//printf("deu isso aqui: %d", a);

							pilha *aux = NULL;
							aux = p;
							p= p->prox->prox;//NULL

							tamp-=2;
							free(aux);

							pilha *aux2 = NULL;
							aux = op;
							op= op->prox;//NULL

							free(aux2);

							pilha *novo3 = (pilha*)malloc(sizeof(pilha));
							char *str = (char *) malloc(TAM * sizeof(char));;
							sprintf(str,"%d",a);
							//printf("%s\n", str);
							novo3 -> chave = str;
							novo3 -> prox = p;
							p = novo3;
							tamp++;
							/*p = prox->prox;
							char *str = "";
							sprintf(str,"%d",a);
							novo = (pilha*)malloc(sizeof(pilha));
							novo -> chave = str;
							novo -> prox = p;
							p = novo;
							op=op->prox;*/
						}
				
			}
		} else {
			novo2 = (pilha*)malloc(sizeof(pilha));
			novo2 -> chave = s;
			novo2 -> prox = op;
			op = novo2;
			//printf("%s\n",op->chave);
		}
		s = strtok(NULL, ",");
	}


	//printf("%s\n", p->chave );
  
	

	//resolvendo
	//pilha *tmp = p;
	//PRINTANDO NA TELA


	free(s);
	
	pilha *tmp = p;
	//PRINTANDO NA TELA
	while (tmp != NULL){
		/*if(strcmp(tmp->chave,"*") || strcmp(tmp->chave,"/")){
			int x,y; 
				sscanf(tmp->chave, "%d", &x);//13
				sscanf(tmp->prox->chave, "%d", &y);//10
				int a;
				if(strcmp(op->chave,"/") == 0)
					a = x/y;
				else if(strcmp(op->chave,"*") == 0)
					a = x*y;

		}*/
		
		printf("%s\n", tmp->chave);
		tmp = tmp->prox;
	}

	free(p);
}