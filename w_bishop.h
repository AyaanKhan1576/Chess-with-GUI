#ifndef W_BISHOP_H
#define W_BISHOP_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "bishop.h"
using namespace sf;

class W_Bishop : public Bishop
{

public:

W_Bishop(std::string png_path) 
{
    tex.loadFromFile(png_path);
	sprite.setTexture(tex);
}

~W_Bishop()
{

}

};

#endif