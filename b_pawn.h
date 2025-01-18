#ifndef B_PAWN_H
#define B_PAWN_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "pawn.h"
using namespace sf;

class B_Pawn : public Pawn
{

public:

int count;

B_Pawn(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
    count = 0;
}

bool legal_move(int selected_piece, int select_posX, int select_posY, int place_posX, int place_posY) override
{
    bool flag = 0;
    selected = selected_piece;
    posX_1 = select_posX;
    posY_1 = select_posY;
    posX_2 = place_posX;
    posY_2 = place_posY;

    if (count == 0)
    {
        if ((posX_2 == posX_1) && (abs(posY_2 - posY_1) <= 128) && (posY_1 < posY_2))
        {
            flag = 1;
            count++;
        }
        if (((posX_2 == posX_1 + 64) || (posX_2 == posX_1 - 64)) && ((posY_2 == posY_1 + 64)) && (diagonal_flag == 1))
        {
            flag = 1;
            count++;
        }
    }

    else
    {
        if ((posX_2 == posX_1) && (abs(posY_2 - posY_1) <= 64) && (posY_1 < posY_2))
            flag = 1;  
        if (((posX_2 == posX_1 + 64) || (posX_2 == posX_1 - 64)) && (posY_2 == posY_1 + 64) && (diagonal_flag == 1))
            flag = 1;
    }
    diagonal_flag = 0;
    return flag;
}

~B_Pawn()
{
    
}
};

#endif