#ifndef PAWN_H
#define PAWN_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "pieces.h"
using namespace sf;

class Pawn : public Pieces
{

public:
static bool diagonal_flag;

Pawn()
{
    //diagonal_flag = 0;
}

virtual bool enemy_collision(int selected_piece, int select_posX, int select_posY, int place_posX, int place_posY, Pieces* black[], Pieces* white[]) override
{
    selected = selected_piece;
    posX_1 = select_posX;
    posY_1 = select_posY;
    posX_2 = place_posX;
    posY_2 = place_posY;

    for (int i=0; i<16; i++)
    {
        if (black[i]->sprite.getPosition().x == posX_1)
        {
            if (black[i]->sprite.getPosition().y == posY_2 && (black[i]->sprite.getPosition().x == posX_2) && (posX_1 == posX_2))
            {
                return 1;
            }
        }

        if ((black[i]->sprite.getPosition().y == posY_2) && (black[i]->sprite.getPosition().x == posX_2) && (posX_2 != posX_1))
        {
            diagonal_flag = 1;
            return 0;
        }
    }
    return 0;
}

~Pawn()
{
    
}
};

bool Pawn::diagonal_flag = 0;

#endif