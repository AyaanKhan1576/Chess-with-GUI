#ifndef B_QUEEN_H
#define B_QUEEN_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "queen.h"
using namespace sf;

class B_Queen : public Queen
{

public:

B_Queen(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	// sprite.setScale(0.75,0.75);
}

~B_Queen()
{
	
}

};

#endif