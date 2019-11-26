#ifndef TERMINAL_HANDLER_H
#define TERMINAL_HANDLER_H

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
