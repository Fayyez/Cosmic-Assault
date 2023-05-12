#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main()
{
    int x = 250;
    int y = 634;
    //Sprite back;
    Texture bac;
    bac.loadFromFile("intro.png");
    //back.setTexture(bac);
   /* RectangleShape back;
    back.setSize(Vector2f(1100.0f, 800.0f));
    back.setTexture(&bac);*/
   // bac.loadFromFile("intro.png");




    RenderWindow window(sf::VideoMode(1100,800), "COSMIC ASSAULT");
    window.setFramerateLimit(120);

    // Declare bullet variables
    bool bulletActive = false;
    Texture bulletTexture;
    Sprite bulletSprite;
    if (!bulletTexture.loadFromFile("bullet.png"))
    {
        cout << "Bullet texture not loaded" << endl;
    }
    bulletSprite.setTexture(bulletTexture);

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
       /* cout << Mouse::getPosition(window).x << "\t\t";
        cout << Mouse::getPosition(window).y << "\n";*/
        // Create ship sprite
        cout << x << "\t" << y << "\n";

        Texture shipTexture;
        Sprite shipSprite;
        if (!shipTexture.loadFromFile("s_ship.png"))
        {
            cout << "Ship texture not loaded" << endl;
        }
        shipSprite.setTexture(shipTexture);
        shipSprite.setPosition(x, y);

        if (Keyboard::isKeyPressed(Keyboard::Right)&& x-90 < window.getSize().x - shipSprite.getGlobalBounds().width)
        {
            x += 5;
            shipSprite.move(5, 0);
           // cout << "Right" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left) && x+90  < window.getSize().x)
        {
            x -= 5;
            shipSprite.move(-5, 0);
            //cout << "Left" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)&& y < window.getSize().y - shipSprite.getGlobalBounds().height)
        {
            y += 5;
            shipSprite.move(0, 5);
           // cout << "Down" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && y+70 < window.getSize().y)
        {
            y -= 5;
            shipSprite.move(0, -5);
            //cout << "up" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) && !bulletActive)
        {
            bulletActive = true;
            bulletSprite.setPosition(x + 140, y - 10);
           // cout << "Up" << endl;
        }
        if (bulletActive)
        {
            bulletSprite.move(0, -10);
            if (bulletSprite.getPosition().y < -60)
            {
                bulletActive = false;
            }
        }

        window.clear(Color::Black);
        RectangleShape back;
        back.setSize(Vector2f(1100.0f, 800.0f));
        back.setTexture(&bac);
        window.draw(back);
        window.draw(shipSprite);
        if (bulletActive)
        {
            window.draw(bulletSprite);
        }
        window.display();
    }

    return 0;
}
