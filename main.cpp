#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.h"
#include"spacecraftandbullet.h"
#include"playGame.h"

#include <fstream>
using namespace std;
using namespace sf;
int main()
{
   /* cout << mousePos.x << "\t\t";
   * 
   * 
    cout << mousePos.y << endl;*/
    RenderWindow window(VideoMode(900, 900), "Cosmic Assault");
    window.setFramerateLimit(120);
    Event event;
    int mainMenuChoice = 0, selectionMenuChoice;
    bool modeMenuChoice = 0;
    while (window.isOpen())
    {
        static int i = 0;
        if(i++==0)  welcomeScreen(window);    
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }    
        window.clear();  
        backgroundAnimation(window);

        if (mainMenuChoice == 0) {

            mainScreen(window, event, mainMenuChoice);
        }
        if (mainMenuChoice == 1)     // it will go in mode menu
        {
            bool openSelectionMenu = 0;
            modeMenu(window, event,mainMenuChoice,modeMenuChoice);
            if (modeMenuChoice) // for easy mode
            {


                openSelectionMenu = 1;
            }
            else if (!modeMenuChoice) // for expert mode
            {


                openSelectionMenu = 1;
            }
        

            cout << mainMenuChoice << endl;
           // choice = 1;
        }
        if (mainMenuChoice == 7) {
            selectionMenu(window, event, mainMenuChoice, selectionMenuChoice);
            cout << "sel menu\n";
        }
        if (mainMenuChoice == 8) {//play game

            PLayGame* game = new PLayGame(modeMenuChoice,selectionMenuChoice);
            do {
                window.clear();
                game->play(window,event);
                window.display();

            } while (!game->getWon());
            if (game->getWon()) {

                mainMenuChoice = 0;

                endingScreen(window, event, "GAME WON!");
            }
            cout << "Pleeeeyy\n";
            delete game;
        }
        else if (mainMenuChoice == 2)    // will go in leaderboard
        {
            window.clear();
            leaderBoard(window,event, mainMenuChoice);
            cout << mainMenuChoice << endl;
         //   mainMenuChoice = 0;
        }
        else if (mainMenuChoice == 3) // will go in credits screen
        {
          // string name = getPlayerName(window,event);
            endingScreen(window, event,"YOU LOST!");
            //creditScreen(window, event, mainMenuChoice);
            cout << mainMenuChoice << endl;
            //mainMenuChoice = 0;
        }
        else if (mainMenuChoice == 4) // will go to instruction screen
        {
            instructions(window, event, mainMenuChoice);
            cout << mainMenuChoice << endl; 
            //mainMenuChoice = 0;
        }


        window.display();
    }



	system("pause");
	return 0;
}

