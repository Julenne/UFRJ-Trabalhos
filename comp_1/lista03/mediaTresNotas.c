/*
	* Programa : mediaTresNotas .c
	* Autor : Arlene Pelenda Julienne
	*DRE: 121089214
	*Email: arlenej011@gmail.com
	* Descricao : Le tres notas de um aluno , calcula sua media
	* e informa se ele foi aprovado ou nao .
	* Data : 26/07/2021
*/
#include <stdio.h>
int main (void) {
	float notaAluno ;
	float mediaAluno ;
	printf("Nota do Aluno:\n");
	scanf("%f",&notaAluno);
	mediaAluno=notaAluno;
	printf("Nota do Aluno:\n");
	scanf("%f",&notaAluno);
	mediaAluno=mediaAluno+notaAluno;
	printf("Nota do Aluno:\n");
	scanf("%f",&notaAluno);
	mediaAluno=mediaAluno+notaAluno;
	mediaAluno=mediaAluno/3;
	printf("A média é: %f",mediaAluno);
	if (mediaAluno >= 5.0) {
		printf (" Aprovado \n");
	}
	else {
		printf (" Reprovado ");
	}
	return 0;
}
