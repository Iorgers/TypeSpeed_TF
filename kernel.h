#ifndef KERNEL_H
#define KERNEL_H

#include "define.h"

//------------------------------------------------------------------------------------------------------------------------------------------------//

//                                                     Conio2.c functions prototypes                                                              //

//------------------------------------------------------------------------------------------------------------------------------------------------//

typedef struct text_info2 {
   unsigned char winleft;        /* left window coordinate */
   unsigned char wintop;         /* top window coordinate */
   unsigned char winright;       /* right window coordinate */
   unsigned char winbottom;      /* bottom window coordinate */
   unsigned char attribute;      /* text attribute */
   unsigned char normattr;       /* normal attribute */
   unsigned char currmode;       /* BW40, BW80, C40, C80, or C4350 */
   unsigned char screenheight;   /* text screen's height */
   unsigned char screenwidth;    /* text screen's width */
   unsigned char curx;           /* x-coordinate in current window */
   unsigned char cury;           /* y-coordinate in current window */
} text_info2;

typedef enum
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLORS;

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

void clrscr(void);

void gotoxy(int x, int y);

void _setcursortype(int cur_t);

void textbackground(int newcolor);

void textcolor(int newcolor);

//------------------------------------------------------------------------------------------------------------------------------------------------//
//
//                                                        End of Conio2.c functions                                                               //
//
//------------------------------------------------------------------------------------------------------------------------------------------------//

struct GAME_INFO{   // Struct to store the game info
	int score;
	int difficulty;
	int errors;
	int speed;
	int scoreMultiplier;
};

typedef struct WORD{
	char string[DEFAULT_STRING_LENGTH];
	int size;
	int posX;
	int posY;
	int speed;
	int color;
} word;

struct PLAYER_INFO{
	char name[DEFAULT_STRING_LENGTH];
};

typedef struct highscore{
	int score;
	int errors;
	struct PLAYER_INFO playerInformation;
} HIGHSCORE;

void getMonitorResolution(unsigned int *horizontal, unsigned int *vertical); // Get the monitor resolution :)

void setWindowSize(void); // It sets the window size based on "IS_RELATIVE_WINDOW_SIZE", where FALSE results in a standart size
                          // and TRUE a fullscreen size.
                        
void init_settings(void *info); // Initializes some terminal/video settings

void createNewWord(word newWord[], char *string, int wordIndex, int speedMultiplier);

void deleteWord(word words[], int toRemove, int wordsOnScreenQnt);

int checkWord(char *string, struct WORD *availableWords, int availableWordsQnt);

int randomYPosition(word words[], int availableWordsQnt);

int init(void);

#endif
