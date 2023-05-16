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
Sprite& Spacecraft::getSprite() { return this->scSprite; }
void Spacecraft::moveSprite(int x, int y) {
    scSprite.move(x, y);
    xCord = scSprite.getPosition().x;
    yCord = scSprite.getPosition().y;
}
void Spacecraft::draw(RenderWindow& window) {
    window.draw(this->scSprite);
}
Spacecraft::~Spacecraft() {}

///definitions for usercraft///
Usercraft::Usercraft(float x, float y, float xFinal, float yFinal, string fileName, int health) :
    Spacecraft(x, y, xFinal, yFinal, fileName, health, 1) {
}
void Usercraft::moveTo(float x, float y) {}
void Usercraft::moveToInitial() {
    float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx * dx + dy * dy);
    if (distance <= getSpeed()) {
        setX(getXFinal());
        setY(getYFinal());
        getSprite().setPosition(getX(), getY());
    }
    else {
        float ratio = getSpeed() / distance;
        getSprite().setPosition(getX() + dx * ratio, getY() + dy * ratio);
       // setX(getX() + dx * ratio);
        setX(getSprite().getPosition().x);
        //setY(getY() + dy * ratio);
        setY(getSprite().getPosition().y);
        getSprite().setPosition(getX(), getY());
    }
    if (getX() == getXFinal() && getY() == getYFinal()) this->setReached(true);
}
Usercraft::~Usercraft() {}

///definitions for EnemyCraft///
EnemyCraft::EnemyCraft(float x, float y, float xFinal, float yFinal, string fileName, int health, float speed) :
    Spacecraft(x, y, xFinal, yFinal, fileName, health, speed) {
}
void EnemyCraft::moveToInitial() {
    float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx * dx + dy * dy);
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
    if (getX() == getXFinal() && getY() == getYFinal()) setReached(true);
}//C
EnemyCraft::~EnemyCraft() {}

///definitions for EnemyRed///
EnemyRed::EnemyRed(float x, float y, float xFinal, float yFinal) :
    EnemyCraft(x, y, xFinal, yFinal, "assets/enemy_ship.png", 2, 3) {
}//
void EnemyRed::moveToInitial() {
    float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx * dx + dy * dy);
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
    if (getX() == getXFinal() && getY() == getYFinal()) setReached(true);
}//health = 2
EnemyRed::~EnemyRed() {}

///definitions for enemyBlue///
EnemyBlue::EnemyBlue(float x, float y, float xFinal, float yFinal) :
    EnemyCraft(x, y, xFinal, yFinal, "assets/enemy_ship.png", 1, 1.5) {
}//C health = 1
void EnemyBlue::moveToInitial() {
    float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx * dx + dy * dy);
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
    if (getX() == getXFinal() && getY() == getYFinal()) setReached(true);
}
EnemyBlue::~EnemyBlue() {}

///definitions for enemyGreen///
EnemyGreen::EnemyGreen(float x, float y, float xFinal, float yFinal):
    EnemyCraft(x, y, xFinal, yFinal, "assets/enemy_ship.png", 1, 3) {
}
void EnemyGreen::moveToInitial() {
    float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx * dx + dy * dy);
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
    if (getX() == getXFinal() && getY() == getYFinal()) setReached(true);
}//health = 1
EnemyGreen::~EnemyGreen() {}

///definitions for BigBoss///
BigBoss::BigBoss(float x, float y, float xFinal, float yFinal):
    //Spacecraft(x,y,xFinal,yFinal,"assets/bigBoss.png", 5, 5) {
    Spacecraft(x,y,xFinal,yFinal,"assets/doggo_villain.png", 5, 1) {
}
void BigBoss::moveToInitial() {
    float dx = getXFinal() - getX();
    float dy = getYFinal() - getY();
    float distance = std::sqrt(dx * dx + dy * dy);
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
    if (getX() == getXFinal() && getY() == getYFinal()) setReached(true);
}//C
BigBoss::~BigBoss() {}

///definitions for bullet///
/*
    * type 1 = verticle move bullet
    * type 2 = down right
    * type 3 = down left
*/
Bullet::Bullet(int type, bool isFriendly, int x, int y) {
 
    this->type = type;
    this->isFriendly = isFriendly;
    xCord = x;
    yCord = y;
    this->isAlive = true;
    if(isFriendly)  this->bulletTexture.loadFromFile("assets/bullet.png");
    else  this->bulletTexture.loadFromFile("assets/enemy-bullet1.png");
    this->bulletSprite.setTexture(this->bulletTexture);
    bulletSprite.setPosition(xCord, yCord);
}
void Bullet::setSprite(string fileName) {

    this->bulletTexture.loadFromFile(fileName);
    this->bulletSprite.setTexture(this->bulletTexture);
}
bool Bullet::getIsFriendly() { return isFriendly; }
int Bullet::getType() { return type; }
float Bullet::getX() { return xCord; }
float Bullet::getY() { return yCord; }
Sprite& Bullet::getSprite() { return bulletSprite; }
void Bullet::move() {

    if (type == 1) {//verticle movement
        if (isFriendly) {
            bulletSprite.move(0, -6);//for user bullets
        }
        else {
            bulletSprite.move(0, 6);//for enemy bullets
        }
    }

    else if (type == 2) {//for down right
        bulletSprite.move(3, 6);
    }

    else {//for down left movement
        bulletSprite.move(-3, 6);
    }

    xCord = bulletSprite.getPosition().x;
    yCord = bulletSprite.getPosition().y;
}
bool Bullet::isOutOfScope() {
    //return true is bullet has gone out of window
    return (xCord > 900 || xCord < 0 || yCord>900 || yCord < 0);
}
void Bullet::draw(sf::RenderWindow& window) { 
    window.draw(this->bulletSprite);
}

///definitions for Powerup///
Powerup::Powerup(float x, float y, string fileName) {

    this->xCord = x;
    this->yCord = y;
    this->isAlive = true;
    this->upTexture.loadFromFile(fileName);
    this->upSprite.setTexture(this->upTexture);
    this->upSprite.setPosition(xCord, yCord);
}
void Powerup::setAlive(bool status) { isAlive = status; }
bool Powerup::getAlive() { return isAlive; }//needed to be popped out of vector
void Powerup::move() {//move the powerup downwards
    upSprite.move(0, 5);
    yCord = upSprite.getPosition().y;
}
void Powerup::draw(sf::RenderWindow& window) {
    window.draw(upSprite);
}