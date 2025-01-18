#ifndef B_KING_H
#define B_KING_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "king.h"
using namespace sf;

class B_King : public King
{

public:

B_King(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	// sprite.setScale(0.75,0.75);
}

~B_King()
{
	
}
};

#endif