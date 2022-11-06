#ifndef MYLOADIMAGE_H_INCLUDED
#define MYLOADIMAGE_H_INCLUDED
#include "iGraphics.h"
#include "variables.h"


void loadimage(){
    menu = iLoadImage("images/harry-potter-wallpapers-29604-5242377.jpg");
	stage1 = iLoadImage("images/drawn-cave-2d-game-background-521006-1009672.png");

	fireBall = iLoadImage("images/fire.png");
	
	GameOver = iLoadImage("GameOver/over.jpg");
	EndGame = iLoadImage("images/painting-game-about-salvador-dal-7-638.jpg");
	life = iLoadImage("images/red-plus-md_400x400.png");
	Snape = iLoadImage("images/Snape_SS.png");
	Shadow = iLoadImage("images/shadow-ball-2.png");



	if (HarryStand){
		Harry[0] = iLoadImage("images/H2.png");	//Harry images
		Harry[1] = iLoadImage("images/H3.png");
		Harry[2] = iLoadImage("images/H4.png");
		Harry[3] = iLoadImage("images/H5.png");

		HarryMoveCounter++;
		if (HarryMoveCounter >= 20){
			HarryMoveCounter = 0;
			Harryindex = 0;
			HarryStand = true;
		}
	}
	else{
		Harry[0] = iLoadImage("images/H2.png");
	}

		gob[0] = iLoadImage("images/Gob5.png");	//GOblin images
		gob[1] = iLoadImage("images/Gob6.png");
		gob[2] = iLoadImage("images/Gob7.png");
		gob[3] = iLoadImage("images/Gob8.png");
		gob[4] = iLoadImage("images/Gob9.png");
		gob[5] = iLoadImage("images/Gob10.png");
}


#endif // MYLOADIMAGE_H_INCLUDED
