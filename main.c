#include <stdio.h>
#include "kernel.h"
#include "define.h"

int main(){
	int pressionada, posicaoY, *posy, primeiraIteracao=0, finalizar=1;

	_setcursortype(_NOCURSOR);
	setWindowSize();

	posicaoY = 20; // Posição inicial para o menu principal (Aponta para "iniciar")
	posy = &posicaoY;

	do{
		fflush(stdin);
		if(primeiraIteracao == 0){
			drawMainMenu();
			pressionada = 19;
			posicaoY = selecaoMenu(*posy, pressionada, primeiraIteracao);
			primeiraIteracao++;
		} else {
			pressionada = getArrowKey(2);
			if(pressionada == RETURN_KEY){
				switch(posicaoY){
					case 19:	//Iniciar
						loadingScreen();
						init();
//						defeatAnimation();  // Need to fix the animation
						primeiraIteracao = 0;
						*posy = 19;
						system("cls");
						break;
					case 20:	//Highscores
						drawHighscores();
						system("cls");
						drawMainMenu();
						posicaoY = selecaoMenu(19, DOWN_ARROW, 1); // Retorna para o menu principal e coloca um ponteiro em "Highscores".
						break;
					case 21:	//Ajuda
						drawAjuda();
						if(getTeclaSobreAjuda() == RETURN_KEY){
							system("cls");
							drawMainMenu();
							posicaoY = selecaoMenu(20, DOWN_ARROW, 1); // Retorna para o menu principal e coloca um ponteiro em "Ajuda".
						}
						break;
					case 22:	//Sobre
						drawSobre();
						if(getTeclaSobreAjuda() == RETURN_KEY){
							system("cls");
							drawMainMenu();
							posicaoY = selecaoMenu(21, DOWN_ARROW, 1); // Retorna para o menu principal e coloca um ponteiro em "Sobre".
						}
						break;
					case 23:	//Sair
						system("cls");
						finalizar = 0;
						break;
				}
			} else {
				posicaoY = selecaoMenu(*posy, pressionada, primeiraIteracao);
			}
		}
	} while(finalizar);

	return 0;
}


