/*
*Feito por: Arlene Pelenda
*As vértices tem de começar com o numero 1, para que este código funcione
*corretamente.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
	int aresta;
	int vert1;
	int vert2;
	int visit;
	struct pilha *prox;
}pilha;

struct pilha* busca (int x, pilha *y){
  pilha *p;
  p = y;
  while (p != NULL && p->aresta != x) {
    p = p->prox; 
		while(p!= NULL && p->aresta == x && p->visit == 1)
			p = p->prox;
	}
  return p;
}

int main(){
	int totVert,totArestas;
	int vert1,vert2,arest,minArestas;
	//printf("Total de vértices e arestas: \n");
	scanf("%d%d", &totVert, &totArestas);
	minArestas = totVert-1;
	int conj[totVert], tam[totVert];

	setbuf(stdin, NULL);

	for(int i=0; i<totVert;i++){
		conj[i] = i+1;
		tam[i] = 1;
	}
	pilha *grafo;
	pilha *novo;
	grafo = NULL;
	for(int i=0; i<totArestas;i++){
		//printf("Vert1 / Vert 2 / Aresta: ");
		scanf("%d%d%d", &vert1, &vert2, &arest);
		novo = (pilha*)malloc(sizeof(pilha));
		novo->aresta=arest;
		novo->vert1=vert1;
		novo->vert2=vert2;
		novo->visit=0;
		novo->prox=grafo;
		grafo = novo;
	}

	int ordemPesoArest[totArestas];

	pilha *tmp = grafo;
	int i=0;
	while (tmp != NULL){
		ordemPesoArest[i] = tmp->aresta;
		tmp = tmp->prox;
		i++;
	}
	// Ordenando o peso das arestas do menor para o maior:
	int aux;
	for(int i=0 ; i<totArestas; i++){
    for(int j=0; j<totArestas;j++){
      aux = ordemPesoArest[j];
      if(ordemPesoArest[j] > ordemPesoArest[i]){
        ordemPesoArest[j] = ordemPesoArest[i];
        ordemPesoArest[i] = aux;
			}
		}
	}
	
	int peso = 0;
	pilha *z;
	for(int i=0; i<totArestas; i++){
		if(minArestas == 0) break;
		z = busca(ordemPesoArest[i], grafo);
		vert1 = z->vert1;
		vert2 = z->vert2;
		if(conj[vert1-1] == conj[vert2-1]) continue;
		if(z->visit == 0){
			if(conj[vert1-1] == vert1 && conj[vert2-1] == vert2){
				conj[vert1-1] = vert2;
				tam[vert2-1] +=1;
				peso += z->aresta;
				minArestas -= 1;
				z->visit = 1;
			} else if(vert1 != conj[vert1-1]){
				if(vert2 == conj[vert2-1]){
					conj[vert2-1] = conj[vert1-1];
					tam[conj[vert1-1]-1] += 1;
					peso += z->aresta;
					minArestas -=1;
					z->visit = 1;
				} else if(vert2 != conj[vert2-1]){
					if(tam[conj[vert1-1]-1] > tam[conj[vert2-1]-1]){
						conj[vert2-1] = conj[vert1-1];
						tam[conj[vert1-1]-1] +=1;
						peso += z->aresta;
						minArestas -=1;
						z->visit = 1;
					} else if(tam[conj[vert1]-1] <= tam[conj[vert2-1]-1]){
						conj[vert1-1] = conj[vert2-1];
						tam[conj[vert2-1]-1] +=1;
						peso += z->aresta;
						minArestas -=1;
						z->visit = 1;
					}
				}
			} else if(vert1 == conj[vert1-1]){
				if(vert2 != conj[vert2-1]){
					conj[vert1-1] = conj[vert2-1];
					tam[conj[vert2-1]-1]+=1;
					peso += z->aresta;
					minArestas -=1;
					z->visit = 1;
				}
			}
		}
	}
	//Peso da arvore geradora minima
	printf("%d", peso);	
}