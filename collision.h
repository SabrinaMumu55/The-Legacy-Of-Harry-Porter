#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include "variables.h"
#include "Harry.h"
#include "allScore.h"


void power_gob_collision(){					//When FireBall hits Goblin...
	for (int i = 0; i < powNum; i++)
	{
		for (int j = 0; j < GOBnumber; j++){
			
			if ((p_x[i] + pdx >= enemy1[j].gobX) && fire[i] == true && enemy1[j].gobShow == true)
			{
				score += 50;

				enemy1[j].gobShow = false;
				fire[i] = false;
				gobDead++;
				if (gobDead == GOBnumber){
					iResumeTimer(SnapeTimer);
				}
			}

		}
	}
}

void Harry_gob_collision(){				//When Harry Collides with Goblin...
	for (int i = 0; i < GOBnumber; i++)
	{
		if (HarrycodX + dx >= enemy1[i].gobX && HarryDead == false && enemy1[i].gobShow == true)
		{
			if (HarryInjured == false){
				HarryLife -= 25;
				enemy1[i].gobShow = false;
				gobDead++;
				HarryInjured == true;
				//printf("Harry injured\n");

				if (HarryLife <= 0)
				{
					HarryDead = true;
					iPauseTimer(GobTimer);
				}
				if (gobDead == GOBnumber){
					iResumeTimer(SnapeTimer);
				}

			}
		}
		else
			HarryInjured == false;
	}
}

void Snape_power_collision(){							//When Fireball Collides with Snape...
	for (int i = 0; i < powNum; i++)
	{
		if ((p_x[i] + pdx >= Boss.SnapeCodX) && (p_x[i] + pdx <= Boss.SnapeCodX + dx) && SnapeStand == true && SnapeDead == false)
		{
			//if(snapeInjured == false){
				score += 5;
				Boss.SnapeLife -= 2;
				fire[i] = false;
				snapeInjured = true;
				if (Boss.SnapeLife <= 0)
				{
					SnapeDead = true;
					Boss.SnapeShow = false;
					iPauseTimer(ShadowTimer);

					score += 2000;
				}
				


			//}
		}
		//else snapeInjured = false;
		
	}
}

void Power_power_collision(){					//When FireBall And ShadowBall collides...
	for (int i = 0; i < powNum; i++)
	{
		for (int j = 0; j < SnapePowNum; j++){

			if ((p_x[i] + pdx >= sp_x[j]) && fire[i] == true && ShadowBall[j] == true)
			{
				score += 50;
				fire[i] = false;
				ShadowBall[j] = false;
				
			}

		}
	}

}

void Harry_power_collision(){				//When Harry Collides with Shadowball...
	for (int i = 0; i < SnapePowNum; i++)
	{
		if (HarrycodX + dx >= sp_x[i] && HarryDead == false && ShadowBall[i] == true && SnapeDead == false)
		{
			if (HarryInjured == false){
				HarryLife -= 20;
				ShadowBall[i] = false;
				HarryInjured = true;
				printf("Harry injured\n");
				if (HarryLife <= 0)
				{
					HarryDead = true;
					iPauseTimer(ShadowTimer);
				}
			}
		}
		else HarryInjured = false;
	}
}

#endif // COLLISION_H_INCLUDED
