/*
Programa : desafioNota.c
Autor : Arlene Pelenda Julienne
DRE: 121089214
Email: arlenej011@gmail.com
Data : 26/07/2021
Descricao : Este programa faz a soma de todos os numeros inteiros entre 0 e n.
*/
#include <stdio.h>
int main (void) {
	int n, soma;
	printf("Digite o número:\n");
	scanf("%d",&n);
	soma = (n*n+n)/2;
	printf("Soma de todos os números inteiros entre 0 e %d: %d",n,soma);
}
