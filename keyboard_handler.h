#ifndef KEYBOARD_HANDLER_H
#define KEYBOARD_HANDLER_H


int getArrowKey(void);

int verifyArrowKey(int pressedKey);

void getUpperCaseString(char *string);

int toUpper(char *string, int stringSize);
	
int strlength(char string[]);

int stringCompare(char *string, char *stringToCompare);

#endif
