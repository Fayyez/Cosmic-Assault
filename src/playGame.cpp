#include "playGame.h"

using namespace std;
using namespace sf;

bool shouldFire(bool mode) {//returns true 10% of the time if status is true and 7%if status is false
	
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dis(0.0f, 1.0f);
	
	float chances;
	chances = dis(gen);
	if (mode) {//for expert mode = 10%
		return (chances <= 0.001f);
	}
	else {//for beginers mode 7%

		return (chances <= 0.0005f);
	}

}
bool BalashouldFire() {

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dis(0.0f, 1.0f);

	float chances;
	chances = dis(gen);
    return (chances <= 0.01f);
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
	this->lose = false;
	this->mode = mode;
	this->direction = true;//initially move formation to right
	this->clockTotal.restart();
	this->clockForFiring.restart();
	this->cooldownTime = seconds(0.35f);
	this->timeFromLastFire = clockForFiring.getElapsedTime();
	string imageName;
	//craft choice of user
	if (craftChoice == 1) imageName = "assets/s_ship.png";//********//
	else if (craftChoice == 2) imageName = "assets/s_ship.png";
	else if (craftChoice == 3) imageName = "assets/s_ship.png";
	if (mode) {//expert mode
		currentLevel = 2;
		speedOfFormation = 6;
		player = new Usercraft(370, 1000, 370, 740, imageName, 50);//*****HEALTH PART TO BE IMPLEMENTED*********//
	}
	else {//beginners mode
		currentLevel = 0;
		speedOfFormation = 2;
		///*********HEALTH PART TO BE IMPLEMENTED&*******************///
		player = new Usercraft(370, 1000, 370, 740, imageName, 100);
	}
	wadiBala = new BigBoss(350, -120, 350,200);
	//formation[10][18] = {0};//start with an empty formation
}
void PLayGame::setSpeed(int s) { speedOfFormation = s; }
void PLayGame::setWon(bool status) { won = status; }
bool PLayGame::getWon() const { return won; }
bool PLayGame::playerIsDead() {
	if (player->getHealth() == 0) {
		return false;
	}
	else return true;
}
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
	xFinal += 55 * xFinal;
	yFinal += 55 * yFinal + 50;

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
void PLayGame::createFormation(bool& status) {//fills formation[][] according to level every 30sec

	if (currentLevel == 0 || currentLevel == 2) {//==2 is to be removed later when more formations are added
		//create a rectangle of 4X10 all greens
		for (int i = 1; i < 5; i++) {
			for (int j = 4; j < 14; j++) {
				//formation[i][j] = 1;
				createEnemy(1, j, i);
			}
		}
		status = !status;
	}

	//********8more formations to be added*******//
}
bool PLayGame::checkCollisionWithAllBullets(EnemyCraft* craft, RenderWindow& window) {
	//return true if spacecraft sprties collided with a bullet

	for (int i = 0; i < bulletArr.size(); i++) {

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
bool PLayGame::checkCollisionWithAllBullets(RenderWindow& window) {

	for (int i = 0; i < bulletArr.size(); i++) {

		if (collides(wadiBala->getSprite(), bulletArr[i]->getSprite(), window) && bulletArr[i]->getIsFriendly()) {
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
void PLayGame::moveFormationNormally(int currentSize) {

	if (leftmost->getX() <= 10 || rightmost->getX() >= 850) {
	//if formation has touched right/left boundary -> move down
		for (int i = 0; i < currentSize; i++) {
			enemyArr[i]->moveSprite(0, 10);
		}
		direction = !direction;//changing direction of motion of formation
	}

	if (direction) {//if moving towards right
		for (int i = 0; i < currentSize; i++) {
			enemyArr[i]->moveSprite(1.5,0);//move all enemies 5pixels to right
		}
	}

	else {//moving to left
		for (int i = 0; i < currentSize; i++) {
			enemyArr[i]->moveSprite(-1.5,0);//move all enemies 5pixels to left
		}
	}
}
void PLayGame::play(RenderWindow& window, Event& event) {

	/*cout << "X = " << player->getX() << "   Y = " << player->getY()<<endl;
	cout << player->getHealth();*/
	/////////player movement-&-collision checks/////////
	player->draw(window);
	if (player->getReached() == 0) {//if player hasn't reached its destination
		player->moveToInitial();
	}
	else {
		////*********movement BOUNDARIES TO BE ADDED with user input and fire********//////////
		timeFromLastFire = clockForFiring.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Space) && timeFromLastFire >= cooldownTime) {
			clockForFiring.restart();
			bulletArr.push_back(new Bullet(1, 1, player->getX() + 32, player->getY()));
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) && player->getX() < 810) {
			player->moveSprite(5, 0);
			// cout << "Right" << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left) && player->getX() > 10) {
			player->moveSprite(-5, 0);
			//cout << "Left" << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) && player->getY() < 790) {
			player->moveSprite(0, 5);
			// cout << "Down" << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up) && player->getY() > 650) {
			player->moveSprite(0, -5);
			//cout << "up" << endl;
		}
	}

	//untill not time for bigBoss
	bool formationKilled = formationIsKilled();
	if (player->getReached()) {//enemies and bigboss appear once player has reached initial

		if (!formationKilled || currentLevel < 1) {// || (mode && currentLevel < 7) || (!mode && currentLevel < 5) 
		//if under normal conditions :

			if (formationKilled) {//if enemies are not present on screen
				createFormation(formationKilled);
				currentLevel++;
			}
			//pointing leftmost, rightmost, lowest
			lowest = rightmost = leftmost = enemyArr[0];

			bool formationReached = true;//assume formaion has been formed
			int currentSize = 0;//declared outside to be used as a size() for enemyArr;

			////check for bullet collisions & formation status////
			for (; currentSize < enemyArr.size(); currentSize++) {

				enemyArr[currentSize]->draw(window);
				//enemy firing
				if (shouldFire(mode)) {
					//will create a non-friendly bullet of type 1
					bulletArr.push_back(new Bullet(1, 0, enemyArr[currentSize]->getX() + 20, enemyArr[currentSize]->getY() + 40));
				}

				//moving to initial positions
				if (!enemyArr[currentSize]->getReached()) {//move towards xFinal & yFinal
					enemyArr[currentSize]->moveToInitial();
				}

				//if enemy formation is not complete
				if (!enemyArr[currentSize]->getReached()) { formationReached = false; }
				//if that enemy has reached final then decide leftmost, rightmost and lowest
				else {
					if (enemyArr[currentSize]->getSprite().getPosition().x > rightmost->getSprite().getPosition().x) {
						rightmost = enemyArr[currentSize];//getting rightmost
					}
					if (enemyArr[currentSize]->getSprite().getPosition().x < leftmost->getSprite().getPosition().x) {
						leftmost = enemyArr[currentSize];//getting leftmost
					}
					if (enemyArr[currentSize]->getSprite().getPosition().y > lowest->getSprite().getPosition().y) {
						lowest = enemyArr[currentSize];//getting lowest
					}
				}
			 
				//checking for collisions:
				if (checkCollisionWithAllBullets(enemyArr[currentSize], window)) {
					//if collided with a friendly bullet
					enemyArr[currentSize]->setHealth(enemyArr[currentSize]->getHealth() - 1);//decrease health
					score += 30;//add 30 score for every bullet hit
				}
				//check for collision with UserCraft
				if (collides(player->getSprite(), enemyArr[currentSize]->getSprite(), window)) {
					enemyArr[currentSize]->setHealth(0);//kill on collision with user
					player->setHealth(player->getHealth() - 2);//user health is decreased by 2 on impact with enemycraft
					score -= 100;//deduct 100 score for hitting enemy craft
					}
				//removing dead enemies
				if (enemyArr[currentSize]->getHealth() <= 0) {//if enemy health == 0 -> pop out of enemyArr

					if (enemyArr[currentSize] != nullptr) {
						delete enemyArr[currentSize];
						enemyArr[currentSize] = nullptr;
					}
					enemyArr.erase(enemyArr.begin() + currentSize);
					currentSize--;
					score += 100;
				}
			}

				///enemy movement & update leftmost lowest, etc///
				if (formationReached) {//enemy formation is complete
					moveFormationNormally(currentSize);
				}
		}

		////////////*********to be implemented*************//////////////
		else {

			wadiBala->draw(window);
			//initial movement
			if (!wadiBala->getReached()) {
				wadiBala->moveToInitial();
			}
			//firing//
			else {
				if (BalashouldFire()) {//fire 10% of the time
					bulletArr.push_back(new Bullet(1, 0, wadiBala->getX() + 45, wadiBala->getY() + 130));
					bulletArr.push_back(new Bullet(2, 0, wadiBala->getX() + 45, wadiBala->getY() + 130));
					bulletArr.push_back(new Bullet(3, 0, wadiBala->getX() + 45, wadiBala->getY() + 130));
				}
			}

			if (checkCollisionWithAllBullets(window)) {
				wadiBala->setHealth(wadiBala->getHealth() - 1);
			}

			if (wadiBala->getHealth() <= 0) {
				currentLevel++;
			}
		}
	}
	

	////move the bullets and check for scope////
	for (int i = 0; i < bulletArr.size(); i++) {

		if (collides(player->getSprite(), bulletArr[i]->getSprite(),window) && !bulletArr[i]->getIsFriendly()) {
			//if enemy bullet hits player
			player->setHealth(player->getHealth() - 1);
			//deleting the bullet
			if (bulletArr[i] != nullptr) {
				delete bulletArr[i];
				bulletArr[i] = nullptr;
			}
			bulletArr.erase(bulletArr.begin() + i);
			i--;
		}
		else if (bulletArr[i]->isOutOfScope()) {
		    //if bullet has moved out of scope:
				if (bulletArr[i] != nullptr) {
					delete bulletArr[i];
					bulletArr[i] = nullptr;
				}
				bulletArr.erase(bulletArr.begin() + i);
				i--;
		}
	}
	
	for (int i = 0; i < bulletArr.size(); i++) {
		bulletArr[i]->draw(window);
		bulletArr[i]->move();
	}

	//////********winning conditions******///////////
	if (formationKilled && currentLevel >= 2) {
		won = true;
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
	//deallocating user craft
	if (player != nullptr) {
		delete player;
		player = nullptr;
	}
	//deallocating bigboss
	if (wadiBala != nullptr) {
		delete wadiBala;
		wadiBala = nullptr;
	}
}