#ifndef B_BISHOP_H
#define B_BISHOP_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "bishop.h"
using namespace sf;

class B_Bishop : public Bishop
{

public:

B_Bishop(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
}

~B_Bishop()
{

}

};

#endif