#ifndef W_ROOK_H
#define W_ROOK_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "rook.h"
using namespace sf;

class W_Rook : public Rook
{

public:

W_Rook(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	// sprite.setScale(0.75,0.75);
}

~W_Rook()
{
	
}

};

#endif