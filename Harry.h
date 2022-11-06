#ifndef HARRY_H_INCLUDED
#define HARRY_H_INCLUDED
#include "variables.h"
#include "myLoadImage.h"

void setfire(){								//this function is for Fireball initialization
	for (int i = 0; i < powNum; i++){
		fire[i] = false;
		p_x[i] = HarrycodX + dx;
		powSpeed = 1;
		powIndex = 0;
	}
}

void fireShow(){							//This function is for showing fireball
	for (int i = 0; i < powNum; i++){
		if (fire[i] == true){
			iShowImage(p_x[i], p_y[i], pdx, pdy, fireBall);
			p_x[i] += powSpeed;
			if (p_x[i] >= width){
				fire[i] = false;
				p_x[i] = HarrycodX + dx;
			}
		}
	}

}

void fireForword(){				//This function is for fireball movement...
	if (powIndex == (powNum-1)){
		powIndex = 0;
		fire[powIndex] = true;
		p_x[powIndex] = HarrycodX + dx;
		p_y[powIndex] = HarrycodY + 20;
		powIndex++;
	}
	else{
		fire[powIndex] = true;
		p_x[powIndex] = HarrycodX + dx;
		p_y[powIndex] = HarrycodY + 20;
		powIndex++;
	}

}

#endif // HARRY_H_INCLUDED
