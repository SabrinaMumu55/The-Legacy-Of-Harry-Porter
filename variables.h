#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
#include "iGraphics.h"
#define height 720
#define width 1360
#define GOBnumber 30
#define powNum 60
#define SnapePowNum 10



//Menu
int menu;
int menuCounter = 0;
int stage1;

//GameOver
int GameOver, EndGame;

//life
int life;

//Harry
int Harry[20], HarrycodX = 80, HarrycodY = 150, Harryindex = 0, dx = 50, dy = 80;
int HarryMoveCounter = 0;
int HarryLife = 200;
bool HarryDead = false;
bool HarryStand = true;
bool HarryInjured = false;


//Power (Harry)
int fireBall;
bool fire[powNum] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };
int powIndex=0;
int p_x[powNum], p_y[powNum], pdx = 45, pdy = 40;
int powSpeed;


//Goblin
//int gob[6] = { iLoadImage("images/Gob5.png"), iLoadImage("images/Gob6.png"), iLoadImage("images/Gob7.png"), iLoadImage("images/Gob8.png"), iLoadImage("images/Gob9.png"), iLoadImage("images/Gob10.png") };
int gob[6];
int gobDead = 0;
int GobTimer;

struct Goblin
{
	int gobX, gobY = HarrycodY, gobIndex = 0;
	int gobdX = 50, gobdY = 80;
	bool gobShow;
	int active;
	int speed=10;
	int goblife = 20;

};

Goblin enemy1[GOBnumber];
void setGobPositions()
{
	enemy1[0].gobX = 10;
	enemy1[1].gobX = 20;


}

//Snape
/*int Snape, SnapeCodX, SnapeCodY = HarrycodY, SnapeIndex = 0;
int SnapeMoveCounter = 0;
int SnapeLife = 800;
bool SnapeShow;*/
int Snape;
bool SnapeDead = false;
bool SnapeStand = true;
int SnapeTimer;
bool snapeInjured = false;

struct SnapeSt
{
	int SnapeCodX, SnapeCodY = HarrycodY, SnapeIndex = 0;
	bool SnapeShow;
	int SnapeLife = 500;
};
SnapeSt Boss;

//Power (Snape)
int Shadow;
bool ShadowBall[SnapePowNum] = { false, false, false, false, false, false, false, false, false, false };
int ShadowIndex = 0;
int sp_x[SnapePowNum], sp_y[SnapePowNum];
int ShadowTimer;

#endif // VARIABLES_H_INCLUDED
