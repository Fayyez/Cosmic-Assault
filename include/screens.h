#pragma once

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
void updateLeaderboard(const string& name, int score, vector<pair<string, int>>& leaderboard);
void textFillColor(Vector2i mousePos, Text & text, int y_i, int y_f, int x_i, int x_f);// will fill colour of text when cursor will be places on it
void boxFillColor(Vector2i mousePos, RectangleShape& shape, int y_i, int y_f, int x_i, int x_f);// will fill colour of rectangular box when cursor will be places on it
void mainScreen(RenderWindow& window, Event& event, int& mainMenuChoice);
void modeMenu(RenderWindow& window, Event& event, int& mainMenuChoice,bool & modeMenuChoice);
void selectionMenu(RenderWindow& window, Event& event, int& mainMenuChoice,int & selectionMenuChoice);
void animate(RenderWindow& window, Event& event, Sprite spaceShip);
void welcomeScreen( RenderWindow &  window);
void backgroundAnimation(RenderWindow & window);
void exitButton(RenderWindow& window, Event& event, int& mainMenuChoice);
void circleFillColor(Vector2i mousePos, CircleShape& shape, int y_i, int y_f, int x_i, int x_f);// i = initial position & f = final position
void leaderBoard(RenderWindow& window, Event& event, int& mainMenuChoice);
void instructions(RenderWindow& window, Event& event, int& mainMenuChoice);
void displayHeading(RenderWindow& window, string heading);
void endingScreen(RenderWindow& window, Event& event,string text);
string getPlayerName(RenderWindow& window, Event& event);
void printEscape(RenderWindow& window);