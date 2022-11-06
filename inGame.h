#ifndef INGAME_H_INCLUDED
#define INGAME_H_INCLUDED
#include "variables.h"
#include "myLoadImage.h"
#include "goblin.h"
#include "Harry.h"
#include "collision.h"
#include "allScore.h"

void ShowGameover(){							//This Function is called when Harry is dead...
	iShowImage(0, 0, width, height, GameOver);
}
void ShowEndGame(){								//This Function is called when Snape is dead...
	iShowImage(0, 0, width, height, EndGame);
}
void Life_Score(){								//This function is for Showing Life and Score of the character playing
	if (HarryLife <= 200 && HarryLife > 160 && HarryDead == false){
		iShowImage(80, 640, 40, 40, life);
		iShowImage(160, 640, 40, 40, life);
		iShowImage(240, 640, 40, 40, life);
		iShowImage(320, 640, 40, 40, life);

	}
	else if (HarryLife <= 160 && HarryLife > 120 && HarryDead == false)
	{
		iShowImage(80, 640, 40, 40, life);
		iShowImage(160, 640, 40, 40, life);
		iShowImage(240, 640, 40, 40, life);
	}
	else if (HarryLife <= 120 && HarryLife > 80 && HarryDead == false){
		iShowImage(80, 640, 40, 40, life);
		iShowImage(160, 640, 40, 40, life);
	}
	else if (HarryLife <= 80 && HarryLife > 40 && HarryDead == false){
		iShowImage(80, 640, 40, 40, life);
	}
}

void showstage1(){									//Function for Showing Stage
	if (HarryDead == false){
		iShowImage(0, 0, width, height, stage1);
		iShowImage(HarrycodX, HarrycodY, dx, dy, Harry[Harryindex]);//Harry Movement

		iSetColor(0, 0, 0);
		iFilledRectangle(0, 600, width, 120);
		onScreen_score_and_name();
		Life_Score();


		gobMovement();
		fireShow();
		power_gob_collision();
		Harry_gob_collision();
		snapeShow();
		ShadowballShow();
		Power_power_collision();
		Snape_power_collision();
		Harry_power_collision();

	}
	if (HarryDead == true)
	{
		menuCounter = 5;
	}
	if (SnapeDead == true)
		menuCounter = 6;
}
	
#endif // INGAME_H_INCLUDED
