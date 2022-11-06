#ifndef GOBLIN_H_INCLUDED
#define GOBLIN_H_INCLUDED
#include"variables.h"
#include"myLoadImage.h"


void setGob(){
	for (int i=0; i < GOBnumber; i++){
		enemy1[i].gobX = width + rand() % 1000;
		enemy1[i].gobIndex = rand() % 200;
		enemy1[i].gobShow = true;
		
	}
}

void gobMovement(){
	for (int i = 0; i < GOBnumber; i++)
	{
		if (enemy1[i].gobShow){
			iShowImage(enemy1[i].gobX, enemy1[i].gobY, enemy1[i].gobdX, enemy1[i].gobdY, gob[enemy1[i].gobIndex]);
		}
	}
}


void goblinChange(){
	for (int i=0; i < GOBnumber; i++){

		enemy1[i].gobX -= 12;// enemy1[i].speed;

			if (enemy1[i].gobX <= 0){
				enemy1[i].gobX = width + rand() % 100;
			}
		enemy1[i].gobIndex++;
		if (enemy1[i].gobIndex >= 6){
			enemy1[i].gobIndex = 0;
		}
	}

}



#endif // GOBLIN_H_INCLUDED
