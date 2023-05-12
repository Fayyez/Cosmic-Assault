#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
void animate(RenderWindow& window, Event& event, Sprite & spaceShip)
{
    int shipX = 320, shipY = 750;
    while (spaceShip.getPosition().y > -20) {
        window.clear();
        spaceShip.setPosition(shipX, shipY);
        window.draw(spaceShip);
        spaceShip.move(shipX, shipY -= 10);
        window.display();
    }
}
void boxFillColor(Vector2i mousePos, RectangleShape & shape, int y_i, int y_f, int x_i, int x_f)// i = initial position & f = final position
{
    if (mousePos.y >= y_i && mousePos.y <= y_f && mousePos.x >= x_i && mousePos.x <= x_f)// it will hihlight or change colour of text whenever mouse cursor will be on it
    {
        shape.setFillColor(Color::Red);
    }
    else shape.setFillColor(Color::Green);

}
void textFillColor(Vector2i mousePos,Text & text, int y_i, int y_f, int x_i, int x_f)// i = initial position & f = final position
{
    if (mousePos.y >= y_i && mousePos.y <= y_f && mousePos.x >= x_i && mousePos.x <= x_f)// it will hihlight or change colour of text whenever mouse cursor will be on it
    {
        text.setFillColor(Color::Yellow);
    }
    else text.setFillColor(Color::White);

}
void mainScreen(RenderWindow& window, Event& event, int& mainMenuChoice)
{
    Vector2i mousePos;// defining to determine and handle mouse coordinates on window, it refers Mouse Position
    Font font;
    font.loadFromFile("res/Icecold.ttf");  // loading font from a file 
    Text text_1("New Game", font, 50);   //  assigning string to text, setting font which is loaded and 25 is font size
    text_1.setOutlineThickness(2);
    text_1.setOutlineColor(Color::Red);
    text_1.setPosition(Vector2f(315.0f, 115.0f));
    mousePos = Mouse::getPosition(window);
    textFillColor(mousePos, text_1, 115, 175, 315, 600);// will fill colour of text when cursor will be places on it
    window.draw(text_1);

    Text text_2("LEADERBOARD", font, 50);   //  assigning string to text, setting font which is loaded and 25 is font size
    text_2.setOutlineThickness(2);
    text_2.setOutlineColor(Color::Red);
    text_2.setPosition(Vector2f(255.0f, 235.0f));
    textFillColor(mousePos, text_2, 235, 295, 255, 655);
    window.draw(text_2);


    Text text_3("CREDITS", font, 50);   //  assigning string to text, setting font which is loaded and 25 is font size
    text_3.setOutlineThickness(2);
    text_3.setOutlineColor(Color::Red);
    text_3.setPosition(Vector2f(330.0f, 345.0f));
    textFillColor(mousePos, text_3, 345, 405, 330, 566);
    window.draw(text_3);

    Text text_4("INSTRUCTIONS", font, 50);   //  assigning string to text, setting font which is loaded and 25 is font size
    text_4.setOutlineThickness(2);
    text_4.setOutlineColor(Color::Red);
    text_4.setPosition(Vector2f(255.0f, 455.0f));
    textFillColor(mousePos, text_4, 455, 515, 255, 566);
    window.draw(text_4);
    static Sprite spaceShip;   // creates ship which will move left write in main screen
    static Texture texShip;     // static used to avoid redeclaration and redifination of ship every time loop reiterrates
    texShip.loadFromFile("sec_ship.png");     
    spaceShip.setTexture(texShip);
    static int shipX = 350, shipY = 700;  // defining coordinates at end of window
 
    spaceShip.setPosition(shipX, shipY); 
    static int moveShip = 5;      // will move ship by 5 coordinates
    if (spaceShip.getPosition().x<170|| spaceShip.getPosition().x >490) moveShip *= -1;   // when reaches one end, will help in changing the moving position of ship to other side
    spaceShip.move(moveShip, 0);
    shipX = shipX + moveShip;    // updates the x axis so that when loop reiterates in main, setposition donot reinitailizes at the centre
    window.draw(spaceShip);
    // below will get mouse input and update menuchoice accoring click for next screen
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        mousePos = Mouse::getPosition(window);
        if (mousePos.y >= 115.0f && mousePos.y <= 175.0f && mousePos.x >= 315.0f && mousePos.x <= 600.0f) mainMenuChoice = 1;
        if (mousePos.y >= 235.0f && mousePos.y <= 295.0f && mousePos.x >= 255.0f && mousePos.x <= 655.0f) mainMenuChoice = 2;
        if (mousePos.y >= 345.0f && mousePos.y <= 405.0f && mousePos.x >= 330.0f && mousePos.x <= 566.0f) mainMenuChoice = 3;
        if (mousePos.y >= 455.0f && mousePos.y <= 515.0f && mousePos.x >= 255.0f && mousePos.x <= 566.0f) mainMenuChoice = 4;
    }
    if(mainMenuChoice!=0)  animate(window, event, spaceShip);

}
void modeMenu(RenderWindow& window, Event& event, int& mainMenuChoice,bool & modeMenuChoice)
{
    window.clear();   // clear the window to print this next screen
    Vector2i mousePos;
    mousePos = Mouse::getPosition(window);
    
    Texture EBtexture;    // texture for exit button
    EBtexture.loadFromFile("EXIT.png");
    Sprite exitbutton;      // sprite fro exit button
    exitbutton.setTexture(EBtexture);
    exitbutton.setPosition(75.0f, 600.0f);   //defining posotion at down left corner
    window.draw(exitbutton);
    // if clicks at exit button then moves to mainmenu screen
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
    {
        if (mousePos.y >= 600.0f && mousePos.y <= 730.0f && mousePos.x >= 75.0f && mousePos.x <= 296.0f)
        {
            mainMenuChoice = 0;
        }
    }

    Font font;
    font.loadFromFile("res/Icecold.ttf");
    RectangleShape mode1, mode2;  // rectangle shapes for options of 2 modes as easy and hard
    mode1.setSize(Vector2f(250.0f, 50.0f));  // size for recatngle box 
    mode1.setFillColor(Color::Green);       // size of rectangle box 
    mode1.setPosition(Vector2f(330.0f, 250.0f));
    boxFillColor(mousePos, mode1, 250, 302, 330, 580);// fill mode1 which is a box, with red colour when cursor is places
    Text textForMode1("Newbie",font,40);     //  text defining for easy mode
    textForMode1.setLetterSpacing(4);
    textForMode1.setOutlineThickness(3);
    textForMode1.setFillColor(Color::Blue);
    textForMode1.setOutlineColor(Color::Black);
    textForMode1.setPosition(Vector2f(365.0f, 251.0f));
    //mode1.setPosition
    window.draw(mode1);
    window.draw(textForMode1);
    //-------------now for mode 2 which will be expert mode
    mode2.setSize(Vector2f(250.0f,50.0f));  // size for recatngle box 
    mode2.setFillColor(Color::Green);       // size of rectangle box 
    mode2.setPosition(Vector2f(330.0f, 350.0f));
    boxFillColor(mousePos, mode2, 350, 400, 330, 580);// fill mode2 which is a box, with red colour when cursor is places
    Text textForMode2("Expert", font, 40);     //  text defining for easy mode
    textForMode2.setLetterSpacing(4);
    textForMode2.setOutlineThickness(3);
    textForMode2.setFillColor(Color::Blue);
    textForMode2.setOutlineColor(Color::Black);
    textForMode2.setPosition(Vector2f(355.0f, 351.0f));
    //mode2.setPosition
    window.draw(mode2);
    window.draw(textForMode2);
    //-------------
    // mouse user input for mode selection 
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        mousePos = Mouse::getPosition(window);
        if (mousePos.y >= 250.0f && mousePos.y <= 302.0f && mousePos.x >= 330.0f && mousePos.x <= 580.0f) modeMenuChoice = 0;
        if (mousePos.y >= 350.0f && mousePos.y <= 400.0f && mousePos.x >= 330.0f && mousePos.x <= 580.0f) modeMenuChoice = 1;
    }




}
void selectionMenu(RenderWindow& window, Event& event, int& mainMenuChoice, int& selectionMenuChoice)
{

}



