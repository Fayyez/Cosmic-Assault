#pragma once
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include"spacecraftANdBullet.h"
#include<vector>
using namespace sf;
using namespace std;

class PLayGame {
	int score;//stores current score of user, adds 50 for every successful kill
	int currentLevel;//it starts with level 0 and is incrementd for each enemy formation that is called
	int speed;//speed of movement of enemy formation {is higher for expert mode}; increasing every 30s
	bool won;//true when user has won the game, i.e, defeated the BigBoss
	bool mode;//true foe expert mode
	Time timer;//to keep track of total game time since the game began
	Usercraft player;
	vector<Powerup*> powerupArr;
	vector<Bullet*> bulletArr;
	vector<EnemyCraft*> enemyArr;
	int formation[10][18];
	/*
	* formation[][] is used as a reference for creating an enemy formation
	* with its [row]&[column] defining the x_final & y_final of the enemy craft
	*/	
	BigBoss* wadiBala;//obj of bigbossis created only when timer has reached a limit of 2:30

public:

	PLayGame(bool mode);//starts with level 0 for beginner & 2 for expert
	void setSpeed();
	bool formationIsKilled();//if formation is killed, level is incremented
	void fillArr();//fills formation[][] according to level every 30sec
	void moveBullets();//calss move of all bullets and destroyes all bullets that are out of scope of window
	void draw(RenderWindow& window);
	void play(RenderWindow&window,Event&event);//main method where game is played;
	~PLayGame();//should empty all the vectors and delete player and bigBoss

};