#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include<fstream>
using namespace sf;
const char title2[] = "Menu Screen";

class Menu
{

public:

Sprite background; //Game background sprite
Texture bg_texture;

Menu()
{
    bg_texture.loadFromFile("img/background.jpg");
    background.setTexture(bg_texture);
    background.setScale(2.15, 1.5);
}

bool display_menu()

{
    int help = 0;

    Font font;
    font.loadFromFile("font2.ttf");

    Text text;												//Text to be used in menu window
    text.setFont(font);
    text.setCharacterSize(30);
    text.setString("Chess\nNew Game: Press Enter\nQuit: Press Escape\nHelp: Press H\n");
    text.setPosition(10.f, 10.f);
    
    Text text2;												//Text to be used in menu window
    text2.setFont(font);
    text2.setCharacterSize(30);
    text2.setString("Chess Game. Checkmate opponent");
    text2.setPosition(10.f, 10.f);


    srand(time(0));

    RenderWindow window(VideoMode(780, 780), title2);								
    	while (window.isOpen())
        {
           	Event e;
           	while (window.pollEvent(e))
           	{ 
           		if (e.type == Event::Closed)                  
               		window.close();  
               				
               	else if (e.key.code == Keyboard::Escape)
               		window.close(); 
               		
               	else if (e.key.code == Keyboard::H)
               	{
                    help = 1;
               	}

                else if (e.key.code == Keyboard::G)
                    help = 0;

          		else if (e.key.code == Keyboard::Enter)
          		{
                    return 1;
    				window.close();
                }
            }

            window.clear();
            window.draw(background);

            if (help == 0)  // Draw the menu only if help is not being displayed
            {
                window.draw(text);
            }
            else if (help == 1)
            {
                window.draw(text2);
            }

            window.display();
        }
    return 0;
}

void gameover()
{
    Font font;
    font.loadFromFile("font2.ttf");
    Text text;											
    text.setFont(font);
    text.setCharacterSize(50);
    text.setString("Game Over");
    text.setPosition(10.f, 10.f);

    srand(time(0));

    Text nameText;
    nameText.setFont(font);
    nameText.setCharacterSize(50);
    nameText.setFillColor(Color::White);
    nameText.setPosition(10.f, 170.f);

    RenderWindow window2(VideoMode(780, 780), "Checkmate");
    while (window2.isOpen())
    {
        Event e;
        while (window2.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window2.close();
            else if (e.key.code == Keyboard::Escape)
                window2.close();
            else if (e.key.code == Keyboard::Num1)
            {
                window2.close();
                display_menu();
            }
        }
        window2.clear();
        window2.draw(background);
        window2.draw(text);
        window2.display();
    } 
}
};