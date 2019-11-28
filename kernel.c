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
	
	drawBox(0, 42, 0, 44, 149, 44, 149, 42);
	
	switch(((struct GAME_INFO *)info) -> difficulty){
		case EASY:
			((struct GAME_INFO *)info) -> speed           = 1;
			((struct GAME_INFO *)info) -> errors          = 16;
			((struct GAME_INFO *)info) -> scoreMultiplier = 1;
			break;
			
		case MEDIUM:
			((struct GAME_INFO *)info) -> speed           = 2;
			((struct GAME_INFO *)info) -> errors          = 12;
			((struct GAME_INFO *)info) -> scoreMultiplier = 2;
			break;
			
		case HARD:
			((struct GAME_INFO *)info) -> speed           = 3;
			((struct GAME_INFO *)info) -> errors          = 8;
			((struct GAME_INFO *)info) -> scoreMultiplier = 3;
			break;
			
		case PRO:
			((struct GAME_INFO *)info) -> speed           = 4;
			((struct GAME_INFO *)info) -> errors          = 5;
			((struct GAME_INFO *)info) -> scoreMultiplier = 5;
			break;
	}	
}

void createNewWord(word newWord[], char *string, int wordIndex, int speedMultiplier){
	strcpy(newWord[wordIndex].string, string);                       // Copy the string
	newWord[wordIndex].size  = strlength(string)+1;                    // Copy the size
	newWord[wordIndex].posY  = 0;                                    // Copy PosX
	newWord[wordIndex].posX  = rand() % 149-newWord[wordIndex].size; // Copy PosY
	newWord[wordIndex].speed = speedMultiplier;                      // Copy speed
	newWord[wordIndex].color = LIGHTGREEN;                                 // Sets the color to white
}

void deleteWord(word words[], int toRemove, int wordsOnScreenQnt){
	
	int i;
	
	for(i = toRemove; i < wordsOnScreenQnt; i++){
		words[i] = words[i+1];
	}
	
}

int checkWord(char *string, word availableWords[], int availableWordsQnt){
	int i;

	for(i=0; i<availableWordsQnt; i++){
		
		if(stringCompare(string, availableWords[i].string)==1){
			return i;
		}
		if(stringCompare(string, "CCBBEDEDBA")==1){
			return 100;
		}
	}
	
	return -1;
}

int randomYPosition(word words[], int availableWordsQnt){
	int i, randomIndex, notAvailable=1;
	
	if(availableWordsQnt==0){
		
		randomIndex = rand() % 38;
		
	} else {
		
		while(notAvailable > 0){
			
			notAvailable = 0;
			
			randomIndex = rand()%38;
			
			for(i=0;i<availableWordsQnt;i++){
				if(randomIndex == words[i].posY){
					notAvailable++;
				}
			}	
		}
	}
	
	return randomIndex;
	
}

int init(void){
//------------------------------------------------------------------------------------------------------------------------------------------------//
//                                                               Variables                                                                        //
//------------------------------------------------------------------------------------------------------------------------------------------------//

	int x=0, wordsOnScreenQnt=0, qntErrors=0, randomIndex, checkWordIndex;	
	char string[DEFAULT_STRING_LENGTH];
	
	struct GAME_INFO *stats;
	
	HIGHSCORE highscoreInformations;
	
	stats = (void*) malloc(sizeof(struct GAME_INFO));
	
	word words[MAX_KEYS_ON_SCREEN];
	
	int posXArray[3]={
		94,
		109,
		132
	};
	
	char dictionaryEASY[MAX_KEYS_ON_SCREEN][DEFAULT_STRING_LENGTH]={
		"LASER",
		"BUG",
		"CORSA",
		"VAGAS",
		"POLVO",
		"BRASIL",
		"CHAVE",
		"SAPATO",
		"PAPEL",
		"CABO",
		"MONDIAL",
		"SOL",
		"PAGODE",
		"PORTA",
		"PLANTA",
		"HUMANO",
		"MESA",
		"LUZ",
		"PLANETA",
		"FOTO"
	};
	
	char dictionaryMEDIUM[MAX_KEYS_ON_SCREEN][DEFAULT_STRING_LENGTH]={
		"SABONETE",
		"GROISMAN",
		"SENNINHA",
		"PALINDROMO",
		"MACHADO",
		"UNIVERSIDADE",
		"IBIRAPUERA",
		"DARWIN",
		"RECURSIVIDADE",
		"BRIOCHE",
		"BRICOLAGEM",
		"ERUDITO",
		"GEMATRIA",
		"SALGADO",
		"TRITONGO",
		"ZURETA",
		"ATOSSICAR",
		"DIPIRONA",
		"FONTURA",
		"ENTROPIA"
	};
	
	char dictionaryHARD[MAX_KEYS_ON_SCREEN][DEFAULT_STRING_LENGTH]={
		"MASSARANDUBA",
		"CHIKUNGUNYA",
		"ECMNESIA",
		"MITSUBISHI",
		"HELIOPATIA",
		"CHAMPIGNON",
		"BUONARROTI",
		"HEXAEDRO",
		"TERGIVERSAR",
		"TUNGSTENIO",
		"KOEGNIGSEGG",
		"PARALELEPIPEDO",
		"ICONOCLASTA",
		"INHOMIRIM",
		"CATAPULTA",
		"TRABUCO",
		"ESTALACTITE",
		"EXCALIBUR",
		"DRUMMOND ",
		"TAXIDERMISTA "
	};
	
	char dictionaryPRO[MAX_KEYS_ON_SCREEN][DEFAULT_STRING_LENGTH]={
		"INFUNDIBULIFORME",
		"PARADICLOROBENZENO",
		"SCHWARZENEGGER",
		"ANTICONSTITUCIONALISMO",
		"SCHRODINGER",
		"ORNITORRINCO",
		"PNEUMOULTRAMICROSCOPICOSSILICOVULCANOCONIOSE",
		"SCHOPENHAUER",
		"SCHNAUZER",
		"MENINGOENCEFALOMIELITE",
		"TRAQUELATLOIDOCCIPITAL",
		"IDIOSSINCRASIA",
		"REINDUSTRIALIZAR",
		"OTORRINOLARINGOLOGISTA ",
		"DESOXIRRIBONUCLEICO",
		"MONOSIALOTETRAESOSILGANGLIOSIDEO",
		"MILTIDISCIPLINARIDADE",
		"DESPROPORCIONALIZAR",
		"EXTRATERRITORIALIDADE",
		"OTORRINOLARINGOLOGISTA"
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
		drawBox(0, 42, 0, 44, 149, 44, 149, 42);
		drawMultipleDivisions(posXArray, 42, 44, 3);
		
		drawInputLocation();
		drawGameDifficulty(stats);
		drawGameScore(stats);
		drawGameErrors(qntErrors);
		
		if(wordsOnScreenQnt<20){
			randomIndex = rand() % MAX_KEYS_ON_SCREEN;
			
			switch(stats -> difficulty){
			case EASY:
				createNewWord(words,dictionaryEASY[randomIndex], wordsOnScreenQnt, stats->speed);
				break;
				
			case MEDIUM:
				createNewWord(words,dictionaryMEDIUM[randomIndex], wordsOnScreenQnt, stats->speed);
				break;
				
			case HARD:
				createNewWord(words,dictionaryHARD[randomIndex], wordsOnScreenQnt, stats->speed);
				break;
				
			case PRO:
				createNewWord(words,dictionaryPRO[randomIndex], wordsOnScreenQnt, stats->speed);
				break;
		}
			
			words[wordsOnScreenQnt].posY = randomYPosition(words, wordsOnScreenQnt);
			
			gotoxy(words[wordsOnScreenQnt].posX, words[wordsOnScreenQnt].posY);
			textcolor(words[wordsOnScreenQnt].color);
			printf("%s", words[wordsOnScreenQnt].string);
			textcolor(WHITE);
			
			wordsOnScreenQnt++;
		}
		
		getUpperCaseString(string);
		
		checkWordIndex = checkWord(string, words, wordsOnScreenQnt);
		
		if(checkWordIndex == 100){
			MessageBox(NULL,"KONAMI CODE DETECTED\n ScoreMultiplier += 10","CHEAT ACTIVATED",MB_OK);
			stats -> scoreMultiplier += 10;
		}
		
		if(checkWordIndex >= 0){
			
			stats-> score += ((words[checkWordIndex].size * (int) CONSTANT_SCORE)) * ((int)stats->scoreMultiplier);	
			
			clearLine(words[checkWordIndex].posY);
			deleteWord(words, checkWordIndex, wordsOnScreenQnt);
			wordsOnScreenQnt--;
		} else {
			qntErrors++;
		}
		
		if(stats->score < 2000){
			stats->difficulty = EASY;
		}else if(stats->score >= 2000 && stats->score <= 10000){
			stats->difficulty = MEDIUM;
		} else if(stats->score > 10000 && stats->score <= 25000){
			stats->difficulty = HARD;
		} else if(stats -> score > 25000){
			stats->difficulty = PRO;
		}
		
		switch(stats -> difficulty){
			case EASY:
				stats -> speed           = 1;
				stats -> scoreMultiplier = 1;
				break;
				
			case MEDIUM:
				stats -> speed           = 2;
				stats -> scoreMultiplier = 2;
				break;
				
			case HARD:
				stats -> speed           = 3;
				stats -> scoreMultiplier = 3;
				break;
				
			case PRO:
				stats -> speed           = 4;
				stats -> scoreMultiplier = 5;
				break;
		}
	}
	
//	highscoreInformations.score = stats->score;
//	highscoreInformations.errors = stats->errors;
//	
//	system("cls");
	
	
	return 0;
	
	// End of main loop
}


//------------------------------------------------------------------------------------------------------------------------------------------------//
//
//                                                         End of Game functions                                                                  //
//
//------------------------------------------------------------------------------------------------------------------------------------------------//
