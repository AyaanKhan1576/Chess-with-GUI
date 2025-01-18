#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include "menu.h"
#include "pieces.h"
#include "rook.h"
#include "w_rook.h"
#include "b_rook.h"
#include "king.h"
#include "w_king.h"
#include "b_king.h"
#include "queen.h"
#include "w_queen.h"
#include "b_queen.h"
#include "bishop.h"
#include "w_bishop.h"
#include "b_bishop.h"
#include "knight.h"
#include "w_knight.h"
#include "b_knight.h"
#include "pawn.h"
#include "w_pawn.h"
#include "b_pawn.h"
using namespace sf;
using namespace std;

const char title[] = "Chess Game";
const int B_WIDTH = 8;
const int B_HEIGHT = 8;
const int B_SIZE = 64;
const int HEIGHT_PIXELS = 512;
const int SIZE_PIXELS = 512/8;

class Game
{

private:
RectangleShape b_squares[B_HEIGHT][B_WIDTH];
Color col1 = Color::White;
Color col2 = Color::Black;
Sprite background; //Game background sprite
Texture bg_texture;

bool selected;
bool turn;
int selected_piece;
int place_posX;
int place_posY;
int select_posX;
int select_posY;
bool check_white;
bool check_black;
bool final_check;

Menu* m;
Pieces *w_rook[2];
Pieces *b_rook[2];
Pieces *w_king;
Pieces *b_king;
Pieces *w_queen;
Pieces *b_queen;
Pieces *w_bishop[2];
Pieces *b_bishop[2];
Pieces *w_knight[2];
Pieces *b_knight[2];
Pieces *w_pawn[8];
Pieces *b_pawn[8];
Pieces *white_piece[16];
Pieces *black_piece[16];

public:

// MAIN CONSTRUCTOR
Game()
{
    bg_texture.loadFromFile("img/background.jpg");
    background.setTexture(bg_texture);
    background.setScale(1, 1);

    selected = 0;
    selected_piece = -1;
    place_posX = -1;
    place_posY = -1;
    select_posX = -1;
    select_posY = -1;
    turn = 0;
    check_white = 0;
    check_black = 0;
    final_check = 1;

    m = new Menu;

    w_king = new W_King("img/w_king.png");
    b_king = new B_King("img/b_king.png");

    w_queen = new W_Queen("img/w_queen.png");
    b_queen = new B_Queen("img/b_queen.png");

    for (int i=0; i<2; i++)
    {
        w_rook[i] = new W_Rook("img/w_rook.png");
        b_rook[i] = new B_Rook("img/b_rook.png");

        w_bishop[i] = new W_Bishop("img/w_bishop.png");
        b_bishop[i] = new B_Bishop("img/b_bishop.png");

        w_knight[i] = new W_Knight("img/w_knight.png");
        b_knight[i] = new B_Knight("img/b_knight.png");

    }

    for (int i=0; i<8; i++)
    {
        w_pawn[i] = new W_Pawn("img/w_pawn.png");
        b_pawn[i] = new B_Pawn("img/b_pawn.png");
        white_piece[i+8] = w_pawn[i];
        black_piece[i+8] = b_pawn[i];
    }

    white_piece[0] = w_rook[0];
    white_piece[1] = w_knight[0];
    white_piece[2] = w_bishop[0];
    white_piece[3] = w_queen;
    white_piece[4] = w_king;
    white_piece[5] = w_bishop[1];
    white_piece[6] = w_knight[1];
    white_piece[7] = w_rook[1];

    black_piece[0] = b_rook[0];
    black_piece[1] = b_knight[0];
    black_piece[2] = b_bishop[0];
    black_piece[3] = b_queen;
    black_piece[4] = b_king;
    black_piece[5] = b_bishop[1];
    black_piece[6] = b_knight[1];
    black_piece[7] = b_rook[1];
   
}

// DRAWING BOARD HERE//
void draw_board(RenderTarget& window)
{
    for (int i=0; i<B_HEIGHT; i++)
    {
        bool color_flag = 0;

        if (i % 2 == 0)
            color_flag = 1;
        
        for (int j=0; j<B_WIDTH; j++)
        {
           // b_squares[i][j].setScale(, 5);
            b_squares[i][j].setPosition(Vector2f(j*64, i*64));
            b_squares[i][j].setSize(sf::Vector2f(64, 64));
            
            if (!color_flag)
                b_squares[i][j].setFillColor(col2);
            else if(color_flag)
                b_squares[i][j].setFillColor(col1);

            color_flag = !color_flag;
        }
    }
}

// START
bool start_menu()
{
   return m->display_menu();
}

// SET POSITIONS OF PIECES
void set_positions()
{
    float coord_x[8];
    float coord_y[8];

    for (int i=0; i<8; i++)
    {
        coord_x[i] = b_squares[0][i].getPosition().x + 4; 
        coord_y[i] = b_squares[i][0].getPosition().y + 4; 
    }

    w_rook[0]->sprite.setPosition(coord_x[0], coord_y[7]);
    w_rook[1]->sprite.setPosition(coord_x[7], coord_y[7]);
    b_rook[0]->sprite.setPosition(coord_x[0], coord_y[0]);
    b_rook[1]->sprite.setPosition(coord_x[7], coord_y[0]);

    w_king->sprite.setPosition(coord_x[4], coord_y[7]);
    b_king->sprite.setPosition(coord_x[4], coord_y[0]);

    w_queen->sprite.setPosition(coord_x[3], coord_y[7]);
    b_queen->sprite.setPosition(coord_x[3], coord_y[0]);

    w_bishop[0]->sprite.setPosition(coord_x[2], coord_y[7]);
    w_bishop[1]->sprite.setPosition(coord_x[5], coord_y[7]);
    b_bishop[0]->sprite.setPosition(coord_x[2], coord_y[0]);
    b_bishop[1]->sprite.setPosition(coord_x[5], coord_y[0]);

    w_knight[0]->sprite.setPosition(coord_x[1], coord_y[7]);
    w_knight[1]->sprite.setPosition(coord_x[6], coord_y[7]);
    b_knight[0]->sprite.setPosition(coord_x[1], coord_y[0]);
    b_knight[1]->sprite.setPosition(coord_x[6], coord_y[0]);

    for (int i=0; i<8; i++)
    {
        w_pawn[i]->sprite.setPosition(coord_x[i], coord_y[6]);
        b_pawn[i]->sprite.setPosition(coord_x[i], coord_y[1]);
    }
}

// CHECK COLLISION
bool collision()
{
    int enemy_collision = 0;
    for (int i=0; i<16; i++)
    {
        if (!turn) //WHITE TURN
        {
            if (white_piece[i]->sprite.getPosition().x == place_posX && white_piece[i]->sprite.getPosition().y == place_posY)
                return 1; //COLLISION WITH SAME PIECE

            // if (white_piece[i]->enemy_collision(selected_piece, select_posX, select_posY, place_posX, place_posY, black_piece, white_piece) == 1)
            if (white_piece[selected_piece]->enemy_collision(selected_piece, select_posX, select_posY, place_posX, place_posY, black_piece, white_piece) == true)
            {  

                    return 1; //CHECK TO NOT SKIP OVER A PIECE
            }
        }

        else //BLACK TURN
        {
            if (black_piece[i]->sprite.getPosition().x == place_posX && black_piece[i]->sprite.getPosition().y == place_posY)
                return 1;

            if (white_piece[selected_piece]->enemy_collision(selected_piece, select_posX, select_posY, place_posX, place_posY, white_piece, black_piece) == 1)
            {   
                return 1;
            }
        }
    }

    return 0;
}

// bool find_check()
// {
//     for (int i=0; i<16; i++)
//     {
        
//         if (i == 4)
//             continue;

//         if (!turn)
//         {
//             if (!white_piece[i]->enemy_collision(selected_piece, white_piece[i]->sprite.getPosition().x, white_piece[i]->sprite.getPosition().y, b_king->sprite.getPosition().x, b_king->sprite.getPosition().y, black_piece, white_piece) 
//             &&  (white_piece[i]->legal_move(selected_piece, white_piece[i]->sprite.getPosition().x, white_piece[i]->sprite.getPosition().y, b_king->sprite.getPosition().x, b_king->sprite.getPosition().y)))
//             {
//                 cout<<"black check";
//                 check_black = 1;
//                 return check_black; 
//             }

//             if (!black_piece[i]->enemy_collision(selected_piece, black_piece[i]->sprite.getPosition().x, black_piece[i]->sprite.getPosition().y, w_king->sprite.getPosition().x, w_king->sprite.getPosition().y, white_piece, black_piece)
//             &&  (black_piece[i]->legal_move(selected_piece, black_piece[i]->sprite.getPosition().x, black_piece[i]->sprite.getPosition().y, w_king->sprite.getPosition().x, w_king->sprite.getPosition().y)))
//             {  
//                 cout<<"white check";
//                 check_white = 1;
//                 return check_white;
//             }
//         }

//         else
//         {
//             if (!black_piece[i]->enemy_collision(selected_piece, black_piece[i]->sprite.getPosition().x, black_piece[i]->sprite.getPosition().y, w_king->sprite.getPosition().x, w_king->sprite.getPosition().y, white_piece, black_piece)
//             &&  (black_piece[i]->legal_move(selected_piece, black_piece[i]->sprite.getPosition().x, black_piece[i]->sprite.getPosition().y, w_king->sprite.getPosition().x, w_king->sprite.getPosition().y)))
//             {  
//                 cout<<"white check";
//                 check_white = 1;
//                 return check_white;
//             }

//             if (!white_piece[i]->enemy_collision(selected_piece, white_piece[i]->sprite.getPosition().x, white_piece[i]->sprite.getPosition().y, b_king->sprite.getPosition().x, b_king->sprite.getPosition().y, black_piece, white_piece) 
//             &&  (white_piece[i]->legal_move(selected_piece, white_piece[i]->sprite.getPosition().x, white_piece[i]->sprite.getPosition().y, b_king->sprite.getPosition().x, b_king->sprite.getPosition().y)))
//             {
//                 cout<<"black check";
//                 check_black = 1;
//                 return check_black;
//             }
//         }
//     }
//     check_white = 0;
//     check_black = 0;
//     return 0;
// }


bool find_check()
{
    check_white = 0;
    check_black = 0;

    for (int i=0; i<16; i++)
    {
        if (i == 4)
            continue;

        if (white_piece[i]->flag_alive == 0)
            continue;
        
        if (black_piece[i]->flag_alive == 0)
            continue;

        if (!white_piece[i]->enemy_collision(selected_piece, white_piece[i]->sprite.getPosition().x, white_piece[i]->sprite.getPosition().y, b_king->sprite.getPosition().x, b_king->sprite.getPosition().y, black_piece, white_piece) 
        &&  (white_piece[i]->legal_move(selected_piece, white_piece[i]->sprite.getPosition().x, white_piece[i]->sprite.getPosition().y, b_king->sprite.getPosition().x, b_king->sprite.getPosition().y)))
        {
            cout<<"black check";
            check_black = 1;
            check_white = 0;
            return check_black; 
        }

        if (!black_piece[i]->enemy_collision(selected_piece, black_piece[i]->sprite.getPosition().x, black_piece[i]->sprite.getPosition().y, w_king->sprite.getPosition().x, w_king->sprite.getPosition().y, white_piece, black_piece)
        &&  (black_piece[i]->legal_move(selected_piece, black_piece[i]->sprite.getPosition().x, black_piece[i]->sprite.getPosition().y, w_king->sprite.getPosition().x, w_king->sprite.getPosition().y)))
        {  
            cout<<"white check";
            check_white = 1;
            check_black = 0;
            return check_white;
        }
    }

    return 0;
}

// bool find_check()
// {
//     check_white = 0;
//     check_black = 0;

//     for (int i=0; i<16; i++)
//     {
//         if (i == 4)
//             continue;

//         if (white_piece[i]->legal_move(selected_piece, white_piece[i]->sprite.getPosition().x, white_piece[i]->sprite.getPosition().y, b_king->sprite.getPosition().x, b_king->sprite.getPosition().y))
//         {  
//             if (!white_piece[i]->enemy_collision(selected_piece, white_piece[i]->sprite.getPosition().x, white_piece[i]->sprite.getPosition().y, b_king->sprite.getPosition().x, b_king->sprite.getPosition().y, black_piece, white_piece))
//             {
//                 cout<<"black check";
//                 check_black = 1;
//                 check_white = 0;
//                 return check_black; 
//             }
//         }
//         if (black_piece[i]->legal_move(selected_piece, black_piece[i]->sprite.getPosition().x, black_piece[i]->sprite.getPosition().y, w_king->sprite.getPosition().x, w_king->sprite.getPosition().y))
//         {
//             if (!black_piece[i]->enemy_collision(selected_piece, black_piece[i]->sprite.getPosition().x, black_piece[i]->sprite.getPosition().y, w_king->sprite.getPosition().x, w_king->sprite.getPosition().y, white_piece, black_piece))
//             {  
//                 cout<<"white check";
//                 check_white = 1;
//                 check_black = 0;
//                 return check_white;
//             }
//         }
//     }

//     return 0;
// }

bool check_mate()
{
    final_check = 1;

    for (int i=0; i<16; i++)
    {
        if (white_piece[i]->flag_alive == 0)
            continue;
        
        if (black_piece[i]->flag_alive == 0)
            continue;
        
        for (int y=0; y<8; y++)
        {

            for (int x=0; x<8; x++)
            {

                if (!turn)
                {
                    int orig_posX = white_piece[i]->sprite.getPosition().x; 
                    int orig_posY = white_piece[i]->sprite.getPosition().y;

                    if (!white_piece[i]->enemy_collision(selected_piece, orig_posX, orig_posY, 64*x + 4, 64*y + 4, black_piece, white_piece) 
                    &&  (white_piece[i]->legal_move(selected_piece, orig_posX, orig_posY, 64*x + 4, 64*y + 4)))
                    {
                        white_piece[i]->sprite.setPosition(64*x + 4, 64*y + 4);
                        find_check();
                        if (check_white)
                        {
                            white_piece[i]->sprite.setPosition(orig_posX, orig_posY);
                        }

                        else
                        {
                            white_piece[i]->sprite.setPosition(orig_posX, orig_posY);
                            final_check = 0;
                            cout<<final_check;
                            return final_check;
                        }
                    }
                }

                else if (turn)
                {
                    int orig_posX = black_piece[i]->sprite.getPosition().x; 
                    int orig_posY = black_piece[i]->sprite.getPosition().y;

                    if (!black_piece[i]->enemy_collision(selected_piece, orig_posX, orig_posY, 64*x + 4, 64*y + 4, white_piece, black_piece) 
                    &&  (black_piece[i]->legal_move(selected_piece, orig_posX, orig_posY, 64*x + 4, 64*y + 4)))
                    {
                        black_piece[i]->sprite.setPosition(64*x + 4, 64*y + 4);
                        find_check();
                        if (check_black)
                        {
                            black_piece[i]->sprite.setPosition(orig_posX, orig_posY);
                        }

                        else
                        {
                            black_piece[i]->sprite.setPosition(orig_posX, orig_posY);
                            final_check = 0;
                            return final_check;
                        }
                    }
                }
                
            }
        }
    }
    cout<<final_check;
    return final_check;
}

// bool check_mate()
// {
//     final_check = 1;

//     for (int i=0; i<16; i++)
//     {
//         for (int y=0; y<8; y++)
//         {

//             for (int x=0; x<8; x++)
//             {

//                 if (!turn)
//                 {
//                     int orig_posX = white_piece[i]->sprite.getPosition().x; 
//                     int orig_posY = white_piece[i]->sprite.getPosition().y;

//                     if (white_piece[i]->legal_move(selected_piece, orig_posX, orig_posY, 64*x + 4, 64*y + 4))
//                     {
//                         if (!white_piece[i]->enemy_collision(selected_piece, orig_posX, orig_posY, 64*x + 4, 64*y + 4, black_piece, white_piece))
//                         {
//                             white_piece[i]->sprite.setPosition(64*x + 4, 64*y + 4);
//                             find_check();
//                             if (check_white)
//                             {
//                                 white_piece[i]->sprite.setPosition(orig_posX, orig_posY);
//                                 cout<<" HELLO ";
//                             }

//                             else
//                             {
//                                 white_piece[i]->sprite.setPosition(orig_posX, orig_posY);
//                                 final_check = 0;
//                                 cout<<final_check;
//                                 return final_check;
//                             }
//                         }
//                     }
//                 }

//                 else if (turn)
//                 {
//                     int orig_posX = black_piece[i]->sprite.getPosition().x; 
//                     int orig_posY = black_piece[i]->sprite.getPosition().y;

//                     if (black_piece[i]->legal_move(selected_piece, orig_posX, orig_posY, 64*x + 4, 64*y + 4))
//                     {
//                         if (!black_piece[i]->enemy_collision(selected_piece, orig_posX, orig_posY, 64*x + 4, 64*y + 4, white_piece, black_piece))
//                         {
//                             black_piece[i]->sprite.setPosition(64*x + 4, 64*y + 4);
//                             find_check();
//                             if (check_black)
//                             {
//                                 black_piece[i]->sprite.setPosition(orig_posX, orig_posY);
//                             }

//                             else
//                             {
//                                 black_piece[i]->sprite.setPosition(orig_posX, orig_posY);
//                                 final_check = 0;
//                                 return final_check;
//                             }
//                         }
//                     }
//                 }
                
//             }
//         }
//     }
//     cout<<final_check;
//     return final_check;
// }

// bool check_mate()
// {
//     final_check = true;

//     for (int i = 0; i < 16; i++)
//     {
//         if (i == 4)
//             continue;

//         Pieces *piece = !turn ? white_piece[i] : black_piece[i];
//         int orig_posX = piece->sprite.getPosition().x;
//         int orig_posY = piece->sprite.getPosition().y;

//         for (int y = 0; y < 8; y++)
//         {
//             for (int x = 0; x < 8; x++)
//             {
//                 if (piece->legal_move(selected_piece, orig_posX, orig_posY, 64 * x + 4, 64 * y + 4))
//                 {
//                     if (!piece->enemy_collision(selected_piece, orig_posX, orig_posY, 64 * x + 4, 64 * y + 4, !turn ? black_piece : white_piece, !turn ? white_piece : black_piece))
//                     {
//                         // Simulate the move
//                         piece->sprite.setPosition(64 * x + 4, 64 * y + 4);
//                         find_check();

//                         if (!turn && check_white)
//                         {
//                             piece->sprite.setPosition(orig_posX, orig_posY);
//                         }
//                         else if (turn && check_black)
//                         {
//                             piece->sprite.setPosition(orig_posX, orig_posY);
//                         }
//                         else
//                         {
//                             piece->sprite.setPosition(orig_posX, orig_posY);
//                             final_check = false;
//                             cout << final_check;
//                             return final_check;
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     cout << final_check;
//     return final_check;
// }

// void short_castle()
// {
//     if (!turn)
//     {
//         w_king->sprite.setPosition(select_posX + 64*2, select_posY);
//         w_rook[1]->sprite.setPosition(select_posX + 62, select_posY);
//     }

//     else
//     {
//         b_king->sprite.setPosition(select_posX + 64*2, select_posY);
//         b_rook[1]->sprite.setPosition(select_posX + 62, select_posY);
//     }
// }

// CHECK VALID MOVES
bool valid_move()
{
    if (collision())
    {
        return 0;
    }

    
    if (!turn) // WHITE TURN
    {

        // if (select_posX == w_king->sprite.getPosition().x && select_posY == w_king->sprite.getPosition().y && place_posX == (w_rook[1]->sprite.getPosition().x - 64) && place_posY == w_rook[1]->sprite.getPosition().y && w_king->moved == 0 && w_rook[1] == 0)
        // {
        //     short_castle();
        //     w_rook[1]->moved = 1;
        //     w_king->moved = 1;
        //     return 1;
        // }

        if (!white_piece[selected_piece]->legal_move(selected_piece, select_posX, select_posY, place_posX, place_posY))
            return 0;
    }

    else // BLACK TURN
    {

        // if (select_posX == b_king->sprite.getPosition().x && select_posY == b_king->sprite.getPosition().y && place_posX == (b_rook[1]->sprite.getPosition().x - 64) && place_posY == b_rook[1]->sprite.getPosition().y && b_king->moved == 0 && b_rook[1] == 0)
        // {
        //     short_castle();
        //     b_rook[1]->moved = 1;
        //     b_king->moved = 1;
        //     return 1;
        // }

        if (!black_piece[selected_piece]->legal_move(selected_piece, select_posX, select_posY, place_posX, place_posY))
            return 0;

    }

    return 1;
}

// SELECT PIECE
void select_piece(int posX, int posY, RenderWindow& window)
{
    select_posX = -1;
    select_posY = -1;

    for (int i=0; i<8; i++)
    {
        if (posY >= i*64 && posY < (i+1)*64)
            select_posY = b_squares[i][0].getPosition().y + 4;

        if (posX >= i*64 && posX < (i+1)*64)
            select_posX = b_squares[0][i].getPosition().x + 4;
    }

    if (!turn)
    {
        for (int i=0; i<16; i++)
        {
            if (white_piece[i]->sprite.getPosition().x == select_posX && white_piece[i]->sprite.getPosition().y == select_posY)
            {
                selected_piece = i;
                selected = 1;
                break;
            }
        }
    } 

    else
    {
        for (int i=0; i<16; i++)
        {
            if (black_piece[i]->sprite.getPosition().x == select_posX && black_piece[i]->sprite.getPosition().y == select_posY)
            {
                selected_piece = i;
                selected = 1;
                break;
            }
        }
    }
}


// MOVE PIECE
void move_piece(int posX, int posY, RenderWindow& window)
{
    int track = -1;
    bool capture = 0;

    for (int i=0; i<8; i++)
    {
        if (posY >= i*64 && posY < (i+1)*64)
            place_posY = b_squares[i][0].getPosition().y + 4;

        if (posX >= i*64 && posX < (i+1)*64)
            place_posX = b_squares[0][i].getPosition().x + 4;
        
    }

    if (valid_move())
    {
        if (!turn)
        {
            white_piece[selected_piece]->sprite.setPosition(place_posX, place_posY);

            for (int i=0; i<16; i++)
            {
                if (black_piece[i]->sprite.getPosition().x == place_posX && black_piece[i]->sprite.getPosition().y == place_posY)
                    track = i;
            }

            if (white_piece[selected_piece]->capture_piece(black_piece, place_posX, place_posY))
                capture = 1;

            find_check();
            if (check_white)
            {
                white_piece[selected_piece]->sprite.setPosition(select_posX, select_posY);
                if (capture == 1)
                {
                    black_piece[track]->sprite.setPosition(place_posX, place_posY);
                    black_piece[track]->sprite.setScale(0.425, 0.425);
                    black_piece[track]->flag_alive = 1;
                }
                check_mate();
                if (final_check)
                {
                    cout<<"Checkmate";
                    window.close();
                    m->gameover();
                }

                return;
            }

            // if (white_piece[selected_piece]->sprite.getPosition().x == place_posX && white_piece[selected_piece]->sprite.getPosition().y == place_posY)
            //     white_piece[selected_piece]->capture_piece(black_piece, place_posX, place_posY);    // CHECK AND UPDATE IF CAPTURED
            
        }
        else
        {
            black_piece[selected_piece]->sprite.setPosition(place_posX, place_posY); 

            for (int i=0; i<16; i++)
            {
                if (white_piece[i]->sprite.getPosition().x == place_posX && white_piece[i]->sprite.getPosition().y == place_posY)
                    track = i;
            }

            if (black_piece[selected_piece]->capture_piece(white_piece, place_posX, place_posY))
                capture = 1;

            find_check(); 
            if (check_black)
            {
                black_piece[selected_piece]->sprite.setPosition(select_posX, select_posY);
                if (capture == 1)
                {
                    white_piece[track]->sprite.setPosition(place_posX, place_posY);
                    white_piece[track]->sprite.setScale(0.425, 0.425);
                    white_piece[track]->flag_alive = 1;
                }
                check_mate();
                if (final_check)
                {
                    cout<<"Checkmate";
                    window.close();
                    m->gameover();
                }
                
                return;    
            }

            // if (black_piece[selected_piece]->sprite.getPosition().x == place_posX && black_piece[selected_piece]->sprite.getPosition().y == place_posY)
            //     black_piece[selected_piece]->capture_piece(white_piece, place_posX, place_posY);
              
        }

        
        turn = !turn;
    }
    
    selected = 0;
}

/////////////////////// GAME FUNCTION ////////////////////////////////////////////////
void start_game()
{
    srand(time(0));
    RenderWindow window(VideoMode(768, 512), title);
    Clock clock;
    float timer=0;
    

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time; 
    
//////////////////////////////// START EVENT ////////////////////////////////////////
        Event e;
            while (window.pollEvent(e))
            {  
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game  

                if(e.type == sf::Event::MouseButtonPressed)
                {
                    if(e.mouseButton.button == sf::Mouse::Left)
                    {       
                        int click_posX = e.mouseButton.x;
                        int click_posY = e.mouseButton.y;

                        if (!selected)                            
                            select_piece(click_posX, click_posY, window);

                        else
                            move_piece(click_posX, click_posY, window);
                    }
                }               	    
            }

////////////////////// CALL FUNCTIONS ////////////////////////////////////////////////
        draw_board(window);
        static bool start1 = 1;
        if (start1 == 1)
        {
            set_positions();
            start1 = 0;
        }

        // if (check_black || check_white)
        // {
        //     check_mate();
        //     if (final_check)
        //     {
        //         cout<<"Checkmate";
        //         //window.close();
        //         m->gameover();
        //     }
        // }



////////////////////// DRAW EVERYTHING ///////////////////////////////////////////////
        window.clear(Color::Black); //clears the screen
        window.draw(background);  // setting background

        for (int i=0; i<B_HEIGHT; i++)
        {
            for (int j=0; j<B_WIDTH; j++)
                window.draw(b_squares[i][j]);
        }

        window.draw(w_rook[0]->sprite);
        window.draw(w_rook[1]->sprite);
        window.draw(b_rook[0]->sprite);
        window.draw(b_rook[1]->sprite);

        window.draw(w_king->sprite);
        window.draw(b_king->sprite);

        window.draw(w_queen->sprite);
        window.draw(b_queen->sprite);

        window.draw(w_bishop[0]->sprite);
        window.draw(w_bishop[1]->sprite);
        window.draw(b_bishop[0]->sprite);
        window.draw(b_bishop[1]->sprite);

        window.draw(w_knight[0]->sprite);
        window.draw(w_knight[1]->sprite);
        window.draw(b_knight[0]->sprite);
        window.draw(b_knight[1]->sprite);

        for (int i=0; i<8; i++)
        {
            window.draw(w_pawn[i]->sprite);
            window.draw(b_pawn[i]->sprite);
        }

        window.display();  //Displying all the sprites
    }
}

~Game()
{
    delete m;
    delete b_king;
    delete w_king;
    delete b_queen;
    delete w_queen;

    for (int i=0; i<2; i++)
    {
        delete w_rook[i];
        delete b_rook[i];
        delete w_bishop[i];
        delete b_bishop[i];
        delete w_knight[i];
        delete b_knight[i];
    }

    for (int i=0; i<8; i++)
    {
        delete w_pawn[i];
        delete b_pawn[i];
    }

    for (int i=0; i<16; i++)
    {
        delete white_piece[i];
        delete black_piece[i];
    }
}
};