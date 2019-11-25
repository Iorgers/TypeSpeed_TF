#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "kernel.h"
#include "keyboard_handler.h"
#include "terminal_handler.h"
#include "define.h"

//------------------------------------------------------------------------------------------------------------------------------------------------//
//
//                                                           Conio2.c functions                                                                   //
//
//------------------------------------------------------------------------------------------------------------------------------------------------//


text_info2 vActual2 = {0, 0, 79, 24, WHITE, WHITE, 3, 25, 80, 1, 1};

void clrscr(void){
   system("cls");
}

void gotoxy(int x, int y){
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void _setcursortype(int cur_t){
   CONSOLE_CURSOR_INFO cci;

   switch(cur_t) {
      case _NOCURSOR:
         cci.dwSize = 100;
         cci.bVisible = FALSE;
         break;
      case _SOLIDCURSOR:
         cci.dwSize = 100;
         cci.bVisible = TRUE;
         break;
      case _NORMALCURSOR:
         cci.dwSize = 10;
         cci.bVisible = TRUE;
         break;
   }
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void textbackground(int newcolor){
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0x0f) | (newcolor << 4));
   vActual2.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}

void textcolor(int newcolor){
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0xf0) | newcolor);
   vActual2.attribute = (csbi.wAttributes & 0xf0) | newcolor;
}


//------------------------------------------------------------------------------------------------------------------------------------------------//
//
//                                                        End of Conio2.c functions                                                               //
//
//------------------------------------------------------------------------------------------------------------------------------------------------//


//------------------------------------------------------------------------------------------------------------------------------------------------//
//
//                                                             Game functions                                                                     //
//
//------------------------------------------------------------------------------------------------------------------------------------------------//


void getMonitorResolution(unsigned int *horizontal, unsigned int *vertical) {
    *horizontal = GetSystemMetrics(SM_CXSCREEN);
	*vertical = GetSystemMetrics(SM_CYSCREEN);
}

void setWindowSize(void){
	unsigned int winHeight, winWidth;
	int command_string_size = 29; 	  	// This value stands for the sum of the command text below, plus the value of 8 chars 
	                        			// which relates to the possible width and height of the console window.
	char command[command_string_size];
	
	if(IS_RELATIVE_WINDOW_SIZE==TRUE){
		getMonitorResolution(&winWidth, &winHeight);
	
		sprintf(command, "MODE con cols=%d lines=%d", winWidth, winHeight);
		system(command);
	} else {
		system("MODE con cols=150 lines=45");
	}
}

void init_settings(void *info){
	((struct GAME_INFO *)info) -> difficulty = 0; // 0-EASY  1-MEDIUM  2-HARD  3-PRO
	((struct GAME_INFO *)info) -> score      = 0;
	
	srand(time(0));
	
	setWindowSize();
	
	_setcursortype(_NOCURSOR);
	
	drawBox(0, 42, 0, 44, 149, 44, 149, 42);
	
	switch(((struct GAME_INFO *)info) -> difficulty){
		case EASY:
			((struct GAME_INFO *)info)->speed    = 1;
			((struct GAME_INFO *)info) -> errors = 10;
			break;
			
		case MEDIUM:
			((struct GAME_INFO *)info)->speed    = 2;
			((struct GAME_INFO *)info) -> errors = 8;
			break;
			
		case HARD:
			((struct GAME_INFO *)info)->speed    = 3;
			((struct GAME_INFO *)info) -> errors = 6;
			break;
			
		case PRO:
			((struct GAME_INFO *)info)->speed    = 4;
			((struct GAME_INFO *)info) -> errors = 4;
			break;
	}	
}

void createNewWord(struct WORD *newWord, char *string, int wordIndex, int speedMultiplier){
	strcpy(newWord[wordIndex].string, string);                       // Copy the string
	newWord[wordIndex].size  = strlength(string);                    // Copy the size
	newWord[wordIndex].posY  = 0;                                    // Copy PosX
	newWord[wordIndex].posX  = rand() % 149-newWord[wordIndex].size; // Copy PosY
	newWord[wordIndex].speed = speedMultiplier;                      // Copy speed
	newWord[wordIndex].index = wordIndex;                            // Copy the index of the word
	newWord[wordIndex].color = WHITE;                                 // Sets the color to white
}

void deleteWord(struct WORD *deleteWord, int index){
	strcpy(deleteWord[index].string, "");   // Delete the string
	deleteWord[index].size  = 0;            // Delete the size
	deleteWord[index].posX  = 0;            // Delete PosX
	deleteWord[index].posY  = 0;            // Delete PosY
	deleteWord[index].speed = 0;            // Delete speed
	deleteWord[index].index = -1;           // Delete the index of the word
}

int checkWord(char *string, char availableWords[][DEFAULT_STRING_LENGTH], int availableWordsQnt){
	int i;
	char *tmp_word;

	for(i=0; i<availableWordsQnt; i++){
		
		tmp_word = (char *) malloc(sizeof(char)*DEFAULT_STRING_LENGTH);
		
		strcpy(tmp_word, availableWords[i]);
		
		if(stringCompare(string, tmp_word)==1){
			free(tmp_word);
			return i;
		} else {
			free(tmp_word);
		}
	}
	
	return -1;
}

void orderWordsIndexes(struct WORD *wordIndex, char wordsOnScreen[][DEFAULT_STRING_LENGTH], int indexToDelete, int *availableWordsQnt){
	int i, tmp, x;
	
	for(i=indexToDelete; i<*availableWordsQnt; i++){
		
		strcpy(wordsOnScreen[i], wordsOnScreen[i+1]);
		
		if(i!=indexToDelete){
			for(x=indexToDelete; x<*availableWordsQnt;x++){
				wordIndex[x].index -= 1;
			}	
		}
	}
	
	availableWordsQnt -= 1;
}


//------------------------------------------------------------------------------------------------------------------------------------------------//
//                                                           Global Variables                                                                     //
//------------------------------------------------------------------------------------------------------------------------------------------------//

	pthread_t wordThread[MAX_KEYS_ON_SCREEN];

void init(void){
//------------------------------------------------------------------------------------------------------------------------------------------------//
//                                                               Variables                                                                        //
//------------------------------------------------------------------------------------------------------------------------------------------------//

	int x=0, lastWordPosY=0, wordsOnScreenQnt=0, qntErrors=0, randomIndex, checkWordIndex;
	
	char string[DEFAULT_STRING_LENGTH];
	
	struct GAME_INFO *stats;
	
	stats = (void*) malloc(sizeof(struct GAME_INFO));
	
	word words[MAX_KEYS_ON_SCREEN];
	
	char dictionary[MAX_KEYS_ON_SCREEN][DEFAULT_STRING_LENGTH]={
		"TESTE",
		"AMOR",
		"ANO",
		"ANJO",
		"BALEIA",
		"BRINCAR",
		"BATOM",
		"BATATA",
		"BOCA",
		"BIBLIA",
		"BEXIGA",
		"RECURSIVIDADE",
		"LOOP",
		"AVENTAL",
		"COR",
		"BEAT",
		"DADO",
		"CALOR",
		"CASA",
		"CABIDE"
	};
	
	char wordsOnScreen[MAX_KEYS_ON_SCREEN][DEFAULT_STRING_LENGTH];
	
	int posXArray[3]={
		94,
		109,
		132
	};
	
//------------------------------------------------------------------------------------------------------------------------------------------------//
//                                                             Game settings                                                                      //
//------------------------------------------------------------------------------------------------------------------------------------------------//
	
	init_settings(stats);
	
//------------------------------------------------------------------------------------------------------------------------------------------------//
//                                                               Execution                                                                        //
//------------------------------------------------------------------------------------------------------------------------------------------------//
	
	
	// Beggining of main loop
	while(qntErrors < stats-> errors){
		
		clearLine(43);
		drawMultipleDivisions(posXArray, 42, 44, 3);
		
		drawInputLocation();
		drawGameDifficulty(stats);
		drawGameScore(stats);
		drawGameErrors(qntErrors);
		
		
		randomIndex = rand() % MAX_KEYS_ON_SCREEN;
			
		strcpy(wordsOnScreen[wordsOnScreenQnt], dictionary[randomIndex]);
		
		createNewWord(words, wordsOnScreen[wordsOnScreenQnt], wordsOnScreenQnt, stats->speed);
		
		for(x=0;x<=wordsOnScreenQnt;x++){
			clearLine(x);
			gotoxy(0, x);
			printf("%s   ", words[x].string);
			printf("%d", words[x].index);
		}	
		
		getUpperCaseString(string);
		
		checkWordIndex = checkWord(string, wordsOnScreen, wordsOnScreenQnt);
		
		gotoxy(40, 0);
		printf("%d", checkWordIndex);
		getch();
			
		if(checkWordIndex >= 0){
			stats-> score += 300;
			deleteWord(words, checkWordIndex);
			orderWordsIndexes(words, wordsOnScreen, checkWordIndex, &wordsOnScreenQnt);
		} else {
			qntErrors++;
		}
		
		for(x=0;x<wordsOnScreenQnt;x++){
			if(words[x].posY==41){
				deleteWord(words, words[x].index);
				orderWordsIndexes(words, wordsOnScreen, x, &wordsOnScreenQnt);
				
				stats->errors += 1;
				wordsOnScreenQnt--;
			}
		}
		
		wordsOnScreenQnt++;
		
	}
	
	gotoxy(0,0);
	printf("GAME OVER");
	
	// End of main loop
}

//------------------------------------------------------------------------------------------------------------------------------------------------//
//
//                                                         End of Game functions                                                                  //
//
//------------------------------------------------------------------------------------------------------------------------------------------------//
