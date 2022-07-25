/*
	* Programa : mediaNotas .c
	* Autor : Arlene Pelenda Julienne
	*DRE: 121089214
	*Email: arlenej011@gmail.com
	* Descricao : Calcula media de aluno e informa se ele foi aprovado ou n~ao .
	* Data : 26/07/2021
*/
#include <stdio.h>
int main (void) {
	float notaAluno ;
	float mediaAluno = 0.0;
	int notasLidas = 0;
	int quantProvas ;
	/* aqui falta ler a quantidade de provas */
	printf("Quantas provas?");
	scanf("%d",&quantProvas);
	while ( notasLidas < quantProvas ) {
		printf("Nota do aluno:");
		scanf("%f",&notaAluno);
		mediaAluno=mediaAluno+notaAluno;
		notasLidas = notasLidas + 1;	
	}
	mediaAluno = mediaAluno / quantProvas ;
	printf ("A media do aluno foi %f\n", mediaAluno );
	if ( mediaAluno >= 5.0) {
		printf (" Aprovado \n");
	}
	else{
		printf (" Reprovado ");
	}
	return 0;
}
