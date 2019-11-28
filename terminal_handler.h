#ifndef TERMINAL_HANDLER_H
#define TERMINAL_HANDLER_H

void defeatAnimation(void);

int loadingScreen(void);

void _clearLine(int inicio, int fim);

void drawLogo(void);

void drawMenuOptions(void);

void drawSobre(void);

void drawHighscores(void);

int selecaoMenu(int posicao, int tecla, int contador);

void drawAjuda(void);

void drawMainMenu(void);

void drawBox(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4); //Creates a division line for the game and the statistics

void drawDivision(int x, int y1, int y2);

void drawMultipleDivisions(int *posXArray, int y1, int y2, int divisionsQnt);

void drawInputLocation(void);

void *drawGameDifficulty(void *info);

void *drawGameScore(void *info);

void *drawGameErrors(int qntErrors);

void clearLine(int posY);

void *drawWord(struct WORD *wordOnScreen, int wordIndex, int option);

#endif
