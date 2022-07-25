/*
Programa : desafioNota.c
Autor : Arlene Pelenda Julienne
Data : 26/07/2021
DRE: 121089214
Email: arlenej011@gmail.com
Descricao : Este programa faz o calculo da nota de um aluno de um disciplina.
*/
#include <stdio.h>
int main (void) {
	float prova, t1, t2, t3, notaFinal;
	printf("Prova:");
	scanf("%f", &prova);
	printf("Teste 1:");
        scanf("%f", &t1);
	printf("Teste 2:");
        scanf("%f", &t2);
	printf("Teste 3:");
        scanf("%f", &t3);
	notaFinal = 0.8 * prova + 0.2*(t1+t2+t3)/3;
	printf("Nota Final: %f",notaFinal);
	return 0;
}
