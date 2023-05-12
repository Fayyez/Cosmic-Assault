#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header.h"
using namespace std;
using namespace sf;
int main()
{
   /* cout << mousePos.x << "\t\t";
    cout << mousePos.y << endl;*/
    RenderWindow window(VideoMode(900, 900), "Cosmic Assault");
    window.setFramerateLimit(90);
    Event event;
    int mainMenuChoice = 0, selectionMenuChoice;
    bool modeMenuChoice = 0;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }    
         window.clear();
        if(mainMenuChoice==0)  mainScreen(window, event, mainMenuChoice);
        if (mainMenuChoice == 1)
        {
            modeMenu(window, event,mainMenuChoice,modeMenuChoice);
            if (mainMenuChoice == 1)
            {


            }
            else if (mainMenuChoice == 2)
            {


            }
          //  selectionMenu((window, event, mainMenuChoice, selectionMenuChoice);

            cout << mainMenuChoice << endl;
           // choice = 1;
        }
        else if (mainMenuChoice == 2)
        {



            cout << mainMenuChoice << endl;
            mainMenuChoice = 0;
        }
        else if (mainMenuChoice == 3)
        {



            cout << mainMenuChoice << endl;
            mainMenuChoice = 0;

        }
        else if (mainMenuChoice == 4)
        {


            
            cout << mainMenuChoice << endl;
            mainMenuChoice = 0;

        }








        window.display();



    }



	system("pause");
	return 0;
}






















/*  Vector2i mousepos;
       Text text1("", font, 50);
       mousepos = Mouse::getPosition(window);
       text1.setCharacterSize(50);
       text1.setString("New Game");
       cout << mousepos.x << "         ";
       cout << mousepos.y << "\n";
       if (mousepos.y >= 150.0f && mousepos.y <= 210.0f && mousepos.x >= 249.0f && mousepos.x <= 512.0f)
       {
           text1.setFillColor(Color::Yellow);
       }
       else text1.setFillColor(Color::White);
       text1.setOutlineThickness(2);
       text1.setOutlineColor(Color::Red);
       text1.setPosition(Vector2f(250.0f, 150.0f));
       window.draw(text1);
       if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
       {
           mousepos = Mouse::getPosition(window);
           if (mousepos.y >= 150.0f && mousepos.y <= 210.0f && mousepos.x >= 249.0f && mousepos.x <= 512.0f)
           {
               window.clear();
               Sprite sprite;
               Texture tex;
               tex.loadFromFile("bsdk.png");
               sprite.setTexture(tex);
               sprite.setPosition(249.0f, 150.0f);
               window.draw(sprite);

           }


       }*/