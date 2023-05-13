#include<iostream>
#include<vector>
#include"playGame.h"
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<random>

using namespace std;
using namespace sf;

bool shouldFire(bool mode) {//returns true 10% of the time if status is true and 7%if status is false
	
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dis(0.0f, 1.0f);
	
	float chances;
	chances = dis(gen);
	if (mode) {//for expert mode = 10%
		return (chances <= 0.1f);
	}
	else {//for beginers mode 7%

		return (chances <= 0.07f);
	}

}
bool collides(Sprite& ship, Sprite& sprite2, RenderWindow& window)
{
	// get the global bounds of the sprites
	FloatRect sprite1 = ship.getGlobalBounds();
	FloatRect bulletBounds = sprite2.getGlobalBounds();

	// check if the global bounds intersect
	return (sprite1.intersects(bulletBounds));
}

//int score;//stores current score of user, adds 50 for every successful kill
//int currentLevel;//it starts with level 0 and is incrementd for each enemy formation that is called
//int speed;//speed of movement of enemy formation {is higher for expert mode}; increasing every 30s
//bool won;//true when user has won the game, i.e, defeated the BigBoss
//bool mode;//true foe expert mode
//bool direcrion;//true if enemy formation is moving rightwards and vice versa
//Clock totalTime;
//Clock clockForFiring
//Time totalTime;
//Time timeFromLastFire;//to keep track of total game time since the game began
//Time cooldownTime;//Usercraft* player;
//vector<Powerup*> powerupArr;
//vector<Bullet*> bulletArr;
//vector<EnemyCraft*> enemyArr;
//int formation[10][18];
///*
//* formation[][] is used as a reference for creating an enemy formation
//* with its [row]&[column] defining the x_final & y_final of the enemy craft
//*/
//BigBoss* wadiBala;//obj of bigbossis created only when user has passed 5 levels
//EnemyCraft* rightmost;
//EnemyCraft* leftmost;
//EnemyCraft* lowest;
PLayGame::PLayGame(bool mode, int craftChoice) {//starts with level 0 for beginner & 2 for expert
	this->score = 0;
	this->won = false;
	this->mode = mode;
	this->direcrion = true;//initially move formation to right
	this->clockTotal.restart();
	this->clockForFiring.restart();
	this->cooldownTime = seconds(0.5f);
	this->timeFromLastFire = clockForFiring.getElapsedTime();
	string imageName;
	//craft choice of user
	if (craftChoice == 1) imageName = "s_ship.png";//********//
	else if (craftChoice == 2) imageName = "s_ship.png";
	else if (craftChoice == 3) imageName = "s_ship.png";
	if (mode) {//expert mode
		currentLevel = 2;
		speedOfFormation = 6;
		player = new Usercraft(370, 125, 370, 780, imageName);//*****HEALTH PART TO BE IMPLEMENTED*********//
	}
	else {//beginners mode
		currentLevel = 0;
		speedOfFormation = 2;
		///*****HEALTH PART TO BE IMPLEMENTED&*******************///
		player = new Usercraft(370, 125, 370, 780, imageName);
	}
	wadiBala = new BigBoss(350, -120, 350,200, "s_ship.png");
	formation[10][18] = {0};//start with an empty formation
}
void PLayGame::setSpeed(int s) { speedOfFormation = s; }
void PLayGame::setWon(bool status) { won = status; }
bool PLayGame::getWon() const { return won; }
bool  PLayGame::sessionCompleted() { //returns true if it is time to bring out bigBoss
	totalTime = clockTotal.getElapsedTime();
	return (timeFromLastFire.asSeconds() > 160); 
}
bool PLayGame::formationIsKilled() {//if formation is killed, level is incremented

	if (enemyArr.size() == 0) return true;
	return false;
}
void PLayGame::createEnemy(int type, int xFinal, int yFinal) {

	//convert [i][j] of array into xy of window
	xFinal += 50 * xFinal;
	yFinal += 50 * yFinal + 100;

	//creating enemies of responding type
	if (type == 1) {
		enemyArr.push_back(new EnemyGreen(xFinal,yFinal));
	}
	else if (type == 2) {
		enemyArr.push_back(new EnemyRed(xFinal, yFinal));
	}
	else if (type == 3) {
		enemyArr.push_back(new EnemyBlue(xFinal, yFinal));
	}
}
void PLayGame::createFormation() {//fills formation[][] according to level every 30sec

	if (currentLevel == 0 || currentLevel == 2) {//==2 is to be removed later when more formations are added
		//create a rectangle of 4X10 all greens
		for (int i = 1; i < 5; i++) {
			for (int j = 4; j < 14; j++) {
				//formation[i][j] = 1;
				createEnemy(1, i, j);
			}
		}
	}

	//********8more formations to be added*******//
}
void PLayGame::moveBullets();//calss move of all bullets and destroyes all bullets that are out of scope of window
void PLayGame::draw(RenderWindow& window);
/*
* draw enemies/bigboss
* draw bullets
* draw user
* draw user health
* draw score
*/
void PLayGame::moveEnemies();//move the enemy formation and update direction if formation moved down
bool PLayGame::checkCollisionWithAllBullets(EnemyCraft* craft, RenderWindow& window) {
	//return true if spacecraft sprties collided with a bullet

	for (int i = 0; i < bulletArr.size();i++) {
		if (collides(craft->getSprite(), bulletArr[i]->getSprite(), window) && bulletArr[i]->getIsFriendly()) {
			//returns true if any friendly bullet collides with that enemy craft
			//remove the bullet from bulletArr & delete the pointer
			if (bulletArr[i] != nullptr) {
				delete bulletArr[i];
				bulletArr[i] = nullptr;
			}
			bulletArr.erase(bulletArr.begin() + i);//pop out that bullet
			i--;
			return true;
		}
	}
	return false;
}
void PLayGame::play(RenderWindow& window, Event& event) {

	//untill not time for bigBoss
	bool formationKilled = formationIsKilled();
	if (!sessionCompleted() || !formationKilled) {
	//if under normal conditions:

		if (formationKilled) {//if enemies are not present on screen
			createFormation();
			//currentLevel++;
		}

		bool reached = true;//assume formaion has been formed
		int currentSize = 0;//declared outside to be used as a size() for enemyArr;
		for (; currentSize < enemyArr.size(); currentSize++) {
			
			//check for bullet collisions
			if (checkCollisionWithAllBullets(enemyArr[currentSize], window)) {
				//if collided with a friendly bullet
				enemyArr[currentSize]->setHealth(enemyArr[currentSize]->getHealth() - 1);//decrease health
			}
			//check for collision with UserCraft
			if (collides(player->getSprite(), enemyArr[currentSize]->getSprite(), window)) {
				enemyArr[currentSize]->setHealth(0);//kill on collision with user
				player->setHealth(player->getHealth() - 2);//user health is decreased bby 2 on impact with enemycraft
			}

			if (enemyArr[currentSize]->getHealth() <= 0) {//if enemy health == 0

				if (enemyArr[currentSize] != nullptr) {
					delete enemyArr[currentSize];
					enemyArr[currentSize] = nullptr;
				}
				enemyArr.erase(enemyArr.begin() + currentSize);
				currentSize--;
			}
			//if enemy formation is not complete
		    if (!enemyArr[currentSize]->getReached()) { reached = false; }

		}
		///enemy movement & update leftmost lowest, etc///
		if (!reached) {//enemy formation is not set yet
			for (int j = 0; j < currentSize; j++) {

			}
		}

	}
	else {
		//bring boss
	}
}
PLayGame::~PLayGame() {

	//deallocate bullets
	for (int i = 0; i < bulletArr.size(); i++) {
		delete bulletArr[i];
		bulletArr[i] = nullptr;
	}
	//deallocate enemies
	for (int i = 0; i < enemyArr.size(); i++) {
		delete enemyArr[i];
		enemyArr[i] = nullptr;
	}
	//deallocate powerups
	for (int i = 0; i < powerupArr.size(); i++) {
		delete powerupArr[i];
		powerupArr[i] = nullptr;
	}
	if (player != nullptr) {
		delete player;
		player = nullptr;
	}
	if (wadiBala != nullptr) {
		delete wadiBala;
		wadiBala = nullptr;
	}


}