
/*
*Feito por: Arlene P., Daniel Arruda e Pedro Otero
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define DiretorioDoArquivo "anagramas.txt"

typedef struct _Anagrama {
	char* letrasExibidas;
	char** palavrasExistentes;
	bool* palavrasEncontradas;
	int quantPalavrasExistentes;
} Anagrama;

enum OpcaoMenu {
	Inicio = 0,
	NovoJogo = 1,
	VoltarAoJogo = 2,
	Regras = 3,
	Sair = 4
};

enum OpcaoMenu menu(bool jogoEmCurso, bool inicio);

int verificarEntrada(char* resposta, Anagrama* anagrama);
void printarInterface(Anagrama anagrama, int status);
void exibirRegras();
void clear(); 

int lerArquivo(bool** anagramasJogados, int* tamanhoAnagramasJogados, Anagrama* anagrama);
void liberarMemoria(Anagrama* anagrama);
bool temMaisAnagramas(bool* anagramasJogados, int tamanhoAnagramasJogados);
bool temMaisPalavras(bool* anagramasJogados, int tamanhoAnagramasJogados); 

int main(){
	Anagrama anagrama;
  int tamanhoAnagramasJogados = 0, status = 5;
  bool* anagramasJogados = NULL;

	enum OpcaoMenu opcaoMenu = Inicio;
	bool jogoEmCurso = false;
	char resposta[46];
	
	while(true) {

		if(status == 5)
			opcaoMenu = menu(jogoEmCurso, opcaoMenu == Inicio);

		if(opcaoMenu == Sair)
			break;
		else if(opcaoMenu == Regras) {
			exibirRegras();
			continue;
		}
		else if(opcaoMenu == NovoJogo) {
			if(temMaisAnagramas(anagramasJogados, tamanhoAnagramasJogados) || tamanhoAnagramasJogados == 0) {
				if(lerArquivo(&anagramasJogados, &tamanhoAnagramasJogados, &anagrama))
					return 1;
			}
			else {
				clear();
				printf("Você já jogou todos anagramas possíveis\n");
				printf("Digite qualquer coisa para sair do jogo\n");

				setbuf(stdin, NULL);
				scanf(" %s", resposta);
				break;
			}
		}
		
		status = 0;
		jogoEmCurso = true;

		while(true) {

			printarInterface(anagrama, status);

			scanf("%s", resposta);

			status = verificarEntrada(resposta, &anagrama);

			if(status == 5)
				break;

			else if(status == 1 && !temMaisPalavras(anagrama.palavrasEncontradas, anagrama.quantPalavrasExistentes)) {
				status = 6;
				printarInterface(anagrama, status);
				opcaoMenu = NovoJogo;
				break;
			}
		}
	}

	if(tamanhoAnagramasJogados > 0)
		liberarMemoria(&anagrama);

	return 0;
}

enum OpcaoMenu menu(bool jogoEmCurso, bool inicio){
	int opcao;
	enum OpcaoMenu opcaoMenu;
	bool entradaValida = false, primeiraEntrada = true;

	while(!entradaValida) {
		clear();

		if(inicio) {
			printf("=/=/=/=/=/=/=/=SEJA BEM-VINDO(A) AO JOGO ANAGRAMA=/=/=/=/=/=/=/=\n");
			printf("Forme o maior número possível de palavras usando as letras disponíveis!\n");
			printf("Cada grupo de \"?\" indica uma palavra e cada ponto de interrogação representa uma letra daquela palavra.\n");
			printf("Ex.: ????? representa uma palavra de 5 letras.\n");
			printf("Dica: Leia atentamente as regras, elas irão te ajudar!\n");
			printf("Pronto?\n\n");
		}

		printf("=*=*=*=*=*=*=*=*=*=*=MENU=*=*=*=*=*=*=*=*=*=*=\n");

		if(jogoEmCurso)
			printf("Escolha uma das opções: \n 1 - Novo Jogo\n 2 - Voltar para o jogo\n 3 - Regras\n 4 - Sair\n");
		else
			printf("Escolha uma das opções: \n 1 - Novo Jogo\n 2 - Regras\n 3 - Sair\n");

		if(primeiraEntrada) {
			printf("\nOpção escolhida: ");
			setbuf(stdin, NULL);
			scanf("%d", &opcao);
			primeiraEntrada = false;
		}
		else {
			printf("\nDigite uma opção válida: ");
			setbuf(stdin, NULL);
			scanf("%d", &opcao);
		}

		if(jogoEmCurso) {
			if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4)
				continue;
			else
				entradaValida = true;

			switch (opcao){
				case 1:
					opcaoMenu = NovoJogo;
					break;
				case 2:
					opcaoMenu = VoltarAoJogo;
					break;
				case 3:
					opcaoMenu = Regras;
					break;
				case 4:
					opcaoMenu = Sair;
					break;
			}
		}
		else {
			if(opcao != 1 && opcao != 2 && opcao != 3)
				continue;
			else
				entradaValida = true;

			switch (opcao){
				case 1:
					opcaoMenu = NovoJogo;
					break;
				case 2:
					opcaoMenu = Regras;
					break;
				case 3:
					opcaoMenu = Sair;
					break;
			}
		}
	}
	
	return opcaoMenu;
}

void exibirRegras(){
	char resposta[46];

	clear();
	printf("=============================================================\n");
	printf("\t\t\tREGRAS\t\t\t");
	printf("\n=============================================================\n");
	printf("-Uma palavra é escolhida para servir como base do jogo atual;\n");
	printf("-Use as letras disponíveis para formar palavras\n");
	printf("-Não são aceitos nomes próprios, gírias ou siglas;\n");
	printf("-Verbos são aceitos apenas se estiverem no infinitivo (terminam em \"ar\", \"er\" ou \"ir\");\n");
	printf("-Cada conjunto de pontos de interrogação representa uma palavra, sendo que elas estão agrupadas por tamanho. Cada ponto de interrogação representa uma letra;\n");
	printf("-O jogo termina apenas quando TODAS as palavras forem formadas.\n");
	printf("==========================================================\n");
	printf("\t\t\tFIM DAS REGRAS\t\t\t");
	printf("\n==========================================================\n");
	printf("Digite qualquer coisa para voltar ao menu\n");
	setbuf(stdin, NULL);
	scanf("%s", resposta);
}

void printarInterface(Anagrama anagrama, int status){
	int tamanhoPalavra;
	char resposta[46];

	clear();
	if(status == 6){
		printf("\n=*=*=*=*=*=*=*=*ANAGRAMA=*=*=*=*=*=*=*=*\n\n");
		printf("Parabéns!!! Você descobriu todas as palavras!!!\n\n");
		printf("Letras do Anagrama: ");
		tamanhoPalavra = strlen(anagrama.letrasExibidas);
		for(int i=0;i<tamanhoPalavra;i++){
			printf("%c",anagrama.letrasExibidas[i]);
			printf(" ");
		}
		printf("\n\nPALAVRAS ENCONTRADAS: \n");

		for(int i=0;i<anagrama.quantPalavrasExistentes;i++)
			if(anagrama.palavrasEncontradas[i]==true)
				printf("%s\t", anagrama.palavrasExistentes[i]);

		printf("\n\nDigite qualquer coisa para continuar\n");
		scanf("%s", resposta);
	} else {
		printf("\n=*=*=*=*=*=*=*=*ANAGRAMA=*=*=*=*=*=*=*=*\n\n");
		printf("Digite \"0\" para retornar ao menu\n");
		printf("Letras disponíveis: ");
		tamanhoPalavra = strlen(anagrama.letrasExibidas);
		for(int i=0;i<tamanhoPalavra;i++){
			printf("%c",anagrama.letrasExibidas[i]);
			printf(" ");
		}
		printf("\n");
		printf("=======================================================================\n");
		for(int i=0;i<anagrama.quantPalavrasExistentes;i++){
			tamanhoPalavra = strlen(anagrama.palavrasExistentes[i]);
			if(anagrama.palavrasEncontradas[i]==true)
				printf("%s\t", anagrama.palavrasExistentes[i]);
			else{	
				for(int j=0; j<tamanhoPalavra; j++){
					printf("?");
				}
				printf("\t");
			}
			if (tamanhoPalavra < 8)
				printf("\t");
			if((i + 1) % 4 == 0 && (i + 1) != anagrama.quantPalavrasExistentes)
				printf("\n");
		}
		printf("\n");
		printf("=======================================================================\n");
		switch (status){
			case 0:
				break;
			case 1:
				printf("Você encontrou uma palavra! Parabéns!\n");
				break;
			case 2:
				printf("Esta entrada é inválida... Por favor, digite uma entrada válida!\n");
				break;
			case 3:
				printf("Esta palavra é inexistente... Tente novamente!\n");
				break;
			case 4:
				printf("Esta palavra já foi encontrada. Digite outra, por favor!\n");
				break;
		}
		printf("\nDigite sua resposta: ");
	}
}

int lerArquivo(bool** anagramasJogados, int* tamanhoAnagramasJogados, Anagrama* anagrama) {
  char line[46];
  int numeroAnagrama, countAnagrama = -1, quantPalavrasExistentes = 0, quantAnagramas, i;
  FILE *file = fopen(DiretorioDoArquivo, "r");

  if(file == NULL) {
		clear();
    printf("Ocorreu um erro durante a leitura do arquivo");
		printf("Digite qualquer coisa para encerrar o programa\n");
		setbuf(stdin, NULL);
		scanf("%s", line);

		return 1;
	}
  
  fscanf(file, "%[^\n] ", line);

  quantAnagramas = atoi(line);

  if (*tamanhoAnagramasJogados != 0) {
    do {
      srand(time(NULL));
      numeroAnagrama = rand() % quantAnagramas;
    } while((*anagramasJogados)[numeroAnagrama]);

    liberarMemoria(anagrama);
  }
  else {
    srand(time(NULL));
    numeroAnagrama = rand() % quantAnagramas;

    *anagramasJogados = (bool*)malloc(quantAnagramas * sizeof(bool));
  
    for(i = 0; i < quantAnagramas; i++)
      (*anagramasJogados)[i] = false;

    *tamanhoAnagramasJogados = quantAnagramas;
  }

  anagrama->palavrasExistentes = (char**)malloc(quantPalavrasExistentes * sizeof(char*));

  while(fscanf(file, "%[^\n] ", line) != EOF) {
    if(strchr(line, '*') != NULL) {
      countAnagrama++;

      if(countAnagrama == numeroAnagrama) {
        fscanf(file, "%[^\n] ", line);
        anagrama->letrasExibidas = (char*)malloc(strlen(line) * sizeof(char));
        strcpy(anagrama->letrasExibidas, line);
      }
    }
    else if(countAnagrama == numeroAnagrama) {
      anagrama->palavrasExistentes = (char**)realloc(anagrama->palavrasExistentes, sizeof(char*) * ++quantPalavrasExistentes);
      anagrama->palavrasExistentes[quantPalavrasExistentes - 1] = (char*)malloc(strlen(line) * sizeof(char));
      strcpy(anagrama->palavrasExistentes[quantPalavrasExistentes - 1], line);
    }
  }

	if(quantAnagramas != countAnagrama + 1) {
		clear();
    printf("Quantidade de anagramas fornecidas no arquivo está incoerente");
		printf("Digite qualquer coisa para encerrar o programa\n");
		setbuf(stdin, NULL);
		scanf("%s", line);

		return 1;
	}

  anagrama->palavrasEncontradas = (bool*)malloc(quantPalavrasExistentes * sizeof(bool));

  for(i = 0; i < quantPalavrasExistentes; i++)
    anagrama->palavrasEncontradas[i] = false;

  anagrama->quantPalavrasExistentes = quantPalavrasExistentes;

  (*anagramasJogados)[numeroAnagrama] = true;

  fclose(file);

	return 0;
}

void liberarMemoria(Anagrama* anagrama) {
  int i;

  for(i = 0; i < anagrama->quantPalavrasExistentes; i++)
    free(anagrama->palavrasExistentes[i]);
  free(anagrama->palavrasExistentes);

  anagrama->quantPalavrasExistentes = 0;

  free(anagrama->letrasExibidas);
  free(anagrama->palavrasEncontradas);
}

bool temMaisAnagramas(bool* anagramasJogados, int tamanhoAnagramasJogados) {
  int i;

  for(i = 0; i < tamanhoAnagramasJogados; i++)
    if(!anagramasJogados[i])
      return true;

  return false;
}

bool temMaisPalavras(bool* palavrasEncontradas, int quantPalavrasExistentes) {
  int i;

  for(i = 0; i < quantPalavrasExistentes; i++)
    if(!palavrasEncontradas[i])
      return true;

  return false;
}

int verificarEntrada(char* resposta, Anagrama* anagrama){	
  if(strcmp(resposta, "0") == 0){
      return 5;
  }
	
	for (int i = 0; i < strlen(resposta); i++){
		resposta[i] = tolower(resposta[i]);
	}

  for(int i = 0; i < anagrama->quantPalavrasExistentes; i++){
      if(strcmp(resposta, anagrama->palavrasExistentes[i]) == 0){
          if(anagrama->palavrasEncontradas[i] == true)
              return 4;
          anagrama->palavrasEncontradas[i] = true;
          return 1;
      }
  }

  int tamanho = strlen(anagrama->letrasExibidas);
  char letrasExibidas[tamanho];
  for(int i = 0; i < tamanho; i++){
      letrasExibidas[i] = anagrama->letrasExibidas[i];
  }
  int contador = 0;
  for(int i = 0; i < strlen(resposta); i++){
      for(int j = 0; j < tamanho; j++){
          if(tolower(letrasExibidas[j]) == resposta[i]){
              contador++;
              letrasExibidas[j] = ' ';
              break;
          }
      }
      if(contador < 1)
          return 2;
      contador = 0;
  }
  return 3;
}

void clear(){
  #ifdef __linux__
    system("clear");
  #elif _WIN32 
    system("cls");
  #endif
}