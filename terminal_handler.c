#include <stdio.h>
#include <string.h>
#include "define.h"
#include "kernel.h"

void defeatAnimation(void){
	int i=0;
	
	system("cls");
	
	for(i=0; i<=10; i++){
		
		Sleep(500);
		textcolor(RED);
		
		if(i%2 == 0){
			gotoxy(80, 2);
			printf("                    ################      ");
			gotoxy(80, 3);
			printf("                 ######################   ");
			gotoxy(80, 4);
			printf("                ########################  ");
			gotoxy(80, 5);
			printf("               ########################## ");
			gotoxy(80, 6);
			printf("              ########################### ");
			gotoxy(80, 7);
			printf("             #############################");
			gotoxy(80, 8);
			printf("             #############################");
			gotoxy(80, 9);
			printf("             #############################");
			gotoxy(80, 10);
			printf("             #############################");
			gotoxy(80, 11);
			printf("             #############################");
			gotoxy(80, 12);
			printf("             #############################");
			gotoxy(80, 13);
			printf("             ## #       #######       # ##");
			gotoxy(80, 14);
			printf("             # #         #####         # #");
			gotoxy(80, 15);
			printf("             ##          #####          ##");
			gotoxy(80, 16);
			printf("             ###       #########       ###");
			gotoxy(80, 17);
			printf("              ############   ############ ");
			gotoxy(80, 18);
			printf("               ##########     ##########  ");
			gotoxy(80, 19);
			printf("                    #####  #  ####        ");
			gotoxy(80, 20);
			printf("                   # ############  #      ");
			gotoxy(80, 21);
			printf("                   #   # #  # #    #      ");
			gotoxy(80, 22);
			printf("                   #              ##      ");
			gotoxy(80, 23);
			printf("                   ### # #  # # ###       ");
			gotoxy(80, 24);
			printf("                    ##############        ");
			gotoxy(80, 25);
			printf("                     ############         ");
			gotoxy(80, 26);
			printf("                       ########           ");
			gotoxy(80, 27);
			printf("                                          ");
			
			textcolor(WHITE);
			gotoxy(5, 4);
			printf("                                         ");
			gotoxy(5, 5);
			printf("  ######      ###    ##     ## ########  ");
			gotoxy(5, 6);
			printf(" ##    ##    ## ##   ###   ### ##        ");
			gotoxy(5, 7);
			printf(" ##         ##   ##  #### #### ##        ");
			gotoxy(5, 8);
			printf(" ##   #### ##     ## ## ### ## ######    ");
			gotoxy(5, 9);
			printf(" ##    ##  ######### ##     ## ##        ");
			gotoxy(5, 10);
			printf(" ##    ##  ##     ## ##     ## ##        ");
			gotoxy(5, 11);
			printf("  ######   ##     ## ##     ## ########  ");
			gotoxy(5, 12);
			printf("                                         ");
			gotoxy(5, 13);
			printf("  #######  ##     ## ######## ########   ");
			gotoxy(5, 14);
			printf(" ##     ## ##     ## ##       ##     ##  ");
			gotoxy(5, 15);
			printf(" ##     ## ##     ## ##       ##     ##  ");
			gotoxy(5, 16);
			printf(" ##     ## ##     ## ######   ########   ");
			gotoxy(5, 17);
			printf(" ##     ##  ##   ##  ##       ##   ##    ");
			gotoxy(5, 18);
			printf(" ##     ##   ## ##   ##       ##    ##   ");
			gotoxy(5, 19);
			printf("  #######     ###    ######## ##     ##  ");
			gotoxy(5, 20);
			printf("                                         ");
			
			gotoxy(91, 29);
		} else {
			gotoxy(80, 2);
			printf("                    ################      ");
			gotoxy(80, 3);
			printf("                 ######################   ");
			gotoxy(80, 4);
			printf("                ########################  ");
			gotoxy(80, 5);
			printf("               ########################## ");
			gotoxy(80, 6);
			printf("              ########################### ");
			gotoxy(80, 7);
			printf("             #############################");
			gotoxy(80, 8);
			printf("             #############################");
			gotoxy(80, 9);
			printf("             #############################");
			gotoxy(80, 10);
			printf("             #############################");
			gotoxy(80, 11);
			printf("             #############################");
			gotoxy(80, 12);
			printf("             #############################");
			gotoxy(80, 13);
			printf("             ## #       #######       # ##");
			gotoxy(80, 14);
			printf("             # #         #####         # #");
			gotoxy(80, 15);
			printf("             ##          #####          ## ");
			gotoxy(80, 16);
			printf("             ###       #########       ###");
			gotoxy(80, 17);
			printf("              ############   ############ ");
			gotoxy(80, 18);
			printf("               ##########     ##########  ");
			gotoxy(80, 19);
			printf("                    #####  #  ####        ");
			gotoxy(80, 20);
			printf("                     ############         ");
			gotoxy(80, 21);
			printf("                   #   # #  # #    #      ");
			gotoxy(80, 22);
			printf("                   #               #");
			gotoxy(80, 23);
			printf("                   ##             ##      ");
			gotoxy(80, 24);
			printf("                    ## # #  # # ##        ");
			gotoxy(80, 25);
			printf("                    ##############        ");
			gotoxy(80, 26);
			printf("                     ############         ");
			gotoxy(80, 27);
			printf("                       ########           ");
			
			textcolor(WHITE);
			gotoxy(5, 4);
			printf("........................................");
			gotoxy(5, 5);
			printf("..######......###....##.....##.########.");
			gotoxy(5, 6);
			printf(".##....##....##.##...###...###.##.......");
			gotoxy(5, 7);
			printf(".##.........##...##..####.####.##.......");
			gotoxy(5, 8);
			printf(".##...####.##.....##.##.###.##.######...");
			gotoxy(5, 9);
			printf(".##....##..#########.##.....##.##.......");
			gotoxy(5, 10);
			printf(".##....##..##.....##.##.....##.##.......");
			gotoxy(5, 11);
			printf("..######...##.....##.##.....##.########.");
			gotoxy(5, 12);
			printf("........................................");
			gotoxy(5, 13);
			printf("..#######..##.....##.########.########..");
			gotoxy(5, 14);
			printf(".##.....##.##.....##.##.......##.....##.");
			gotoxy(5, 15);
			printf(".##.....##.##.....##.##.......##.....##.");
			gotoxy(5, 16);
			printf(".##.....##.##.....##.######...########..");
			gotoxy(5, 17);
			printf(".##.....##..##...##..##.......##...##...");
			gotoxy(5, 18);
			printf(".##.....##...##.##...##.......##....##..");
			gotoxy(5, 19);
			printf("..#######.....###....########.##.....##.");
			gotoxy(5, 20);
			printf("........................................");
			
			gotoxy(91, 29);
		}
		
		textcolor(WHITE);
	}
	
	Sleep(300);
	system("cls");
}

int loadingScreen(void){
	int x, i;
	float c;
	char loading[30], a=176, b=219; // "a" e "b" são caracteres da animação de loading.
	
	system("cls");
	
	for(x=0; x<30; x++){
		loading[x] = a;
	}
	
	for(x=0; x<30; x++){
		
		c = x;
		
		Sleep(50);
		gotoxy(65, 21);
		printf("Carregando %.1f%c \n", c*3.448, 37);
		loading[x]= b;
		for(i=0; i<30; i++){
			if(loading[i] == b){
				gotoxy(58+i, 22);
				textcolor(LIGHTCYAN);
			} else {
				textcolor(WHITE);
			}
			printf("%c", loading[i]);
		}
	}
	
	Sleep(300);
	system("cls");
	return 1;
}

void _clearLine(int inicio, int fim){
	int i;

	for(i=inicio; i<=fim; i++){
		gotoxy(67, i);
		printf(" ");
	}
}

void drawLogo(void){
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
}

void drawMenuOptions(void){
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

void drawSobre(void){
	system("cls");

	textcolor(LIGHTCYAN);
	gotoxy(65, 11);
	printf("~ Sobre os devs ~");
	textcolor(WHITE);
	gotoxy(39, 14);
	printf("Nome: Rafael Coracini Basso");
	gotoxy(39, 16);
	printf("Idade: 18 Anos");
	gotoxy(79, 14);
	printf("Nome: Paulo C%csar de Lima Rocha", 130);
	gotoxy(79, 16);
	printf("Idade: 19 Anos");
	gotoxy(39, 19);
	printf("Nome: Iorgers Costa de Almeida", 130);
	gotoxy(39, 21);
	printf("Idade: 22 Anos");

	gotoxy(65, 24);
	textcolor(LIGHTCYAN);
	printf("~ Sobre o Projeto ~");
	gotoxy(42, 27);
	textcolor(WHITE);
	printf("Este projeto foi desenvolvido como Trabalho Final(TF), para a mat%cria", 130);
	gotoxy(39, 28);
	printf("de \"Programa%c%co Estruturada\", do curso de Ci%cncia da Computa%c%co e de", 135, 131, 136, 135, 131);
	gotoxy(39, 29);
	printf("Engenharia de Software da Universidade Cat%clica de Bras%clia.", 162, 161);

	gotoxy(122, 40);
	printf("Voltar");
}

void drawHighscores(void){
	int i, x=0;
	
	system("cls");
	
	textcolor(WHITE);
	gotoxy(65, 20);
	printf("WORK IN PROGRESS");
	
	while(x < 3){
		for(i=1; i <= 5; i++){
			switch(i){
				case 1:
					gotoxy(83 ,20);
					textcolor(LIGHTBLUE);
					printf("|");
					break;
					
				case 2:
					gotoxy(83 ,20);
					textcolor(LIGHTGREEN);
					printf("/");
					break;
					
				case 3:
					gotoxy(83 ,20);
					textcolor(LIGHTCYAN);
					printf("-");
					break;
					
				case 4:
					gotoxy(83 ,20);
					textcolor(LIGHTRED);
					printf("\\");
					break;
					
				case 5:
					gotoxy(83 ,20);
					textcolor(LIGHTMAGENTA);
					printf("|");
					break;
			}
			
			Sleep(150);
		}
		x++;
	}
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
		_clearLine(29, 33);
	}

	switch(posicao){
		case 19:
			_clearLine(29, 33);
			if(tecla == UP_ARROW){
				gotoxy(67, 33);
				printf("%c", 175);
				posicaoFinal = 23;
			} else if(tecla == DOWN_ARROW){
				gotoxy(67, 30);
				printf("%c", 175);
				posicaoFinal = 20;
			}
			break;
		case 20:
			if(tecla == UP_ARROW){
				gotoxy(67, 29);
				printf("%c", 175);
				posicaoFinal = 19;
			} else if(tecla == DOWN_ARROW){
				gotoxy(67, 31);
				printf("%c", 175);
				posicaoFinal = 21;
			}
			break;
		case 21:
			if(tecla == UP_ARROW){
				gotoxy(67, 30);
				printf("%c", 175);
				posicaoFinal = 20;
			} else if(tecla == DOWN_ARROW){
				gotoxy(67, 32);
				printf("%c", 175);
				posicaoFinal = 22;
			}
			break;
		case 22:
			if(tecla == UP_ARROW){
				gotoxy(67, 31);
				printf("%c", 175);
				posicaoFinal = 21;
			} else if(tecla == DOWN_ARROW){
				gotoxy(67, 33);
				printf("%c", 175);
				posicaoFinal = 23;
			}
			break;
		case 23:
			if(tecla == UP_ARROW){
				gotoxy(67, 32);
				printf("%c", 175);
				posicaoFinal = 22;
			} else if(tecla == DOWN_ARROW){
				gotoxy(67, 29);
				printf("%c", 175);
				posicaoFinal = 19;
			}
			break;
	}

	gotoxy(151, 44);
	return posicaoFinal;
}

void drawAjuda(void){
	system("cls");
//	drawWalls(0);

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

void drawMainMenu(void){
	drawLogo();
	drawMenuOptions();
}

void drawBox(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int i;
	
	textcolor(WHITE);
		
	gotoxy(x1, y1);   // Draw left upper corner 
	printf("%c", 218);
	
	gotoxy(x2, y2);   // Draw left lower corner
	printf("%c", 192);
	
	gotoxy(x3, y3);   // Draw right lower corner
	printf("%c", 217);
	
	gotoxy(x4, y4);   // Draw right upper corner
	printf("%c", 191);
	
	for(i=x1; i<x4-1; i++){
		gotoxy(i+1, y1);
		printf("%c", 196);
	}
	
	for(i=x2; i<x3-1; i++){
		gotoxy(i+1, y2);
		printf("%c", 196);
	}
	
	for(i=y1; i<y2-1; i++){
		gotoxy(x1, i+1);
		printf("%c", 179);
	}
	
	for(i=y4; i<y3-1; i++){
		gotoxy(x4, i+1);
		printf("%c", 179);
	}

}

void drawDivision(int x, int y1, int y2){
	int i;
	
	gotoxy(x,y1);
	printf("%c", 194);
	
	gotoxy(x,y2);
	printf("%c", 193);
	
	for(i=y1;i<y2-1;i++){
		gotoxy(x,i+1);
		printf("%c", 179);
	}
}

void drawMultipleDivisions(int *posXArray, int y1, int y2, int divisionsQnt){
	int count;
	
	for(count=0; count<divisionsQnt;count++){
		drawDivision(posXArray[count] , y1, y2);
	}
}

void drawInputLocation(void){
	gotoxy(5, 43);
	printf("<                                           >");
}

void *drawGameDifficulty(void *info){
	int difficulty = ((struct GAME_INFO *)info)->difficulty;
	
	gotoxy(112, 43);
	printf("Difficulty:       ");
	gotoxy(124, 43);
	
	switch(difficulty){
		case EASY:
			textcolor(GREEN);
			printf(" EASY");
			break;
			
		case MEDIUM:
			textcolor(BLUE);
			printf("MEDIUM");
			break;
			
		case HARD:
			textcolor(YELLOW);
			printf(" HARD");
			break;
			
		case PRO:
			textcolor(RED);
			printf("  PRO");
			break;
	}
	
	textcolor(WHITE);
	
	return NULL;
}

void *drawGameScore(void *info){
	int score = ((struct GAME_INFO *)info)->score;
	
	gotoxy(135, 43);
	printf("Score: %6d", score);
	
	return NULL;
}

void *drawGameErrors(int qntErrors){
	
	gotoxy(97, 43);
	printf("Errors: %2d", qntErrors);
	
	return NULL;
}

void clearLine(int posY){
	gotoxy(0, posY);
	printf("                                                                                                                                                     ");
}

void *drawWordOnScreen(struct WORD *wordOnScreen, int wordIndex, int option){
	
	switch(option){
		case 1:
			gotoxy(wordOnScreen[wordIndex].posX, wordOnScreen[wordIndex].posY);
			printf("%s", wordOnScreen[wordIndex].string);
			break;
			
		case 2:
			if(wordOnScreen[wordIndex].posY + 1 == 42){
				strcpy(wordOnScreen[wordIndex].string, "");
			} else {
				wordOnScreen[wordIndex].posY += 1;
			}
			break;
			
		case 3:
			
			break;
	}
	
}



