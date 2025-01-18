#ifndef W_QUEEN_H
#define W_QUEEN_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "queen.h"
using namespace sf;

class W_Queen : public Queen
{

public:

W_Queen(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	// sprite.setScale(0.75,0.75);
}

~W_Queen()
{

}

};

#endif