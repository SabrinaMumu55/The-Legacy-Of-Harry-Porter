#ifndef SNAPE_H_INCLUDED
#define SNAPE_H_INCLUDED
#include "variables.h"
#include "myLoadImage.h"

void setSnape(){			//Snape initialization
	Boss.SnapeCodX = width + rand() % 500;
	Boss.SnapeShow = true;
	SnapeStand = false;
	SnapeDead = false;
	Boss.SnapeLife = 50000;
}

void snapeShow(){			//This function is for Showinf snape in the game
	if (Boss.SnapeShow == true && SnapeDead == false){
		iShowImage(Boss.SnapeCodX, Boss.SnapeCodY, dx, dy, Snape);
	}
}

void SnapeMove(){			//This function is for moving Snape
	if (SnapeDead == false && SnapeStand == false && Boss.SnapeCodX >= width - 200){
		Boss.SnapeCodX -= 10;
	}
	
	else{
		SnapeStand = true;
		iResumeTimer(ShadowTimer);
	}

}
void setshadow(){		//This function is for power initialization(Snape)
	for (int i = 0; i < SnapePowNum; i++){
		ShadowBall[i] = false;
		sp_x[i] = Boss.SnapeCodX;
		powSpeed = 1;
		powIndex = 0;
	}
}

void ShadowballShow(){						//This function is for Showing snape power
	for (int i = 0; i < SnapePowNum; i++){
		if (ShadowBall[i] == true){
			iShowImage(sp_x[i], sp_y[i], pdx, pdy, Shadow);
			sp_x[i] -= powSpeed;
			if (p_x[i] <= 0){
				ShadowBall[i] = false;
				sp_x[i] = Boss.SnapeCodX;
			}
		}
	}

}

void ShadowBallForword(){						//This function is for moving Snape's power
	if (ShadowIndex == (SnapePowNum - 1)){
		ShadowIndex = 0;
		ShadowBall[ShadowIndex] = true;
		sp_x[ShadowIndex] = Boss.SnapeCodX;
		sp_y[ShadowIndex] = Boss.SnapeCodY + 20;
		ShadowIndex++;
	}
	else{
		ShadowBall[ShadowIndex] = true;
		sp_x[ShadowIndex] = Boss.SnapeCodX;
		sp_y[ShadowIndex] = Boss.SnapeCodY + 20;
		ShadowIndex++;
	}

}

#endif // SNAPE_H_INCLUDED
