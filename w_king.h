#ifndef W_KING_H
#define W_KING_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "king.h"
using namespace sf;

class W_King : public King
{

public:

W_King(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	// sprite.setScale(0.75,0.75);
}

~W_King()
{
	
}
};

#endif