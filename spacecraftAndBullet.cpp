#include<iostream>
#include<SFML/Graphics.hpp>
#include"spacecraftAndBullet.h"
#include<string>
#include<cmath>

using namespace std;
using namespace sf;
/*
* -----------------------
*  "//C" in fornt of any method means
*  yet to be defined
* ------------------------
*/
///definitions for Spacecraft class
Spacecraft::Spacecraft(float x, float y, float xFinal, float yFinal, string fileName, int health, float speed) {
	xCord = x;
	yCord = y;
	this->xFinal = xFinal;
	this->yFinal = yFinal;
	this->health = health;
	this->speed = speed;
	reached = 0;
	this->scTexture.loadFromFile(fileName);
	this->scSprite.setTexture(this->scTexture);
	scSprite.setPosition(xCord, yCord);
}
void Spacecraft::setX(float x) { xCord = x; }
void Spacecraft::setY(float y) { yCord = y; }
void Spacecraft::setXFinal(float x) { xFinal = x; }
void Spacecraft::setYFinal(float y) { yFinal = y; }
void Spacecraft::setSpeed(float s) { speed = s; }
void Spacecraft::setHealth(int h) { this->health = h; }
void Spacecraft::setSprite(string fileName) {
	this->scTexture.loadFromFile(fileName);
	this->scSprite.setTexture(this->scTexture);
}
void Spacecraft::setReached(bool status) { reached = status; }
float Spacecraft::getX() { return xCord; }
float Spacecraft::getY() { return yCord; }
float Spacecraft::getXFinal() { return xFinal; }
float Spacecraft::getYFinal() { return yFinal; }
float Spacecraft::getSpeed() { return speed; }
int Spacecraft::getHealth() { return health; }
bool Spacecraft::getReached() { return reached; }
Sprite & Spacecraft::getSprite() { return this->scSprite; }
void Spacecraft::draw(RenderWindow& window) {
	window.draw(this->scSprite);
}
Spacecraft::~Spacecraft(){}

///definitions for usercraft///
Usercraft::Usercraft(float x, float y, float xFinal, float yFinal, string fileName):
	Spacecraft(x,y,xFinal,yFinal,fileName, 8, 3) {
}
void Usercraft::moveTo(float x, float y){}
void Usercraft::moveToInitial() {
	float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance <= getSpeed()) {
        setX(getXFinal());
        setY(getYFinal());
        getSprite().setPosition(getX(), getY());
    }
    else {
        float ratio = getSpeed() / distance;
        setX(getX() + dx * ratio);
        setY(getY() + dy * ratio);
        getSprite().setPosition(getX(), getY());
    }
}//C
Usercraft::~Usercraft() {}

///definitions for EnemyCraft///
EnemyCraft::EnemyCraft(float x, float y, float xFinal, float yFinal, string fileName, int health) :
	Spacecraft(x,y,xFinal,yFinal,fileName,health, 5) {
}
void EnemyCraft::moveToInitial() {
	float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance <= getSpeed()) {
        setX(getXFinal());
        setY(getYFinal());
        getSprite().setPosition(getX(), getY());
    }
    else {
        float ratio = getSpeed() / distance;
        setX(getX() + dx * ratio);
        setY(getY() + dy * ratio);
        getSprite().setPosition(getX(), getY());
    }
}//C
EnemyCraft::~EnemyCraft() {}

///definitions for EnemyRed///
//EnemyRed::EnemyRed(float xFinal, float yFinal) {}//
void EnemyRed::moveToInitial() {
	float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance <= getSpeed()) {
        setX(getXFinal());
        setY(getYFinal());
        getSprite().setPosition(getX(), getY());
    }
    else {
        float ratio = getSpeed() / distance;
        setX(getX() + dx * ratio);
        setY(getY() + dy * ratio);
        getSprite().setPosition(getX(), getY());
    }
}//C health = 2
EnemyRed::~EnemyRed() {}

///definitions for enemyBlue///
//EnemyBlue::EnemyBlue(float xFinal, float yFinal){}//C health = 1
void EnemyBlue::moveToInitial() {
	float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance <= getSpeed()) {
        setX(getXFinal());
        setY(getYFinal());
        getSprite().setPosition(getX(), getY());
    }
    else {
        float ratio = getSpeed() / distance;
        setX(getX() + dx * ratio);
        setY(getY() + dy * ratio);
        getSprite().setPosition(getX(), getY());
    }
}
EnemyBlue::~EnemyBlue() {}

///definitions for enemyGreen///
//EnemyGreen::EnemyGreen(float xFinal, float yFinal) {}//C
void EnemyGreen::moveToInitial() {
	float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance <= getSpeed()) {
        setX(getXFinal());
        setY(getYFinal());
        getSprite().setPosition(getX(), getY());
    }
    else {
        float ratio = getSpeed() / distance;
        setX(getX() + dx * ratio);
        setY(getY() + dy * ratio);
        getSprite().setPosition(getX(), getY());
    }
}//C health = 1
EnemyGreen::~EnemyGreen() {}

///definitions for BigBoss///
//BigBoss::BigBoss(float x, float y, float xFinal, float yFinal, string fileName);//C
void BigBoss::moveToInitial() {
	float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance <= getSpeed()) {
        setX(getXFinal());
        setY(getYFinal());
        getSprite().setPosition(getX(), getY());
    }
    else {
        float ratio = getSpeed() / distance;
        setX(getX() + dx * ratio);
        setY(getY() + dy * ratio);
        getSprite().setPosition(getX(), getY());
    }
}//C
BigBoss::~BigBoss() {}

///definitions for bullet///
//Bullet::Bullet(float type, bool isFriendly, float x, float y, string fileName);
//void Bullet::setSprite(string fileName);
//bool Bullet::getIsFriendly();
//int Bullet::getType();
//float Bullet::getX();
//float Bullet::getY();
//Sprite Bullet::getSprite();
//void Bullet::move();
//bool Bullet::isOutOfScope();//return true is bullet has ggone out of window
//void Bullet::draw(sf::RenderWindow& window) {}

///definitions for Powerup///
Powerup::Powerup(float x, float y, string fileName) {
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