#ifndef B_KNIGHT_H
#define B_KNIGHT_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "knight.h"
using namespace sf;

class B_Knight : public Knight
{

public:

B_Knight(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
}

~B_Knight()
{
    
}

};

#endif