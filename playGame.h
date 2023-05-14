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
	int speedOfFormation;//speed of movement of enemy formation {is higher for expert mode}; increasing every 30s
	bool won;//true when user has won the game, i.e, defeated the BigBoss
	bool lose;//true when enemy crosses border or when userhealth==0
	bool mode;//true foe expert mode
	bool direction;//true if enemy formation is moving rightwards and vice versa
	Clock clockTotal;
	Clock clockForFiring;
	Time totalTime;
	Time timeFromLastFire;//to keep track of total game time since the game began
	Time cooldownTime;
	Usercraft* player;
	vector<Powerup*> powerupArr;
	vector<Bullet*> bulletArr;
	vector<EnemyCraft*> enemyArr;
	/*
	* formation[][] is used as a reference for creating an enemy formation
	* with its [row]&[column] defining the x_final & y_final of the enemy craft
	*/	
	BigBoss* wadiBala;//obj of bigbossis created only when user has passed 5 levels
	EnemyCraft* rightmost;
	EnemyCraft* leftmost;
	EnemyCraft* lowest;

public:

	PLayGame(bool mode, int craftChoice);//starts with level 0 for beginner & 2 for expert
	void setSpeed(int s);
	void setWon(bool status);
	bool getWon() const;
	bool playerIsDead();
	bool sessionCompleted();
	bool formationIsKilled();//if formation is killed, level is incremented
	void createEnemy(int type, int xFinal, int yFinal);
	void createFormation(bool& status);//fills formation[][] according to level every 30sec
	bool checkCollisionWithAllBullets(EnemyCraft* craft, RenderWindow& window);
	void moveFormationNormally(int currentSize);//move the enemy formation and also saves the rightmost and leftmost enemy at any given time
	void play(RenderWindow&window,Event&event);//main method where game is played;
	~PLayGame();//should empty all the vectors and delete player and bigBoss
};