#include <stdio.h>
#include "define.h"
#include "kernel.h"

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
	printf("<                              >");
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
	gotoxy(1, posY);
	printf("                                                                                                                                                    ");
}

void *drawWord(void *wordOnScreen){
	
	
}



