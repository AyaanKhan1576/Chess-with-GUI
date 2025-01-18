#ifndef W_KNIGHT_H
#define W_KNIGHT_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "knight.h"
using namespace sf;

class W_Knight : public Knight
{

public:

W_Knight(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
}

W_Knight()
{
    
}

};

#endif