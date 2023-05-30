#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int STATUS;	// variavel global
#define STATUS_INIT		0
#define STATUS_EXEC		1
#define STATUS_ENDGAME	2

int MIN_VAL; 
int MAX_VAL;
int N_TENTATIVAS;

// Setar as definicoes default do game
void init_game(void) {
	srand( time(0) );	// Inicia a semente da funcao rand()
	MIN_VAL = 0;
	MAX_VAL = 10;
	N_TENTATIVAS = 3;
	STATUS = STATUS_INIT;
}

void tela_apresentacao(void) {
	printf(
		"------------------------------------------------\n"
		"- BEM VINDO AO JOGO DE ADIVINHE O NUMERO       -\n"
		"------------------------------------------------\n"
		"\n\n\n"
		);
	// delay
	sleep(2);
}

void tela_endgame(void) {
	printf(
		"------------------------------------------------\n"
		"- JA VAI TARDE                                 -\n"
		"------------------------------------------------\n"
		"\n\n\n"
		);
	// delay
	sleep(2);
}

int menu_tela_conf(void) {
	int op;
	printf("1) Definir intervalo\n");
	printf("2) Definir tentativas\n");
	printf("3) PLAY\n");
	printf("4) Sair\n");
    printf("\n");
	scanf("%d", &op);
    printf("\n\n");
	return op;
}

void tela_conf(void) {
	int k;
	while(1) {
		k = menu_tela_conf();
		switch ( k ) {
			case 1:
				printf("Entre com os valores de MIN e MAX: ");
				scanf("%d %d", &MIN_VAL, &MAX_VAL);
                printf("\n");
				break;
			case 2:
				printf("Entre com a quantidade de tentativas: ");
				scanf("%d", &N_TENTATIVAS);
                printf("\n\n\n");
				break;
			default:
				printf("Opcao invalida\n\n");
				break;
			case 3:
				STATUS = STATUS_EXEC;
				break;
			case 4:
				STATUS = STATUS_ENDGAME;
				break;
		}
		if(k==3 || k==4) break;
	}
}


void tela_game_state(int nt, int last_n) {
	printf(
		"=====================================\n"
		"= Tentativas restantes: %d          =\n"
		, N_TENTATIVAS-nt );
	if( last_n != -1 ) {
		printf("= Ultima tentativa: %d              =\n", last_n);
	}
	printf("=====================================\n");

}

int main() {
	int N; // Numero sorteado
	int x; // Tentativa
	int nt; // numero de tentativas
	int last_n; // ultima tentativa

	// Inicializacao
	init_game();

	tela_apresentacao();

	while( STATUS == STATUS_INIT ) {
		tela_conf();
		if( STATUS == STATUS_ENDGAME ) {
			tela_endgame();
			return 0;
		}

		// Sorteando o numero aleatorio
		N = rand() % (MAX_VAL+1-MIN_VAL) + MIN_VAL;
		nt = 0;
		last_n = -1;
		while( STATUS == STATUS_EXEC )  {

			if(nt == N_TENTATIVAS) {
				printf("Perdeu!\n\n\n");
				break;;
			}
			tela_game_state(nt, last_n );
			printf("Digite um numero: ");
			scanf("%d", &x);
            printf("\n\n");
			if( N > x ) {
				printf("O valor N e maior que %d\n", x);
			} else if( N < x ) {
				printf("O valor de N e menor que %d\n", x);
			} else {
				printf("Parabens... voce acertou\n\n\n");
				break;
			}
			nt++;
			last_n = x;
			printf("\n");
			sleep(2);
		}
		// tela_resultado();
		STATUS = STATUS_INIT;
	}

	

	return 0;
}
