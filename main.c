#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include "kernel.h"
#include "define.h"

#define CIMA 72
#define BAIXO 80
#define ENTER 13

textcolor2 (int color){
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    color + (__BACKGROUND << 4));
    
}

void drawWalls(){
	int x;
	
	textcolor(WHITE);
	
	gotoxy(0,0);
	printf("%c", 201);
	
	for(x=0; x<45; x++){ // Linha da Esquerda
		if(x!=0){
			gotoxy(0, x);
			printf("%c", 186);
		}
	}
	
	for(x=1; x<150; x++){ // linha de Cima
		gotoxy(x, 0);
		printf("%c", 205);
	}
	
	for(x=1; x<45; x++){ // Linha Direita
		if(x==1){
			printf("%c", 187);
		} else {
			gotoxy(150, x-1);
			printf("%c", 186);
		}
	}
	
	for(x=0; x<151; x++){ // Linha de Baixo
		if(x==0){
			printf("\n%c", 200);
		} else {
			if(x==150){
				printf("%c", 188);
			} else {	
				gotoxy(x, 44);
				printf("%c", 205);
			}
		}
	}
	
	gotoxy(2, 43);
	textcolor(WHITE);
	printf("Beta 0.1 (nov-2019)");
}

void drawLogo(){
		textcolor(WHITE);
		gotoxy(15, 10);
		printf("       ::::::::  :::::::::  :::::::::: :::::::::: :::::::::    ::::::::::: :::   ::: :::::::::  :::::::::: :::::::::");
		gotoxy(15, 11);
		printf("     :+:    :+: :+:    :+: :+:        :+:        :+:    :+:        :+:     :+:   :+: :+:    :+: :+:        :+:    :+:");
		gotoxy(15, 12);
		printf("    +:+        +:+    +:+ +:+        +:+        +:+    +:+         +:+      +:+ +:+  +:+    +:+ +:+        +:+    +:+");
		gotoxy(15, 13);
		printf("   +#++:++#++ +#++:++#+  +#++:++#   +#++:++#   +#+    +:+          +#+       +#++:   +#++:++#+  +#++:++#   +#++:++#:");
		gotoxy(15, 14);
		printf("         +#+ +#+        +#+        +#+        +#+    +#+           +#+        +#+    +#+        +#+        +#+    +#+");
		gotoxy(15, 15);
		printf(" #+#    #+# #+#        #+#        #+#        #+#    #+#            #+#        #+#    #+#        #+#        #+#    #+#");
		gotoxy(15, 16);
		printf(" ########  ###        ########## ########## #########              ###        ###    ###        ########## ###    ###");
//		gotoxy(24, 9);
//		printf("             |___/                      ");
//		gotoxy(26, 10);
//		printf("       ______                           ");
//		gotoxy(26, 11);
//		printf("      |  ___|                           ");
//		gotoxy(26, 12);
//		printf("      | |_ ___  _ __ ___ __ _           ");
//		gotoxy(26, 13);
//		printf("      |  _/ _ \\| '__/ __/ _` |         ");
//		gotoxy(26, 14);
//		printf("      | || (_) | | | (_| (_| |          ");
//		gotoxy(26, 15);
//		printf("      \\_| \\___/|_|  \\___\\__,_|      ");
}

void drawMenuOptions(){
	textcolor(WHITE);
	gotoxy(70, 29);
	printf("Iniciar");
	gotoxy(70, 30);
	printf("HighScores");
	gotoxy(70, 31);
	printf("Ajuda");
	gotoxy(70, 32);
	printf("Sobre");
	gotoxy(70, 33);
	printf("Sair");
}

void drawSobre(){
	system("cls");
	drawWalls(0);
	
	textcolor(LIGHTCYAN);
	gotoxy(65, 11);
	printf("~ Sobre os devs ~");
	textcolor(WHITE);
	gotoxy(39, 14);
	printf("Nome: Rafael Coracini Basso");
	gotoxy(39, 16);
	printf("Idade: 17 Anos");
	gotoxy(79, 14);
	printf("Nome: Paulo C%csar de Lima Rocha", 130);
	gotoxy(79, 16);
	printf("Idade: 19 Anos");
	
	gotoxy(65, 21);
	textcolor(LIGHTCYAN);
	printf("~ Sobre o Projeto ~", 135, 198);
	gotoxy(42, 24);
	textcolor(WHITE);
	printf("Este projeto foi desenvolvido como Trabalho Final(TF), para a mat%cria", 130);
	gotoxy(39, 25);
	printf("de \"Programa%c%co Estruturada\", do curso de Ci%cncia da Computa%c%co e de", 135, 131, 136, 135, 131);
	gotoxy(39, 26);
	printf("Engenharia de Software da Universidade Cat%clica de Bras%clia.", 162, 161);
	
	gotoxy(55, 33);
	printf("\"Se for para fazer algo, fa%ca bem feito\"", 135);
	
	gotoxy(122, 40);
	printf("Voltar");
}

void drawAjuda(){
	system("cls");
	drawWalls(0);
	
	textcolor(WHITE);
	gotoxy(65, 11);
	printf("~ AJUDA ~");
	gotoxy(29, 14);
	
	textcolor(LIGHTCYAN);
	printf("Defini%cao:", 135);
	textcolor(WHITE);
	gotoxy(41, 14);
	printf("SpeedTyper %c um jogo em que o jogador deve digitar as palavras aparecendo na", 130);
	gotoxy(29, 15);
	printf("tela o mais r%cpido poss%cvel antes que a palavra desapare%ca da tela e adquirir o m%cximo", 160, 161, 135, 160);
	gotoxy(29, 16);
	printf("de pontos. Cada palavra perdida resultar%c numa perda de pontos no score do jogador.", 160);
	gotoxy(29, 17);
	printf("O jogo termina ap%cs 10 erros de digita%c%co.", 162, 135, 131);
	gotoxy(29, 18);
	printf("");
	
	gotoxy(29, 20);
	textcolor(LIGHTCYAN);
	printf("Como jogar:");
	gotoxy(32, 22);
	printf("1%c", 167);
	gotoxy(32, 25);
	printf("2%c", 167);
	gotoxy(32, 27);
	printf("3%c", 167);
	gotoxy(32, 29);
	printf("4%c", 167);
	gotoxy(32, 31);
	printf("5%c", 167);
	textcolor(WHITE);
	gotoxy(35, 22);
	printf("O jogador poder%c escolher entre quatro dificuldades (F%ccil, M%cdio, Dif%ccil e Pro),", 160, 160, 130, 161);
	gotoxy(35, 23);
	printf("que ir%c determinar a complexidade e o tamanho das palavras.", 160);
	gotoxy(35, 25);
	printf("O jogador ter%c tempo ilimitado para conseguir a maior quantia de pontos poss%cvel.", 160, 161);
	gotoxy(35, 27);
	printf("Cada palavra errada aferar%c negativamente o score do jogador.", 160);
	gotoxy(35, 29);
	printf("A dificuldade aumentar%c gradativamente com o decorrer do score do jogador.", 160);
	gotoxy(35, 31);
	printf("O jogo acaba quando o jogador cometer 10 erros.", 130);
	
	gotoxy(122, 40);
	printf("Voltar");
}

void drawMainMenu(){
	drawWalls();
	drawLogo();
	drawMenuOptions();
}

int getTeclaMenuPrincipal(){
	short cima, baixo, enter;
	
	do{
		Sleep(150);
		drawLogo();
		
		gotoxy(91, 29);
		
		fflush(stdin);
		
		cima = GetAsyncKeyState(VK_UP);
		baixo = GetAsyncKeyState(VK_DOWN);
		enter = GetAsyncKeyState(VK_RETURN);
	
		if(cima){
			return CIMA;
		} else if(baixo) {
			return BAIXO;
		} else if(enter) {
			return ENTER;
		}
	}while(!enter); // enter == 0
}

int getTeclaSobreAjuda(){
	int tecla=0, pisca=0;
	short enter;
	
	do{	
		gotoxy(120, 40);
		Sleep(400);
		if(pisca == 0){
			textcolor(WHITE);
			printf("%c", 175);
			pisca++;
		} else {
			textcolor(BLACK);
			printf("%c", 175);
			pisca--;
		}
		gotoxy(91, 29);
		
		enter = GetAsyncKeyState(VK_RETURN);
	
		if(enter) {
			tecla = ENTER;
		}
	}while(!enter); // enter == 0
	
	return tecla;
}

int loadingScreen(){
	int x, i;
	float c;
	char loading[30], a=176, b=219; // "a" e "b" são caracteres da animação de loading.
	
	for(x=0; x<30; x++){
		loading[x] = a;
		gotoxy(30+x, 14);
		printf("%c", loading[x]);
	}
	
	for(x=0; x<30; x++){
		
		c = x;
		
		Sleep(45);
		gotoxy(37, 13);
		printf("Carregando %.1f%c \n", c*3.448, 37);
		loading[x]= b;
		for(i=0; i<30; i++){
			if(loading[i] == b){
				gotoxy(30+i, 14);
				textcolor(LIGHTCYAN);
			} else {
				textcolor(WHITE);
			}
			printf("%c", loading[i]);
		}
	}
	
	Sleep(250);
	system("cls");
	return 1;
}

int selecaoMenu(int posicao, int tecla, int contador){
	int posicaoFinal;
	
	textcolor(WHITE);
	
	if(contador == 0){
		gotoxy(67, 29);
		printf("%c", 175);
		posicaoFinal = 19;
		gotoxy(151, 44);
		return posicaoFinal;
	} else {
		clearLine(29);
		clearLine(30);
		clearLine(31);
		clearLine(32);
		clearLine(33);
		drawMenuOptions();
	}
	
	switch(posicao){
		case 19:
			clearLine(29);
			clearLine(30);
			clearLine(31);
			clearLine(32);
			clearLine(33);
			drawMenuOptions();
			if(tecla == CIMA){
				gotoxy(67, 33);
				printf("%c", 175);
				posicaoFinal = 23;
			} else if(tecla == BAIXO){
				gotoxy(67, 30);
				printf("%c", 175);
				posicaoFinal = 20;
			}
			break;
		case 20:
			if(tecla == CIMA){
				gotoxy(67, 29);
				printf("%c", 175);
				posicaoFinal = 19;
			} else if(tecla == BAIXO){
				gotoxy(67, 31);
				printf("%c", 175);
				posicaoFinal = 21;
			}
			break;
		case 21:
			if(tecla == CIMA){
				gotoxy(67, 30);
				printf("%c", 175);
				posicaoFinal = 20;
			} else if(tecla == BAIXO){
				gotoxy(67, 32);
				printf("%c", 175);
				posicaoFinal = 22;
			}
			break;
		case 22:
			if(tecla == CIMA){
				gotoxy(67, 31);
				printf("%c", 175);
				posicaoFinal = 21;
			} else if(tecla == BAIXO){
				gotoxy(67, 33);
				printf("%c", 175);
				posicaoFinal = 23;
			}
			break;
		case 23:
			if(tecla == CIMA){
				gotoxy(67, 32);
				printf("%c", 175);
				posicaoFinal = 22;
			} else if(tecla == BAIXO){
				gotoxy(67, 29);
				printf("%c", 175);
				posicaoFinal = 19;
			}
			break;
	}
	
	gotoxy(151, 44);
	return posicaoFinal;
}

int main(void){
	
	_setcursortype(0); 
	int pressionada, posicaoY, *posy, primeiraIteracao=0, finalizar=1, ganhouPerdeu;
	
	setlocale(LC_ALL, NULL);
	system("MODE con cols=151 lines=45");
	
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
			Sleep(150);
			pressionada = getTeclaMenuPrincipal();
			if(pressionada == ENTER){
				switch(posicaoY){
					case 19:	//Iniciar
						system("cls");
						if (loadingScreen()) {
							init();
							main();
						}
						break;
					case 20:	//Highscores
						system("cls");
						
						break;
					case 21:	//Ajuda
						drawAjuda();
						if(getTeclaSobreAjuda() == ENTER){
							system("cls");
							drawMainMenu();
							posicaoY = selecaoMenu(20, BAIXO, 1); // Retorna para o menu principal e coloca um ponteiro em "Ajuda".
						}
						break;
					case 22:	//Sobre
						drawSobre();
						if(getTeclaSobreAjuda() == ENTER){
							system("cls");
							drawMainMenu();
							posicaoY = selecaoMenu(21, BAIXO, 1); // Retorna para o menu principal e coloca um ponteiro em "Sobre".
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

