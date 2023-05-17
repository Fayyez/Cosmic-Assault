#include "playGame.h"
#include <sstream>
#include"screens.h"
using namespace std;
using namespace sf;

Font font;
Text currentScore;
bool shouldFire(bool& mode)
{ // returns true 10% of the time if status is true and 7%if status is false

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(0.0f, 1.0f);

    float chances;
    chances = dis(gen);
    if (mode)
    { // for expert mode = 10%
        return (chances <= 0.0007f);
    }
    else
    { // for beginers mode 7%

        return (chances <= 0.0005f);
    }
}
bool BalashouldFire(bool& mode)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(0.0f, 1.0f);

    float chances;
    chances = dis(gen);
    if (mode)
    { // for expert mode = 10%
        return (chances <= 0.007f);
    }
    else
    { // for beginers mode 7%

        return (chances <= 0.004f);
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

// int score;//stores current score of user, adds 50 for every successful kill
// int currentLevel;//it starts with level 0 and is incrementd for each enemy formation that is called
// int speed;//speed of movement of enemy formation {is higher for expert mode}; increasing every 30s
// bool won;//true when user has won the game, i.e, defeated the BigBoss
// bool mode;//true foe expert mode
// bool direcrion;//true if enemy formation is moving rightwards and vice versa
// Clock totalTime;
// Clock clockForFiring
// Time totalTime;
// Time timeFromLastFire;//to keep track of total game time since the game began
// Time cooldownTime;//Usercraft* player;
// vector<Powerup*> powerupArr;
// vector<Bullet*> bulletArr;
// vector<EnemyCraft*> enemyArr;
// int formation[10][18];
///*
//* formation[][] is used as a reference for creating an enemy formation
//* with its [row]&[column] defining the x_final & y_final of the enemy craft
//*/
// BigBoss* wadiBala;//obj of bigbossis created only when user has passed 5 levels
// EnemyCraft* rightmost;
// EnemyCraft* leftmost;
// EnemyCraft* lowest;
PlayGame::PlayGame(bool mode, int craftChoice)
{ // starts with level 0 for beginner & 2 for expert
    this->score = 0;
    this->won = false;
    this->lose = false;
    this->mode = mode;
    this->direction = true; // initially move formation to right
    this->clockTotal.restart();
    this->clockForFiring.restart();
    this->cooldownTime = seconds(0.35f);
    this->timeFromLastFire = clockForFiring.getElapsedTime();
    string imageName;
    // craft choice of user
    if (craftChoice == 1)
        imageName = "assets/s_ship.png"; //********//
    else if (craftChoice == 2)
        imageName = "assets/s_ship.png";
    else if (craftChoice == 3)
        imageName = "assets/s_ship.png";
    if (mode)
    { // expert mode
        currentLevel = 2;
        speedOfFormation = 6;
        player = new Usercraft(370, 1000, 370, 740, imageName, 50); //*****HEALTH PART TO BE IMPLEMENTED*********//
        read = new ifstream("txt/difficult.txt");
    }
    else
    { // beginners mode
        currentLevel = 0;
        speedOfFormation = 2;
        ///*********HEALTH PART TO BE IMPLEMENTED&*******************///
        player = new Usercraft(370, 1000, 370, 740, imageName, 100);
        read = new ifstream("txt/easy.txt");
    }
    wadiBala = new BigBoss(350, -120, 350, 200);
}
void PlayGame::setSpeed(int s) { speedOfFormation = s; }
void PlayGame::setWon(bool status) { won = status; }
bool PlayGame::getWon() const { return won; }
bool PlayGame::getLose() const { return lose; }
bool PlayGame::playerIsDead()
{
    if (player->getHealth() == 0)
    {
        return false;
    }
    else
        return true;
}
bool PlayGame::sessionCompleted()
{ // returns true if it is time to bring out bigBoss
    totalTime = clockTotal.getElapsedTime();
    return (timeFromLastFire.asSeconds() > 160);
}
void PlayGame::printStats(RenderWindow& window)
{
    //font.loadFromFile("fonts/IceCold.ttf"); // loading font from a file
    //char scorebuffer[16];
    //snprintf(scorebuffer, sizeof(scorebuffer), "%d", score);
    //currentScore.setFont(font);
    //currentScore.setString(ss.str().c_str());
    //currentScore.setFillColor(Color::Yellow);
    //currentScore.setCharacterSize(24);
    //currentScore.setPosition(20.0f, 40.0f);
    //window.draw(currentScore);
}
bool PlayGame::formationIsKilled()
{ // if formation is killed, level is incremented

    if (enemyArr.size() == 0)
    {
        return true;
    }
    return false;
}
void PlayGame::createEnemy(int type, int xFinal, int yFinal)
{
    // convert [i][j] of array into xy of window
    xFinal += 60 * xFinal + 65;
    yFinal += 60 * yFinal + 100;
    // creating random origins:
    int x = 0, y = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 5);

    // Generate a random number between 0 and 4 (inclusive)
    int randomOrigin = distribution(gen); // will give 0 - 4 randomnly
    // assigning origin:
    switch (randomOrigin)
    {
    case 0:
        x = 400;
        y = -60;
        break;
    case 1:
        x = 920;
        y = 500;
        break;
    case 2:
        x = 935;
        y = 660;
        break;
    case 3:
        x = -60;
        y = 350;
        break;
    case 4:
        x = -70;
        y = 510;
        break;
    default:
        x = -80;
        y = 720;
        break;
    }

    // creating enemies of responding type
    if (type == 1)
    {
        enemyArr.push_back(new EnemyGreen(x, y, xFinal, yFinal));
    }
    else if (type == 2)
    {
        enemyArr.push_back(new EnemyRed(x, y, xFinal, yFinal));
    }
    else if (type == 3)
    {
        enemyArr.push_back(new EnemyBlue(x, y, xFinal, yFinal));
    }
}
void PlayGame::createFormation(bool& status)
{ // fills formation[][] according to level every 30sec

    // create a rectangle of 4X10 all greens
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            int temp = 0;
            (*read) >> temp;
            if (temp != 0)
            {
                createEnemy(temp, j, i);
            }
        }
    }
    status = !status;
}
bool PlayGame::checkCollisionWithAllBullets(EnemyCraft* craft, RenderWindow& window)
{
    // return true if spacecraft sprties collided with a bullet

    for (int i = 0; i < bulletArr.size(); i++)
    {

        if (collides(craft->getSprite(), bulletArr[i]->getSprite(), window) && bulletArr[i]->getIsFriendly())
        {
            // returns true if any friendly bullet collides with that enemy craft
            // remove the bullet from bulletArr & delete the pointer
            if (bulletArr[i] != nullptr)
            {
                delete bulletArr[i];
                bulletArr[i] = nullptr;
            }
            bulletArr.erase(bulletArr.begin() + i); // pop out that bullet
            i--;
            return true;
        }
    }
    return false;
}
bool PlayGame::checkCollisionWithAllBullets(RenderWindow& window)
{

    for (int i = 0; i < bulletArr.size(); i++)
    {

        if (collides(wadiBala->getSprite(), bulletArr[i]->getSprite(), window) && bulletArr[i]->getIsFriendly())
        {
            // returns true if any friendly bullet collides with that enemy craft
            // remove the bullet from bulletArr & delete the pointer
            if (bulletArr[i] != nullptr)
            {
                delete bulletArr[i];
                bulletArr[i] = nullptr;
            }
            bulletArr.erase(bulletArr.begin() + i); // pop out that bullet
            i--;
            return true;
        }
    }
    return false;
}
void PlayGame::moveFormationNormally(int currentSize)
{

    if (leftmost->getX() <= 10 || rightmost->getX() >= 850)
    {
        // if formation has touched right/left boundary -> move down
        for (int i = 0; i < currentSize; i++)
        {
            enemyArr[i]->moveSprite(0, 10);
        }
        direction = !direction; // changing direction of motion of formation
    }

    if (direction)
    { // if moving towards right
        for (int i = 0; i < currentSize; i++)
        {
            enemyArr[i]->moveSprite(1.5, 0); // move all enemies 5pixels to right
        }
    }

    else
    { // moving to left
        for (int i = 0; i < currentSize; i++)
        {
            enemyArr[i]->moveSprite(-1.5, 0); // move all enemies 5pixels to left
        }
    }
}
void PlayGame::play(RenderWindow& window, Event& event, int& mainMenuChoice)
{

    /////////player movement-&-collision checks/////////
    player->draw(window);
    printStats(window);
    if (player->getReached() == 0)
    { // if player hasn't reached its destination
        player->moveToInitial();
    }
    else
    {
        ////*********movement BOUNDARIES TO BE ADDED with user input and fire********//////////
        timeFromLastFire = clockForFiring.getElapsedTime();

        if (Keyboard::isKeyPressed(Keyboard::Space) && timeFromLastFire >= cooldownTime)
        {
            clockForFiring.restart();
            bulletArr.push_back(new Bullet(1, 1, player->getX() + 32, player->getY(), "assets/bullet.png"));
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && player->getX() < 810)
        {
            player->moveSprite(5, 0);
            // cout << "Right" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left) && player->getX() > 10)
        {
            player->moveSprite(-5, 0);
            // cout << "Left" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && player->getY() < 790)
        {
            player->moveSprite(0, 5);
            // cout << "Down" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && player->getY() > 650)
        {
            player->moveSprite(0, -5);
            // cout << "up" << endl;
        }
    }

    // untill not time for bigBoss
    bool formationKilled = formationIsKilled();
    if (player->getReached())
    { // enemies and bigboss appear once player has reached initial

        if (!formationKilled || (mode && currentLevel < 7) || (!mode && currentLevel < 5))
        {
            // if under normal conditions :

            if (formationKilled)
            { // if enemies are not present on screen
                createFormation(formationKilled);
                currentLevel++;
            }
            // pointing leftmost, rightmost, lowest
            lowest = rightmost = leftmost = enemyArr[0];

            bool formationReached = true; // assume formaion has been formed
            int currentSize = 0;          // declared outside to be used as a size() for enemyArr;

            ////check for bullet collisions & formation status////
            for (; currentSize < enemyArr.size(); currentSize++)
            {

                enemyArr[currentSize]->draw(window);
                // enemy firing
                if (shouldFire(mode))
                {
                    // will create a non-friendly bullet of type 1
                    bulletArr.push_back(new Bullet(1, 0, enemyArr[currentSize]->getX() + 20, enemyArr[currentSize]->getY() + 40, "assets/enemy-bullet.png"));
                }

                // moving to initial positions
                if (!enemyArr[currentSize]->getReached())
                { // move towards xFinal & yFinal
                    enemyArr[currentSize]->moveToInitial();
                }

                // if enemy formation is not complete
                if (!enemyArr[currentSize]->getReached())
                {
                    formationReached = false;
                }
                // if that enemy has reached final then decide leftmost, rightmost and lowest
                else
                {
                    if (enemyArr[currentSize]->getSprite().getPosition().x > rightmost->getSprite().getPosition().x)
                    {
                        rightmost = enemyArr[currentSize]; // getting rightmost
                    }
                    if (enemyArr[currentSize]->getSprite().getPosition().x < leftmost->getSprite().getPosition().x)
                    {
                        leftmost = enemyArr[currentSize]; // getting leftmost
                    }
                    if (enemyArr[currentSize]->getSprite().getPosition().y > lowest->getSprite().getPosition().y)
                    {
                        lowest = enemyArr[currentSize]; // getting lowest
                    }
                }

                // checking for collisions:
                if (checkCollisionWithAllBullets(enemyArr[currentSize], window))
                {
                    // if collided with a friendly bullet
                    enemyArr[currentSize]->setHealth(enemyArr[currentSize]->getHealth() - 1); // decrease health
                    score += 10;                                                              // add 30 score for every bullet hit
                }
                // check for collision with UserCraft
                if (collides(player->getSprite(), enemyArr[currentSize]->getSprite(), window))
                {
                    enemyArr[currentSize]->setHealth(0);        // kill on collision with user
                    player->setHealth(player->getHealth() - 2); // user health is decreased by 2 on impact with enemycraft
                    score -= 100;                               // deduct 100 score for hitting enemy craft
                }
                // removing dead enemies
                if (enemyArr[currentSize]->getHealth() <= 0)
                { // if enemy health == 0 -> pop out of enemyArr

                    if (enemyArr[currentSize] != nullptr)
                    {
                        delete enemyArr[currentSize];
                        enemyArr[currentSize] = nullptr;
                    }
                    enemyArr.erase(enemyArr.begin() + currentSize);
                    currentSize--;
                    score += 50;
                }
            }

            /// enemy movement & update leftmost lowest, etc///
            if (formationReached)
            { // enemy formation is complete
                moveFormationNormally(currentSize);
            }
        }

        ////////////*********BigBoss************//////////////
        else
        {
            // printing on window
            wadiBala->draw(window);
            // movements
            if (!wadiBala->getReached())
            {
                wadiBala->moveToInitial();
            }
            else
            {
                int x = 0, y = 0;
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> distribution(0, 6);

                // Generate a random number between 0 and 4 (inclusive)
                int randomFinal = distribution(gen); // will give 0 - 4 randomnly
                // assigning origin:
                switch (randomFinal)
                {

                case 0:
                    x = 120;
                    y = 100;
                    break;
                case 1:
                    x = 400;
                    y = 500;
                    break;
                case 2:
                    x = 300;
                    y = 150;
                    break;
                case 3:
                    x = 730;
                    y = 300;
                    break;
                default:
                    x = 350;
                    y = 200;
                    break;
                }
                wadiBala->setXFinal(x);
                wadiBala->setYFinal(y);
                wadiBala->setReached(0);
            }
            // shooting
            if (BalashouldFire(mode))
            { // fires 7% of the time
                int x = 0, y = 0;
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> distribution(0, 2);

                // Generate a random number between 0 and 4 (inclusive)
                int randomFinal = distribution(gen); // will give 0 - 4 randomnly
                // assigning origin:
                switch (randomFinal)
                {

                case 0:
                    bulletArr.push_back(new Bullet(1, 0, wadiBala->getX() + 45, wadiBala->getY() + 130, "assets/enemy-bullet.png"));
                    bulletArr.push_back(new Bullet(2, 0, wadiBala->getX() + 45, wadiBala->getY() + 130, "assets/enemy-bullet.png"));
                    bulletArr.push_back(new Bullet(3, 0, wadiBala->getX() + 45, wadiBala->getY() + 130, "assets/enemy-bullet.png"));
                    break;
                case 1:
                    bulletArr.push_back(new Bullet(1, 0, wadiBala->getX() + 45, wadiBala->getY() + 130, "assets/enemy-bullet.png"));
                    bulletArr.push_back(new Bullet(1, 0, wadiBala->getX() + 35, wadiBala->getY() + 130, "assets/enemy-bullet.png"));
                    bulletArr.push_back(new Bullet(1, 0, wadiBala->getX() + 55, wadiBala->getY() + 130, "assets/enemy-bullet.png"));
                    break;
                default:
                    bulletArr.push_back(new Bullet(1, 0, wadiBala->getX() + 45, wadiBala->getY() + 130, "assets/sonicBoom.png"));
                    break;
                }
            }
            // collision detection
            if (checkCollisionWithAllBullets(window))
            {
                wadiBala->setHealth(wadiBala->getHealth() - 1);
            }

            if (wadiBala->getHealth() <= 0)
            {
                won = true;
            }
        }
    }

    ////move the bullets and check for scope////
    for (int i = 0; i < bulletArr.size(); i++)
    {

        if (collides(player->getSprite(), bulletArr[i]->getSprite(), window) && !bulletArr[i]->getIsFriendly())
        {
            // if enemy bullet hits player
            player->setHealth(player->getHealth() - 1);
            // deleting the bullet
            if (bulletArr[i] != nullptr)
            {
                delete bulletArr[i];
                bulletArr[i] = nullptr;
            }
            bulletArr.erase(bulletArr.begin() + i);
            i--;
        }
        else if (bulletArr[i]->isOutOfScope())
        {
            // if bullet has moved out of scope:
            if (bulletArr[i] != nullptr)
            {
                delete bulletArr[i];
                bulletArr[i] = nullptr;
            }
            bulletArr.erase(bulletArr.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < bulletArr.size(); i++)
    {
        bulletArr[i]->draw(window);
        bulletArr[i]->move();
    }

    //////********ending conditions******///////////
    if (formationKilled && ((mode && currentLevel >= 7) || (!mode && currentLevel >= 5)) && wadiBala->getHealth() == 0)
    {
        // if no formation + level reached + wadibala is dead -> win
        won = true;
    }
    else if (player->getHealth() == 0 || lowest != nullptr)
    {
        if (lowest->getY() >= 900)
            // if player died or enemy ship crossed border
            lose = true;
    }
}
PlayGame::~PlayGame()
{

    // deallocate bullets
    for (int i = 0; i < bulletArr.size(); i++)
    {
        delete bulletArr[i];
        bulletArr[i] = nullptr;
    }
    // deallocate enemies
    for (int i = 0; i < enemyArr.size(); i++)
    {
        delete enemyArr[i];
        enemyArr[i] = nullptr;
    }
    // deallocate powerups
    for (int i = 0; i < powerupArr.size(); i++)
    {
        delete powerupArr[i];
        powerupArr[i] = nullptr;
    }
    // deallocating user craft
    if (player != nullptr)
    {
        delete player;
        player = nullptr;
    }
    // deallocating bigboss
    if (wadiBala != nullptr)
    {
        delete wadiBala;
        wadiBala = nullptr;
    }
    delete read;
    read = nullptr;
}