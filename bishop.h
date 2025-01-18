#ifndef BISHOP_H
#define BISHOP_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "pieces.h"
using namespace sf;

class Bishop : public Pieces
{

public:

Bishop()
{

}

// bool enemy_collision(int selected_piece, int select_posX, int select_posY, int place_posX, int place_posY, Pieces* white[], Pieces* black[]) override
// {
//     selected = selected_piece;
//     posX_1 = select_posX;
//     posY_1 = select_posY;
//     posX_2 = place_posX;
//     posY_2 = place_posY;

//     // Check if the bishop is moving diagonally
//     int deltaX = abs(posX_2 - posX_1);
//     int deltaY = abs(posY_2 - posY_1);

//     if (deltaX == deltaY)
//     {
//         int stepX = (posX_2 > posX_1) ? 64 : -64;
//         int stepY = (posY_2 > posY_1) ? 64 : -64;
//         int x = posX_1 + stepX;
//         int y = posY_1 + stepY;

//         while (x != posX_2 && y != posY_2)
//         {
//             for (int i = 0; i < 16; i++)
//             {
//                 if (black[i]->sprite.getPosition().x == x && black[i]->sprite.getPosition().y == y)
//                 {
//                     if (x == posX_2 && y == posY_2)
//                     {
//                         // capture_piece(black, i);
//                         return 0;
//                     }    
//                     else
//                         return 1;
//                 }

//                 if (i == selected)
//                     continue;

//                 if (white[i]->sprite.getPosition().x == x && white[i]->sprite.getPosition().y == y)
//                 {
//                     return 1; 
//                 }
//             }

//             x += stepX;
//             y += stepY;
//         }
//     }

//     return 0; // No piece on the path
// }

bool enemy_collision(int selected_piece, int select_posX, int select_posY, int place_posX, int place_posY, Pieces* black[], Pieces* white[]) override
{
    selected = selected_piece;
    posX_1 = select_posX;
    posY_1 = select_posY;
    posX_2 = place_posX;
    posY_2 = place_posY;

    int count = 0;

    // Check if the rook is moving horizontally
    if (posY_1 == posY_2)
    {   
        int stepX = (posX_2 > posX_1) ? 64 : -64;
        int stepY = (posY_2 > posY_1) ? 64 : -64;

        if (posX_2 > posX_1)
        {
            for (int i = posX_1 + stepX; i <= posX_2; i += stepX)
            {
                for (int j = 0; j < 16; j++)
                {
                    if (black[j]->sprite.getPosition().x == i && black[j]->sprite.getPosition().y == posY_1)
                    {
                        if (i == posX_2)
                        {
                            return false;
                        }
                        else
                            return 1;
                    }

                    if (j == selected)
                        continue;
                        
                    if (white[j]->sprite.getPosition().x == i && white[j]->sprite.getPosition().y == posY_1)
                    {
                        return 1;
                    }
                }
            }
        }

        else
        {
            for (int i = posX_1 + stepX; i >= posX_2; i += stepX)
            {
                for (int j = 0; j < 16; j++)
                {
                    if (black[j]->sprite.getPosition().x == i && black[j]->sprite.getPosition().y == posY_1)
                    {
                        if (i != posX_2)
                        {
                            return 1;
                        }
                        else
                            return 0;
                    }

                    if (j == selected)
                        continue;
                        
                    if (white[j]->sprite.getPosition().x == i && white[j]->sprite.getPosition().y == posY_1)
                    {
                        return 1;
                    }
                }
            }
        }

    }
    // Check if the rook is moving vertically
    else if (posX_1 == posX_2)
    {
        int stepX = (posX_2 > posX_1) ? 64 : -64;
        int stepY = (posY_2 > posY_1) ? 64 : -64;
        
        if (posY_2 > posY_1)
        {
            for (int i = posY_1 + stepY; i <= posY_2; i += stepY)
            {
                for (int j = 0; j < 16; j++)
                {
                    if (black[j]->sprite.getPosition().x == posX_1 && black[j]->sprite.getPosition().y == i)
                    {
                        if (i == posY_2)
                        {
                            return false;
                        }

                        else
                            return 1;
                    }

                    if (j == selected)
                        continue;
        
                    if (white[j]->sprite.getPosition().x == posX_1 && white[j]->sprite.getPosition().y == i)
                    {
                        return 1;
                    }
                }
            }
        }

        else
        {
            for (int i = posY_1 + stepY; i >= posY_2; i += stepY)
            {
                for (int j = 0; j < 16; j++)
                {
                    if (black[j]->sprite.getPosition().x == posX_1 && black[j]->sprite.getPosition().y == i)
                    {
                        if (i != posY_2)
                        {
                            return 1;
                        }

                        else
                            return 0;
                    }

                    if (j == selected)
                        continue;
        
                    if (white[j]->sprite.getPosition().x == posX_1 && white[j]->sprite.getPosition().y == i)
                    {
                        return 1;
                    }
                }
            }
        }

    }
    
    // Check if the bishop is moving diagonally
    int deltaX = abs(posX_2 - posX_1);
    int deltaY = abs(posY_2 - posY_1);

    if (deltaX == deltaY)
    {
        int stepX = (posX_2 > posX_1) ? 64 : -64;
        int stepY = (posY_2 > posY_1) ? 64 : -64;
        int x = posX_1 + stepX;
        int y = posY_1 + stepY;

        while (x != posX_2 && y != posY_2)
        {
            for (int i = 0; i < 16; i++)
            {
                if (black[i]->sprite.getPosition().x == x && black[i]->sprite.getPosition().y == y)
                {
                    if (x == posX_2 && y == posY_2)
                    {
                        // capture_piece(black, i);
                        return 0;
                    }    
                    else
                        return 1;
                }

                if (i == selected)
                    continue;

                if (white[i]->sprite.getPosition().x == x && white[i]->sprite.getPosition().y == y)
                {
                    return 1; 
                }
            }

            x += stepX;
            y += stepY;
        }
    }

    return 0; // No piece on the path
}

bool legal_move(int selected_piece, int select_posX, int select_posY, int place_posX, int place_posY) override
{
    bool count = 0;
    selected = selected_piece;
    posX_1 = select_posX;
    posY_1 = select_posY;
    posX_2 = place_posX;
    posY_2 = place_posY;

    for (int i=0; i<8; i++)
    {
        if (((posX_2 == posX_1 + 64*i) || (posX_2 == posX_1 - 64*i)) && ((posY_2 == posY_1 + 64*i) || (posY_2 == posY_1 - 64*i)))
            count = 1;
    }

    return count;
}

~Bishop()
{
    
}
};

#endif