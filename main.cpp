#include<iostream>
#include "game.h"
using namespace std;

int main()
{
    Game g;

    if (g.start_menu() == 1)
        g.start_game();
        
    return 0;
}