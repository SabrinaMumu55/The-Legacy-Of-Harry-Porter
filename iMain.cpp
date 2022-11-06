#include "iGraphics.h"
#include "variables.h"
#include "myLoadImage.h"
#include "bitmap_loader.h"
#include "menu.h"
#include "Harry.h"
#include "goblin.h"
#include "Snape.h"
#include "inGame.h"
#include "collision.h"
#include "allScore.h"



//function iDraw() is called again and again by the system.


void iDraw()
{
    //place your drawing codes here
    iClear();
    if (menuCounter == 0)
    {
        iPauseTimer(GobTimer);
		iPauseTimer(SnapeTimer);
		iPauseTimer(ShadowTimer);
        mainMenu();

    }
    else if (menuCounter == 1)
    {
        showstage1();
		iResumeTimer(GobTimer);
		
    }
    else if (menuCounter == 2)
    {
        Instruction();
    }
    else if (menuCounter == 3)
    {
        onScreen_score_and_name();
    }
    else if (menuCounter == 4)
    {
		//iPauseTimer(GobTimer);
        takePlayerName();
    }
	else if (menuCounter == 5)
	{
		ShowGameover();
		saveScore();
	}
	else if (menuCounter == 6)
	{
		ShowEndGame();
		saveScore();
	}
}

void iPassiveMouse(int x, int y)
{

}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
    printf("x = %d, y= %d\n", mx, my);
    //place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //	printf("x = %d, y= %d\n",mx,my);
        if (mx > 500 && mx < 860 && my>560 && my < 640 && menuCounter==0)
        {
            menuCounter = 4;
            
        }
        else if (mx > 500 && mx < 860 && my > 400 && my < 480 && menuCounter == 0)
        {
            menuCounter = 2;
        }
        else if (mx > 500 && mx < 860 && my > 240 && my < 320 && menuCounter == 0)
        {
            menuCounter = 3;
        }

        else if (mx > 500 && mx < 860 && my>80 && my < 160 && menuCounter == 0)
        {
            menuCounter = 4;
            exit(0);

        }

    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
    if (key == 'q')
    {
        //exit(0);
    }
    if (key == 'a' && menuCounter == 1)
    {
		fireForword();


    }
	if (key == 'b' && (menuCounter == 1 || menuCounter == 2 || menuCounter == 3 || menuCounter == 5 || menuCounter == 6))
    {
        menuCounter = 0;

    }
	if (menuCounter == 4)                           //this is the condition for taking in player name which is stored in "name" and later
	{                                        //shown in the player name taking menu and later in the game

		if (key == '\r')
		{
			PlaySound("music//enter", NULL, SND_ASYNC);
			menuCounter = 1;
			//iResumeTimer(GobTimer);

		}

		else if (key == '\b')
		{

			if (nameL>0)
			{
				PlaySound("music//backspace", NULL, SND_ASYNC);
				nameL--;
				name[nameL] = '\0';
			}
			if (nameL == 0)
				PlaySound("music//error", NULL, SND_ASYNC);
		}

		else
		{
			PlaySound("music//button", NULL, SND_ASYNC);
			name[nameL] = key;
			nameL++;
		}
		if (key == '\r' && menuCounter == 5)              //here all the values are given there initial values after the game over
		{
			//PlaySound("music//intro", NULL, SND_ASYNC);
			menuCounter = 0;

			strcpy(ssf[10].playerName, name);
			ssf[10].playerScore = score;


			saveScore();

		}

		if (key == '\r' && menuCounter == 6)              //here all the values are given there initial values after the game finished
		{
			//PlaySound("music//intro", NULL, SND_ASYNC);
			menuCounter = 0;

			strcpy(ssf[10].playerName, name);
			ssf[10].playerScore = score;


			saveScore();

		}

	}

    //place your codes for other keys here
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_RIGHT)
    {
        HarrycodX += 10;
        Harryindex++;
        if (Harryindex >= 4)
        {
            Harryindex = 0;
            HarryStand = false;
        }
    }
    else if (key == GLUT_KEY_LEFT)
    {
        HarrycodX -= 10;
        Harryindex--;
        if (Harryindex < 0)
        {
            Harryindex = 3;
            HarryStand = false;
        }
    }
    else if (key == GLUT_KEY_UP)
    {
        HarryMoveCounter = 3;
    }
    //place your codes for other keys here
}


int main()
{
    //place your own initialization codes here.

	srand(time(NULL));
    setGob();
	setfire();
	setGobPositions();
	setSnape();
	setshadow();
	GobTimer = iSetTimer(120, goblinChange);
	SnapeTimer = iSetTimer(100, SnapeMove);
	ShadowTimer = iSetTimer(1400, ShadowBallForword);
    iInitialize(width, height, "The Legacy og Harry Potter");
    loadimage();


    iStart(); // it will start drawing

    return 0;
}
