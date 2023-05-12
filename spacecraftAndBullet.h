#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;

class Spacecraft {
	int health;
	int xCord;
	int yCord;
	int xFinal;
	int yFinal;
	int type;
	/* type 1 = usercraft
	   type 2 = enemy craft red
	   type 3 = enemy craft green
	   type 4 = enemy craft dragon */

	bool reached;//will return true when enemycraft has reached final position
	sf::Texture scTexture;
	sf::Sprite scSprite;

public:
	Spacecraft(int x, int y, int xFinal, int yFinal, string fileName, int health);
	void setX(int x);
	void setY(int y);
	void setHealth(int h);
	void setSprite(string fileName);
	int getX();
	int getY();
	int getHealth();
	sf::Sprite getSprite();
	virtual void moveToInitial() = 0;
};

class Usercraft : public Spacecraft {
public:
	Usercraft(int x, int y, int xFinal, int yFinal, string fileName);
	void moveTo(int x, int y);
	void moveToInitial();
};

class EnemyCraft: public Spacecraft {
	int path;
public:
	EnemyCraft(int x, int y, int xFinal, int yFinal, string fileName);
	void moveToInitial();
};

class BigBoss: public Spacecraft {
public:
	BigBoss(int x, int y, int xFinal, int yFinal, string fileName);
	void moveToInitial();
};

class Bullet {
	bool isAlive;
	bool isFriendly;// true = firendly bullet, false = enemy bullet
	int type;
	/*
	* type 1 = verticle down bullet
	* type 2 = verticle down fireball
	* type 3 = down right
	* type 4 = down left
	*/
	int xCord;
	int yCord;
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
public:
	Bullet(int type, bool isFriendly, int x, int y, string fileName);
	void setSprite(string fileName);
	bool getIsFriendly();
	int getType();
	int getX();
	int getY();
	sf::Sprite getSprite();
	void move();
	bool isOutOfScope();//return true is bullet has ggone out of window
};
