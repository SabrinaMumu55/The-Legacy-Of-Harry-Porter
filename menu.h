#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "variables.h"
#include "myLoadImage.h"

void mainMenu(){						//Function For MainMenu
	iShowImage(0, 0, width, height, menu);
	iSetColor(0, 0, 0);
	iRectangle(500, 560, 360, 80);	//Play game
	iText(600, 600, "START GAME", GLUT_BITMAP_TIMES_ROMAN_24);

	iRectangle(500, 400, 360, 80);	//Controls
	iText(600, 440, "INSTUCTIONS", GLUT_BITMAP_TIMES_ROMAN_24);

	iRectangle(500, 240, 360, 80);	//High score
	iText(600, 280, "HIGH SCORE", GLUT_BITMAP_TIMES_ROMAN_24);

	iRectangle(500, 80, 360, 80);	//Exit
	iText(600, 120, "EXIT GAME", GLUT_BITMAP_TIMES_ROMAN_24);

}

void Instruction(){			//Instruction For Game
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, width, height);
	iSetColor(25, 230, 255);
	//iText(500, 600, "       'UP' Key to Jump", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 500, "  'LEFT' Key to Move Left", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 400, "'RIGHT' Key to Move Right", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 300, " 'A' Key to Shoot Fire Ball", GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(500, 200, " 'X' Key for Special Power", GLUT_BITMAP_TIMES_ROMAN_24);
}




#endif // MENU_H_INCLUDED
