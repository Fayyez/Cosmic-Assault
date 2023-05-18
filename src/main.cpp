#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "screens.h"
#include "spacecraftAndBullet.h"
#include "playGame.h"
#include <fstream>
#include <windows.h>

using namespace std;
using namespace sf;

void updateBackground(int& bgTimer, vector<Sprite>& backgrounds, Sprite& background) {
    int timerLimit = 30;
    if (bgTimer < timerLimit) bgTimer++;
    if (bgTimer >= timerLimit) {
        backgrounds.push_back(background);
        bgTimer = 0;
    }

    for (int i = 0; i < backgrounds.size(); i++) {
        backgrounds[i].move(0, 10);
        if (background.getPosition().y >= backgrounds[i].getGlobalBounds().height) {
            backgrounds.erase(backgrounds.begin() + i);
        }
    }
}
void drawBackground(RenderWindow& window, vector<Sprite>& backgrounds) {
    for (int i = 0; i < backgrounds.size(); i++)
        window.draw(backgrounds[i]);
}
void creditScreen(RenderWindow& window, Event& event, int& mainMenuChoice, int& bgTimer, vector<Sprite>& backgrounds, Sprite& background)
{
    ifstream creditsR("txt/credits.txt");
    int posX = 00, posY = 850;
    int fontSize = 20;
    Text text[32];
    string line[32];
    Font font;
    font.loadFromFile("fonts/IceCold.ttf");
    int q = 0;
    while (getline(creditsR, line[q])) // Fix: use getline directly instead of checking eof()
    {
        q++;
    }
    // will load sentences from file

    for (int i = 0; i < 32; i++)
    {
        text[i].setCharacterSize(25);
        text[i].setLetterSpacing(1);
        text[i].setFont(font);
        text[i].setString(line[i]);
        text[i].setOutlineThickness(3);
        text[i].setOutlineColor(Color::White);
        text[i].setFillColor(Color::Red);
        text[i].setPosition(posX, posY);
        posY += 30;
    }

    // Start the animation
    posY = 900;
    int i = 0;
    int sizeOfLoop = 32;// it will increase every time loop iterates because every time more text will be displayed on screen than previous
    while (window.isOpen())
    {
        window.clear();
        updateBackground(bgTimer, backgrounds, background);
        drawBackground(window, backgrounds);
        for (int i = 0; i < 32; i++) {
            //text[i].move(text[i].getPosition().x, text[i].getPosition().y - 30);
            text[i].setPosition(text[i].getPosition().x, text[i].getPosition().y - 1);
            window.draw(text[i]);
            //sleep(milliseconds(20));   
        }

        exitButton(window, event, mainMenuChoice);
        window.display();
        //sleep(milliseconds(100));
        if (mainMenuChoice == 0) break;

    }

    creditsR.close(); // Fix: close the file after reading
}
int main()
{
   /* cout << mousePos.x << "\t\t";
   * 
   * 
    cout << mousePos.y << endl;*/
   
    RenderWindow window(VideoMode(900, 900), "Cosmic Assault");
    window.setFramerateLimit(120);
    Event event;
    ///background///
    Texture bgTexture;
    bgTexture.loadFromFile("assets/background2.png");
    int bgTimer = 0;
    Sprite background(bgTexture);
    vector<Sprite> backgrounds;
    background.setPosition(0,-300);
    ///choices///
    int mainMenuChoice = 0, selectionMenuChoice;
    bool modeMenuChoice = 0;
    SoundBuffer introBuffer,mainBuffer;
    Sound introSound, mainSound;
    introBuffer.loadFromFile("sounds/intro_sound.wav");
    introSound.setBuffer(introBuffer);
    bool mainMenuSong = 0;
    bool playGameSong = 0;
    Music musicTrack;
    musicTrack.openFromFile("tomjerry.ogg");
    Music leaderboardTrack;
    leaderboardTrack.openFromFile("standupforchampion.ogg");
    Music creditTrack;
    creditTrack.openFromFile("pink_panther_credit.ogg");
    Music shot;
    shot.openFromFile("pishu.ogg");
    while (window.isOpen())
    {
        static int i = 0;
        if (i++ == 0) {
            introSound.play();
            welcomeScreen(window);
        }
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        if (!(musicTrack.getStatus()==Music::Playing)) {
            musicTrack.play();
          //  mainMenuSong = 1;
        }

        //backgroundAnimation(window);
        if (mainMenuChoice != 3) {
            window.clear();
            updateBackground(bgTimer, backgrounds, background);
            drawBackground(window, backgrounds);
        }

        if (mainMenuChoice == 0) {

            mainScreen(window, event, mainMenuChoice);
        }
        if (mainMenuChoice == 1)     // it will go in mode menu
        {
            bool openSelectionMenu = 0;
            window.clear();
            updateBackground(bgTimer, backgrounds, background);
            drawBackground(window, backgrounds);
            modeMenu(window, event, mainMenuChoice, modeMenuChoice);
            cout << mainMenuChoice << endl;
            // choice = 1;
        }
        if (mainMenuChoice == 7) {

            window.clear();
            updateBackground(bgTimer, backgrounds, background);
            drawBackground(window, backgrounds);
            selectionMenu(window, event, mainMenuChoice, selectionMenuChoice);
            cout << "sel menu\n";
        }
        if (mainMenuChoice == 8) {//play game

            if(musicTrack.getStatus()==Music::Playing) musicTrack.stop();
            PlayGame* game = new PlayGame(modeMenuChoice, selectionMenuChoice);
            do {
                window.clear();
                updateBackground(bgTimer, backgrounds, background);
                drawBackground(window, backgrounds);
                game->play(window, event, mainMenuChoice,shot);
                printEscape(window);
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    mainMenuChoice = 0;
                    break;
                }

                window.display();
              

            } while (!game->getWon() && !game->getLose());

            if (game->getWon()) {

                mainMenuChoice = 0;
                window.clear();
                updateBackground(bgTimer, backgrounds, background);
                drawBackground(window, backgrounds);
                endingScreen(window, event, "GAME WON!");
               // string name = getPlayerName(window, event);
            }
            else if (game->getLose()) {
                mainMenuChoice = 0;
                window.clear();
                updateBackground(bgTimer, backgrounds, background);
                drawBackground(window, backgrounds);
                endingScreen(window, event, "YOU LOST!");
            }
            cout << "Pleeeeyy\n";
            delete game;
        }
             
        if (musicTrack.getStatus() == Music::Stopped()) musicTrack.play();
        else if (mainMenuChoice == 2)    // will go in leaderboard
        {
            updateBackground(bgTimer, backgrounds, background);
            drawBackground(window, backgrounds);
            leaderBoard(window, event, mainMenuChoice);
            cout << mainMenuChoice << endl;
          
        }
            else if (mainMenuChoice == 3) // will go in credits screen
            {
                musicTrack.stop();
                if (creditTrack.getStatus() == Music::Stopped) creditTrack.play();
                window.clear();
                creditScreen(window, event, mainMenuChoice, bgTimer, backgrounds, background);
                cout << mainMenuChoice << endl;
                if (mainMenuChoice == 0) {
                    creditTrack.stop();
                    musicTrack.play();
                }
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

