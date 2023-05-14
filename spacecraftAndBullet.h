#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<cstring>
#include<vector>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<random>
using namespace std;

class Spacecraft {
	int health;
	float xCord;
	float yCord;
	float xFinal;
	float yFinal;
	float speed;
	float reached;//will return true when craft has reached final position
	sf::Texture scTexture;
	sf::Sprite scSprite;
public:
	Spacecraft(float x, float y, float xFinal, float yFinal, string fileName, int health, float speed);
	void setX(float x);
	void setY(float y);
	void setXFinal(float x);
	void setYFinal(float y);
	void setSpeed(float s);
	void setHealth(int h);
	void setSprite(string fileName);
	void setReached(bool status);
	float getX();
	float getY();
	float getXFinal();
	float getYFinal();
	float getSpeed();
	int getHealth();
	bool getReached();
	sf::Sprite& getSprite();
	virtual void moveToInitial() = 0;//all types of crafts have specific movement from origin to x_final&y_final
	void moveSprite(int x, int y);
	void draw(sf::RenderWindow& window);
	virtual ~Spacecraft();

};

class Usercraft : public Spacecraft {
public:
	Usercraft(float x, float y, float xFinal, float yFinal, string fileName, int health);
	void moveTo(float x, float y);
	void moveToInitial();
	~Usercraft();
};

class EnemyCraft : public Spacecraft {
public:
	EnemyCraft(float x, float y, float xFinal, float yFinal, string fileName, int health, float speed);
	void moveToInitial();
	~EnemyCraft();
};

//red blue and green are three types of enemies who will have different starting position at time of creation
//and different healths
class EnemyRed : public EnemyCraft {
public:
	EnemyRed(float xFinal, float yFinal);
	void moveToInitial();
	~EnemyRed();
};

class EnemyBlue : public EnemyCraft {
public:
	EnemyBlue(float xFinal, float yFinal);
	void moveToInitial();
	~EnemyBlue();
};

class EnemyGreen : public EnemyCraft {
public:
	EnemyGreen(float xFinal, float yFinal);
	void moveToInitial();
	~EnemyGreen();
};

class BigBoss : public Spacecraft {
public:
	BigBoss(float x, float y, float xFinal, float yFinal, string fileName);
	void moveToInitial();
	~BigBoss();
};

class Bullet {
	bool isAlive;
	bool isFriendly;// true = firendly bullet, false = enemy bullet
	int type;
	/*
	* type 1 = verticle move bullet
	* type 2 = down right
	* type 3 = down left
	*/
	float xCord;
	float yCord;
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
public:
	Bullet(int type, bool isFriendly, int x, int y);
	void setSprite(string fileName);
	bool getIsFriendly();
	int getType();
	float getX();
	float getY();
	sf::Sprite& getSprite();
	void move();
	bool isOutOfScope();//return true is bullet has ggone out of window
	void draw(sf::RenderWindow& window);
};

class Powerup {//will give a shield to the usercraft
	float xCord;
	float yCord;
	bool isAlive;
	sf::Texture upTexture;
	sf::Sprite upSprite;
public:
	Powerup(float x, float y, string fileName);
	void setAlive(bool status);
	bool getAlive();//needed to be popped out of vector
	void move();
	void draw(sf::RenderWindow& window);
};