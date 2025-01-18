#ifndef B_ROOK_H
#define B_ROOK_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "rook.h"
using namespace sf;

class B_Rook : public Rook
{

public:

B_Rook(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	// sprite.setScale(0.75,0.75);
}

~B_Rook()
{
	
}

};

#endif