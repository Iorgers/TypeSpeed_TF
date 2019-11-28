#include <stdio.h>
#include "keyboard_handler.h"
#include "kernel.h"
#include "define.h"

int getTeclaSobreAjuda(void){
	int tecla=0, pisca=0, enter;

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

		fflush(stdin);
		enter = getch();

		if(enter == RETURN_KEY) {
			tecla = RETURN_KEY;
		}
	}while(!enter); // enter == 0

	return tecla;
}

int getArrowKey(void){
	int key, key_check, validKeyPressed = FALSE;

	while(validKeyPressed == FALSE){
		
		fflush(stdin);
		
		key_check = getch();
		
		if(key_check == RETURN_KEY){
			return key_check;
		}
		
		if(key_check == ARROW_KEY_CONTROL_VALUE){ // ARROW_KEY_CONTROL_VALUE is the value returned by getch(), which determines that an arrow key was pressed.
			key = getch();
			validKeyPressed = verifyArrowKey(key);
		}
		
	}
	
	return key;
}

int verifyArrowKey(int pressedKey){
	if(pressedKey == UP_ARROW || pressedKey == DOWN_ARROW){
			return TRUE;
	} else {
		return FALSE;
	}
}

void getUpperCaseString(char *string){
	char c[1]={'\0'};
	
	do{
		gotoxy(6, 43);
		fflush(stdin);
		fgets(string, DEFAULT_STRING_LENGTH, stdin);
	}while(stringCompare(string,c));

	toUpper(string, strlength(string));
}

int toUpper(char *string, int stringSize){
	
	if(stringSize == 0){ // If it reaches the first character
		
		if(string[stringSize] >= 97 && string[stringSize] <= 122){
			string[stringSize] -= 32;
		}
		return 0;
	}
	
	if(string[stringSize] >= 97 && string[stringSize] <= 122){
		string[stringSize] -= 32;
	}
	
	return toUpper(string, stringSize-1);
}

int strlength(char string[]){ // Returns the string length - 1;
	int size=0;
	
	while(string[size] != '\0'){
		size++;
	}
	
	return size-1;
}

int stringCompare(char *string, char *stringToCompare){
	int cont, isEqual=0;
	int string_size, stringToCompare_size;
	
	string_size = strlength(string);
	stringToCompare_size = strlength(stringToCompare)+1;
		
	if(string_size-stringToCompare_size!=0){
		return 0;
	} else {
		for(cont=0;cont<string_size;cont++){
			if(string[cont] == stringToCompare[cont]){
				isEqual++;
			}
		}
		if(isEqual==string_size){
			return 1;
		} else {
			return 0;
		}
	}
}

