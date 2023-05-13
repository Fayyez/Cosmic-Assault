// adding imports
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

// using namespaces
using namespace sf;
using namespace std;

void moveShip(sf::Sprite& ship, float& x1, float& y1, float x2, float y2, float speed) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance <= speed) {
        x1 = x2;
        y1 = y2;
        ship.setPosition(x1, y1);
    }
    else {
        float ratio = speed / distance;
        x1 += dx * ratio;
        y1 += dy * ratio;
        ship.setPosition(x1, y1);
    }
}

// function to destroy both sprites on collision
void destroySprites(Sprite &ship, Sprite &bullet, RenderWindow &window, bool &bulletActive)
{
    // get the global bounds of the sprites
    FloatRect shipBounds = ship.getGlobalBounds();
    FloatRect bulletBounds = bullet.getGlobalBounds();
    
    // check if the global bounds intersect
    if (shipBounds.intersects(bulletBounds)) {
        // destroy the sprites
        ship.setTextureRect(IntRect(0, 0, 0, 0));
        //bullet.setTextureRect(IntRect(0, 0, 0, 0));

        // erase the sprites from the screen
        window.draw(ship);
        //window.draw(bullet);

        // set bulletActive to false to stop drawing it
        bulletActive = false;
    }
}

int main()
{
    /*
    Texture bg;
    bg.loadFromFile("assets/background.jpg");
    */

    // initializing variables
    float t1 = 0, t2 = 0;
    float x1 = -70, y1 = 200;
    float x2 = 570, y2 = 200;
    float x = 225, y = 434;
    bool bulletActive = false;

    // initiating window
    RenderWindow window(VideoMode(600, 600), "COSMIC ASSAULT");
    window.setFramerateLimit(90);

    // loading textures
    Texture shipTexture, bulletTexture, villainTexture;
    shipTexture.loadFromFile("assets/spaceship1.png");
    bulletTexture.loadFromFile("assets/milk_bullet.png");
    villainTexture.loadFromFile("assets/doggo_villain.png");

    // setting villain ship and bullet sprites
    Sprite ship2(villainTexture), ship3(villainTexture), bullet(bulletTexture);

    //ship2.setPosition(x1, y1);

    // window open area
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        // friendly ship declaration
        Sprite ship1(shipTexture);
        ship1.setTexture(shipTexture);
        //ship2.setPosition(x1, y1);
        ship1.setPosition(x, y);

        // key press movement adjustments
        if (Keyboard::isKeyPressed(Keyboard::Right)&& x-90 < window.getSize().x - ship1.getGlobalBounds().width)
        {
            x += 5;
            ship1.move(5, 0);
            // cout << "Right" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left) && x+90  < window.getSize().x) {
            x -= 5; ship1.move(-5, 0);
            //cout << "Left" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && y < window.getSize().y - ship1.getGlobalBounds().height) {
            y += 5; ship1.move(0, 5);
            // cout << "Down" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && y+70 < window.getSize().y) {
            y -= 5; ship1.move(0, -5);
            //cout << "up" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) && !bulletActive) {
            bulletActive = true;
            bullet.setTexture(bulletTexture);
            bullet.setPosition(x + 50, y - 10);
        }
        if (bulletActive) {
            bullet.move(0, -10);
            if (bullet.getPosition().y < -60) {
                bulletActive = false;
            }
        }
        
        /*
        RectangleShape background;
        background.setSize(Vector2f(600.0f, 600.0f));
        background.setTexture(&bg);
        window.draw(background);
        */

        // window clearing
        window.clear(Color::Black);
        
        // ships drawing
        window.draw(ship2);
        window.draw(ship3);
        window.draw(ship1);
        
        // moving ship to init pos
        moveShip(ship2, x1, y1, 225, 40, 4);
        moveShip(ship3, x2, y2, 60, 40, 6);

        // destroying sprites per collision
        destroySprites(ship2, bullet, window, bulletActive);
        destroySprites(ship3, bullet, window, bulletActive);
        
        // bullet drawing
        if (bulletActive) {
            window.draw(bullet);
        }

        // display window
        window.display();
    }

    return 0;
}