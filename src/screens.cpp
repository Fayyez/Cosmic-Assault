#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

void exitButton(RenderWindow& window,Event & event,int& mainMenuChoice)
{
    Vector2i mousePos;
    mousePos = Mouse::getPosition(window);

    Texture EBtexture;    // texture for exit button
    EBtexture.loadFromFile("assets/EXIT.png");
    Sprite exitbutton;      // sprite fro exit button
    exitbutton.setTexture(EBtexture);
    exitbutton.setPosition(838.0f, 40.0f);   //defining posotion at down left corner
    window.draw(exitbutton);
    // if clicks at exit button then moves to mainmenu screen
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (mousePos.y >= 40.0f && mousePos.y <= 100.0f && mousePos.x >= 838.0f && mousePos.x <= 898.0f)
        {
            mainMenuChoice = 0;
        }
    }
}
void displayHeading(RenderWindow & window, string heading)
{
    Font font;
    font.loadFromFile("fonts/IceCold.ttf");
    Text textForMode1(heading, font, 60);     //  text defining for easy mode
    textForMode1.setLetterSpacing(3);
    textForMode1.setOutlineThickness(3);
    textForMode1.setFillColor(Color::Yellow);
    textForMode1.setOutlineColor(Color::Black);
    textForMode1.setPosition(Vector2f(150.0f, 30.0f));
    window.draw(textForMode1);
    RectangleShape mode1;  // rectangle shapes for options of 2 modes as easy and hard
    mode1.setSize(Vector2f(900.0f, 20.0f));  // size for recatngle box 
    mode1.setFillColor(Color::Red);       // size of rectangle box 
    mode1.setPosition(Vector2f(0.0f, 120.0f));
    window.draw(mode1);
}
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
void circleFillColor(Vector2i mousePos, CircleShape& shape, int y_i, int y_f, int x_i, int x_f)// i = initial position & f = final position
{
    if (mousePos.y >= y_i && mousePos.y <= y_f && mousePos.x >= x_i && mousePos.x <= x_f)// it will hihlight or change colour of text whenever mouse cursor will be on it
    {
        shape.setFillColor(Color::Red);
    }
    else shape.setFillColor(Color::Cyan);

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
    displayHeading(window, "MAIN MENU");
    Vector2i mousePos;// defining to determine and handle mouse coordinates on window, it refers Mouse Position
    Font font;
    font.loadFromFile("fonts/IceCold.ttf");  // loading font from a file 
    Text text_1("New Game", font, 50);   //  assigning string to text, setting font which is loaded and 25 is font size
    text_1.setOutlineThickness(2);
    text_1.setOutlineColor(Color::Red);
    text_1.setPosition(Vector2f(315.0f, 165.0f));
    mousePos = Mouse::getPosition(window);
    textFillColor(mousePos, text_1, 165, 225, 315, 600);// will fill colour of text when cursor will be places on it
    window.draw(text_1);

    Text text_2("LEADERBOARD", font, 50);   //  assigning string to text, setting font which is loaded and 25 is font size
    text_2.setOutlineThickness(2);
    text_2.setOutlineColor(Color::Red);
    text_2.setPosition(Vector2f(235.0f, 295.0f));
    textFillColor(mousePos, text_2, 295, 355, 235, 635);
    window.draw(text_2);


    Text text_3("CREDITS", font, 50);   //  assigning string to text, setting font which is loaded and 25 is font size
    text_3.setOutlineThickness(2);
    text_3.setOutlineColor(Color::Red);
    text_3.setPosition(Vector2f(330.0f, 435.0f));
    textFillColor(mousePos, text_3, 435, 495, 330, 566);
    window.draw(text_3);

    Text text_4("INSTRUCTIONS", font, 50);   //  assigning string to text, setting font which is loaded and 25 is font size
    text_4.setOutlineThickness(2);
    text_4.setOutlineColor(Color::Red);
    text_4.setPosition(Vector2f(255.0f, 575.0f));
    textFillColor(mousePos, text_4, 575, 635, 255, 566);
    window.draw(text_4);
    static Sprite spaceShip;   // creates ship which will move left write in main screen
    static Texture texShip;     // static used to avoid redeclaration and redifination of ship every time loop reiterrates
    texShip.loadFromFile("assets/sec_ship.png");     
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
        if (mousePos.y >= 165.0f && mousePos.y <= 225.0f && mousePos.x >= 315.0f && mousePos.x <= 600.0f) mainMenuChoice = 1;
        if (mousePos.y >= 295.0f && mousePos.y <= 355.0f && mousePos.x >= 255.0f && mousePos.x <= 655.0f) mainMenuChoice = 2;
        if (mousePos.y >= 435.0f && mousePos.y <= 495.0f && mousePos.x >= 330.0f && mousePos.x <= 566.0f) mainMenuChoice = 3;
        if (mousePos.y >= 575.0f && mousePos.y <= 635.0f && mousePos.x >= 255.0f && mousePos.x <= 566.0f) mainMenuChoice = 4;
    }
    if(mainMenuChoice!=0)  animate(window, event, spaceShip);

}
void modeMenu(RenderWindow& window, Event& event, int& mainMenuChoice,bool & modeMenuChoice)
{
    displayHeading(window, "MODE MENU");
    Vector2i mousePos;
    mousePos = Mouse::getPosition(window);
    Font font;
    font.loadFromFile("fonts/Icecold.ttf");
    RectangleShape mode1, mode2;  // rectangle shapes for options of 2 modes as easy and hard
    mode1.setSize(Vector2f(350.0f, 50.0f));  // size for recatngle box 
    mode1.setFillColor(Color::Green);       // size of rectangle box 
    mode1.setPosition(Vector2f(270.0f, 250.0f));
    boxFillColor(mousePos, mode1, 250, 302, 270, 620);// fill mode1 which is a box, with red colour when cursor is places
    Text textForMode1("Newbie",font,40);     //  text defining for easy mode
    textForMode1.setLetterSpacing(4);
    textForMode1.setOutlineThickness(3);
    textForMode1.setFillColor(Color::Blue);
    textForMode1.setOutlineColor(Color::Black);
    textForMode1.setPosition(Vector2f(305.0f, 251.0f));
    //mode1.setPosition
    window.draw(mode1);
    window.draw(textForMode1);
    //-------------now for mode 2 which will be expert mode
    mode2.setSize(Vector2f(350.0f,50.0f));  // size for recatngle box 
    mode2.setFillColor(Color::Green);       // size of rectangle box 
    mode2.setPosition(Vector2f(270.0f, 350.0f));
    boxFillColor(mousePos, mode2, 350, 400, 270, 620);// fill mode2 which is a box, with red colour when cursor is places
    Text textForMode2("Expert", font, 40);     //  text defining for easy mode
    textForMode2.setLetterSpacing(4);
    textForMode2.setOutlineThickness(3);
    textForMode2.setFillColor(Color::Blue);
    textForMode2.setOutlineColor(Color::Black);
    textForMode2.setPosition(Vector2f(305.0f, 351.0f));
    //mode2.setPosition
    window.draw(mode2);
    window.draw(textForMode2);
    //-------------
    // mouse user input for mode selection 
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        mousePos = Mouse::getPosition(window);
        if (mousePos.y >= 250.0f && mousePos.y <= 302.0f && mousePos.x >= 330.0f && mousePos.x <= 680.0f) {
            modeMenuChoice = 0;
            mainMenuChoice = 7;
        }
        if (mousePos.y >= 350.0f && mousePos.y <= 400.0f && mousePos.x >= 330.0f && mousePos.x <= 680.0f) {
            modeMenuChoice = 1;
            mainMenuChoice = 7;
        }
       
    }
  
    exitButton(window, event, mainMenuChoice);
   
}
void welcomeScreen(RenderWindow& window)
{
    RectangleShape initial_background;   // background adjust to rectangle shape to be on full window
    Texture  i_background;
    i_background.loadFromFile("assets/welcome.png");
    initial_background.setTexture(&i_background);
    initial_background.setSize(Vector2f(900.0f, 900.0f));    // setting according to window size
    initial_background.setTexture(&i_background);
    int moveCosmic = 5, moveAssault = -7;    // first one will move cosmic sprite to right, 2nd will move assault sprite to left
    Sprite cosmic;
    Texture cos;
    cos.loadFromFile("assets/cosmic.png");
    cosmic.setTexture(cos);
    cosmic.setPosition(-30, 250);
    Sprite assault;
    Texture assau;
    assau.loadFromFile("assets/assault.png");
    assault.setTexture(assau);
    assault.setPosition(800, 370);


    while (true) {  // will run untill welcome screen completes

        window.clear();
        window.draw(initial_background);
        window.draw(cosmic);
        window.draw(assault);

        if (cosmic.getPosition().x > 250 && cosmic.getPosition().x < 270) // when reached at centre, will pause for a second and go away immediately and new screen pop ups
        {
            sleep(milliseconds(1000));
            moveCosmic = 25, moveAssault = -25;
        }
        cosmic.move(moveCosmic, 0);
        assault.move(moveAssault, 0);
        window.display();
        if (cosmic.getPosition().x >= 800) break;        // will break when both sprites will moveout of window

    }



}
void selectionMenu(RenderWindow& window, Event& event, int& mainMenuChoice, int& selectionMenuChoice)
{
    Vector2i mousePos;
    mousePos = Mouse::getPosition(window);
    // if clicks at exit button then moves to mainmenu screen
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (mousePos.y >= 700.0f && mousePos.y <= 830.0f && mousePos.x >= 75.0f && mousePos.x <= 296.0f)
        {
            mainMenuChoice = 0;
        }
    }
     Font font;
    font.loadFromFile("fonts/Icecold.ttf");
    CircleShape choice1, choice2,choice3;  // rectangle shapes for options of 2 modes as easy and hard
    choice1.setRadius(100);
    choice1.setOutlineThickness(5.f);
    choice1.setOutlineColor(Color::Red);
    //choice1.setSize(Vector2f(150.0f, 150.0f));  // size for recatngle box 
    choice1.setFillColor(Color::Cyan);       // size of rectangle box 
    choice1.setPosition(Vector2f(130.0f, 250.0f));
    circleFillColor(mousePos, choice1, 250, 450, 130, 330);// fill mode1 which is a box, with red colour when cursor is places
    //mode1.setPosition
    window.draw(choice1); Sprite ship1;
    Texture tShip1;
    tShip1.loadFromFile("assets/s_ship.png");
    ship1.setTexture(tShip1);
    ship1.setPosition(Vector2f(190.0f, 300.0f));
    window.draw(ship1);

    choice2.setRadius(100);
    choice2.setOutlineThickness(5.f);
    choice2.setOutlineColor(Color::Red);
   // choice2.setSize(Vector2f(150.0f, 150.0f));  // size for recatngle box 
    choice2.setFillColor(Color::Cyan);       // size of rectangle box 
    choice2.setPosition(Vector2f(360.0f, 250.0f));
    circleFillColor(mousePos, choice2, 250, 450, 360, 560);// fill mode1 which is a box, with red colour when cursor is places
    //mode1.setPosition
    window.draw(choice2);
    Sprite ship2;
    Texture tShip2;
    tShip2.loadFromFile("assets/s_ship.png");
    ship2.setTexture(tShip2);
    ship2.setPosition(Vector2f(418.5f, 300.0f));
    window.draw(ship2);

    choice3.setRadius(100);
    choice3.setOutlineThickness(5.f);
    choice3.setOutlineColor(Color::Red);
    //choice3.setSize(Vector2f(150.0f, 150.0f));  // size for recatngle box 
    choice3.setFillColor(Color::Cyan);       // size of rectangle box 
    choice3.setPosition(Vector2f(590.0f, 250.0f));
    circleFillColor(mousePos, choice3, 250, 450, 590, 790);// fill mode1 which is a box, with red colour when cursor is places
    //mode1.setPosition
    window.draw(choice3);
    Sprite ship3;
    Texture tShip3;
    tShip3.loadFromFile("assets/s_ship.png");
    ship3.setTexture(tShip3);
    ship3.setPosition(Vector2f(650.0f, 300.0f));
    window.draw(ship3);
    window.waitEvent(event);
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        mousePos = Mouse::getPosition(window);
        if (mousePos.y >= 250.0f && mousePos.y <= 450.0f && mousePos.x >= 130.0f && mousePos.x <= 330.0f) {
            mainMenuChoice = 8; 
            selectionMenuChoice = 1; 
        }
        if (mousePos.y >= 250.0f && mousePos.y <= 450.0f && mousePos.x >= 360.0f && mousePos.x <= 560.0f) {
            mainMenuChoice = 8;
            selectionMenuChoice = 2;
        }
        if (mousePos.y >= 250.0f && mousePos.y <= 450.0f && mousePos.x >= 590.0f && mousePos.x <= 790.0f) {
            mainMenuChoice = 8;
            selectionMenuChoice = 3;
        }
    }
    exitButton(window, event, mainMenuChoice);
}
void instructions(RenderWindow& window, Event& event, int& mainMenuChoice)
{
    Vector2i mousePos;
    mousePos = Mouse::getPosition(window);
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (mousePos.y >= 700.0f && mousePos.y <= 830.0f && mousePos.x >= 75.0f && mousePos.x <= 296.0f)
        {
            mainMenuChoice = 0;
        }
    }
    Sprite instruction;  // instructions picture;
    Texture intru;
    intru.loadFromFile("assets/instructio.png");
    instruction.setTexture(intru);
    instruction.setPosition(0, 0);
    window.draw(instruction);
    exitButton(window, event, mainMenuChoice);
}
void endingScreen(RenderWindow& window, Event& eventt, string text)
{
    int fontSize = 1;
    Font font;
    font.loadFromFile("fonts/Icecold.ttf");
    Text textForMode1(text, font, fontSize);     //  text defining for easy mode
    textForMode1.setLetterSpacing(4);
    textForMode1.setOutlineThickness(3);
    textForMode1.setFillColor(Color::Blue);
    textForMode1.setOutlineColor(Color::Black);
    textForMode1.setPosition(Vector2f(100.0f, 300.0f));

    while (true) {
        //window.clear();
        sleep(milliseconds(50));
        textForMode1.setCharacterSize(fontSize += 2);        // font size will increase and stop when it enlarges enough tobe in centre
        window.draw(textForMode1);
        if (fontSize > 70)
        {
            sleep(milliseconds(3000));            // pause so that user can see win or lose more clearly
            break; 
        }
        window.display();
    }
}
string getPlayerName(RenderWindow& window, Event& event)
{
    Font font;
    if (!font.loadFromFile("fonts/IceCold.ttf")) {
        // handle error
    }

    Text text("", font, 34);
    text.setFillColor(sf::Color::White);
    Text defaultText("Enter your Name :",font,40 ); // it is to declair above above box, so user know that he has to write his name
    defaultText.setFillColor(Color::Red);
    defaultText.setOutlineThickness(4);
    defaultText.setOutlineColor(Color::White);

    string playerName;
    bool done = false;

    while (!done)
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::TextEntered)
            {
                if (event.text.unicode == '\b' && !playerName.empty())
                {
                    playerName.pop_back();
                }
                else if (event.text.unicode < 128 && event.text.unicode != '\r' && event.text.unicode != '\n')
                {
                    playerName += static_cast<char>(event.text.unicode);
                }
            }
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter && !playerName.empty())
            {
                done = true;
            }
        }

        window.clear(sf::Color::Black);

        RectangleShape box(sf::Vector2f(500.f, 70.f));
        box.setPosition(200.f, 280.f);
        box.setFillColor(sf::Color(100, 100, 100));
        window.draw(box);
        defaultText.setPosition(200, 220);
        text.setString(playerName);
        text.setPosition(210.f, 290.f);
        window.draw(text);
        window.draw(defaultText);
        window.display();
    }

    return playerName;

}
void leaderBoard(RenderWindow& window, Event& event, int& mainMenuChoice)
{

    Font font;
    font.loadFromFile("fonts/Icecold.ttf");
    ifstream playerR("txt/players.txt"),scoreR("txt/score.txt");
    string players[7];
    string arr[7] {};
    if (!playerR.is_open()) cout << "File player not opened in leaderboard\n";
    int i = 0;
    while (!playerR.eof()&&i<7)
    {
        getline(playerR,players[i]);
        //playerR >> players[i];
        i++;
    }
    int nameX=50, nameY=200;    // used to set player name position in leaderboard
    Text names[7];
    for (int j = 0; j < 7; j++)
    {
        names[j].setCharacterSize(30);
        names[j].setLetterSpacing(3);
        names[j].setFont(font);
        names[j].setString(players[j]);
        names[j].setOutlineThickness(3);
        names[j].setOutlineColor(Color::White);
        names[j].setFillColor(Color::Red);
        names[j].setPosition(nameX,nameY);
        nameY += 60;
        window.draw(names[j]);
    }
    // printing leaderboard
    Text textForMode1("LeaderBoard", font, 60);     //  text defining for easy mode
    textForMode1.setLetterSpacing(2);
    textForMode1.setOutlineThickness(3);
    textForMode1.setFillColor(Color::Yellow);
    textForMode1.setOutlineColor(Color::Black);
    textForMode1.setPosition(Vector2f(110.0f, 30.0f));
    window.draw(textForMode1);
    RectangleShape mode1;  // rectangle shapes for options of 2 modes as easy and hard
    mode1.setSize(Vector2f(900.0f, 20.0f));  // size for recatngle box 
    mode1.setFillColor(Color::Red);       // size of rectangle box 
    mode1.setPosition(Vector2f(0.0f, 120.0f));
    window.draw(mode1);
  
    // for score reading rom file and printing
    i = 0;
    while (!scoreR.eof() && i < 7)
    {
        scoreR >> arr[i];
        i++;
    }
    int scoreX=650, scoreY=200;
    Text scores[7];
    for (int j = 0; j < 7; j++)
    {
        scores[j].setCharacterSize(30);
        scores[j].setLetterSpacing(3);
        scores[j].setFont(font);
        scores[j].setString(arr[j]);
        scores[j].setOutlineThickness(3);
        scores[j].setOutlineColor(Color::White);
        scores[j].setFillColor(Color::Red);
        scores[j].setPosition(scoreX, scoreY);
        scoreY += 60;
        window.draw(scores[j]);
    }
    exitButton(window, event, mainMenuChoice);

}
void creditScreen(RenderWindow& window, Event& event, int& mainMenuChoice)
{
    ifstream creditsR("txt/credits.txt");
    int posX = 300, posY = 850;
    int fontSize = 20;
    Text text[20];
    string line[20];
    Font font;
    font.loadFromFile("res/IceCold.ttf");
    int q = 0;
    while (getline(creditsR, line[q])) // Fix: use getline directly instead of checking eof()
    {
        q++;
    }
    // will load sentences from file

    for (int i = 0; i < 20; i++)
    {
        text[i].setCharacterSize(50);
        text[i].setLetterSpacing(3);
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
    int sizeOfLoop=20;// it will increase every time loop iterates because every time more text will be displayed on screen than previous
    while (window.isOpen())
    {
        window.clear();
        for (int i = 0; i < 20; i++) {
            if (text[i].getPosition().y < 900) {
                text[i].setPosition(text[i].getPosition().x + 10, text[i].getPosition().y - 30);
                text[i].setCharacterSize(text[i].getCharacterSize() - 5);
            }
            text[i].setPosition(text[i].getPosition().x, text[i].getPosition().y - 30);
            window.draw(text[i]);
            sleep(milliseconds(30));
        }
          
        exitButton(window, event, mainMenuChoice);
        window.display();
        if (mainMenuChoice == 0) break;
       
    }

    creditsR.close(); // Fix: close the file after reading
}






