#ifndef KING_H
#define KING_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "pieces.h"
using namespace sf;

class King : public Pieces
{

public:

King()
{

}

bool legal_move(int selected_piece, int select_posX, int select_posY, int place_posX, int place_posY) override
{
    bool count = 0;
    selected = selected_piece;
    posX_1 = select_posX;
    posY_1 = select_posY;
    posX_2 = place_posX;
    posY_2 = place_posY;

    if ((abs(posX_2 - posX_1) <= 64) && (abs(posY_2 - posY_1) <= 64))
    {
        count = 1;
        moved = 1;
    }

    return count;
}

~King()
{
    
}
};

#endif