#ifndef PIECES_H
#define PIECES_H

#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Pieces
{

public: 

Texture tex;
Sprite sprite;
int selected;
int posX_1;
int posY_1;
int posX_2;
int posY_2;
bool flag_alive;
static int death_y;
bool moved;


Pieces()
{
    sprite.setScale(0.425, 0.425);
    selected = -1;
    posX_1 = -1;
    posY_1 = -1;
    posX_2 = -1;
    posY_2 = -1;
    flag_alive = 1;
    //death_y = 0;
    moved = 0;

}

virtual bool capture_piece(Pieces* black[], int posX_2, int posY_2)
{
    for (int i=0; i<16; i++)
    {
        if (black[i]->sprite.getPosition().x == posX_2 && black[i]->sprite.getPosition().y == posY_2)
        {
            black[i]->sprite.setScale(0.2, 0.2);
            black[i]->flag_alive = 0;
            black[i]->sprite.setPosition(600, death_y);
            death_y += 32;
            return 1;
        }
    }   

    return 0;
}

virtual bool legal_move(int selected_piece, int select_posX, int select_posY, int place_posX, int place_posY)
{
    selected = selected_piece;
    posX_1 = select_posX;
    posY_1 = select_posY;
    posX_2 = place_posX;
    posY_2 = place_posY;

    return 1;
}

virtual bool enemy_collision(int selected_piece, int select_posX, int select_posY, int place_posX, int place_posY, Pieces* black[], Pieces* white[])
{
    return 0;
}

~Pieces()
{
    
}

};

int Pieces::death_y = 0;

#endif