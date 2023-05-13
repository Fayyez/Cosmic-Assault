#include<iostream>
#include<SFML/Graphics.hpp>
#include"spacecraftAndBullet.h"
#include<string>
using namespace std;
using namespace sf;
/*
* -----------------------
*  "//C" in fornt of any method means
*  yet to be defined
* ------------------------
*/
///definitions for Spacecraft class
Spacecraft::Spacecraft(int x, int y, int xFinal, int yFinal, string fileName, int health) {
	xCord = x;
	yCord = y;
	this->xFinal = xFinal;
	this->yFinal = yFinal;
	this->health = health;
	reached = 0;
	this->scTexture.loadFromFile(fileName);
	this->scSprite.setTexture(this->scTexture);
	scSprite.setPosition(xCord, yCord);
}
void Spacecraft::setX(int x) { xCord = x; }
void Spacecraft::setY(int y) { yCord = y; }
void Spacecraft::setHealth(int h) { this->health = h; }
void Spacecraft::setSprite(string fileName) {
	this->scTexture.loadFromFile(fileName);
	this->scSprite.setTexture(this->scTexture);
}
void Spacecraft::setReached(bool status) { reached = status; }
int Spacecraft::getX() { return xCord; }
int Spacecraft::getY() { return yCord; }
int Spacecraft::getHealth() { return health; }
bool Spacecraft::getReached() { return reached; }
Sprite Spacecraft::getSprite() { return this->scSprite; }
void Spacecraft::draw(RenderWindow& window){}//C
Spacecraft::~Spacecraft(){}

///definitions for usercraft///
Usercraft::Usercraft(int x, int y, int xFinal, int yFinal, string fileName):
	Spacecraft(x,y,xFinal,yFinal,fileName, 8) {
}
void Usercraft::moveTo(int x, int y){}
void Usercraft::moveToInitial() {}//C
Usercraft::~Usercraft() {}

///definitions for EnemyCraft///
EnemyCraft::EnemyCraft(int x, int y, int xFinal, int yFinal, string fileName, int health) :
	Spacecraft(x,y,xFinal,yFinal,fileName,health) {
}
void EnemyCraft::moveToInitial() {}//C
EnemyCraft::~EnemyCraft() {}

///definitions for EnemyRed///
//EnemyRed::EnemyRed(int xFinal, int yFinal) {}//
void EnemyRed::moveToInitial() {}//C
EnemyRed::~EnemyRed() {}

///definitions for enemyBlue///
//EnemyBlue::EnemyBlue(int xFinal, int yFinal){}//C
void EnemyBlue::moveToInitial() {}
EnemyBlue::~EnemyBlue() {}

///definitions for enemyGreen///
//EnemyGreen::EnemyGreen(int xFinal, int yFinal) {}//C
void EnemyGreen::moveToInitial() {}//C
EnemyGreen::~EnemyGreen() {}

///definitions for BigBoss///
//BigBoss::BigBoss(int x, int y, int xFinal, int yFinal, string fileName);//C
void BigBoss::moveToInitial() {}//C
BigBoss::~BigBoss() {}

///definitions for bullet///
//Bullet::Bullet(int type, bool isFriendly, int x, int y, string fileName);
//void Bullet::setSprite(string fileName);
//bool Bullet::getIsFriendly();
//int Bullet::getType();
//int Bullet::getX();
//int Bullet::getY();
//Sprite Bullet::getSprite();
//void Bullet::move();
//bool Bullet::isOutOfScope();//return true is bullet has ggone out of window
//void Bullet::draw(sf::RenderWindow& window) {}

///definitions for Powerup///
Powerup::Powerup(int x, int y, string fileName) {
	this->xCord = x;
	this->yCord = y;
	this->isAlive = 1;
	this->upTexture.loadFromFile(fileName);
	this->upSprite.setTexture(this->upTexture);
	this->upSprite.setPosition(xCord, yCord);
}
void Powerup::setAlive(bool status) { isAlive = status; }
bool Powerup::getAlive() { return isAlive; }//needed to be popped out of vector
void Powerup::move() { 
	yCord -= 5;
	upSprite.setPosition(xCord, yCord);
}
void Powerup::draw(sf::RenderWindow& window) {
	window.draw(upSprite);
}