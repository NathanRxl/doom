#pragma once

#include <Imagine/Graphics.h>
using namespace Imagine;
#include <cmath>
#define _USE_MATH_DEFINES

//Fen�tre
const int W = 1300;
const int H = 700;
const int W_MINIMAP = 20; //Dimensions de la minimap en %
const int H_MINIMAP = 20;

//Mouvements
const int PAS = 1; //Pas de d�placement
const float THETA = M_PI/10; //Pas de rotation

//Graphismes
const float FOV = 90; //Field of view � 90
const float H_WALLS = 500; //Coefficient de hauteur des murs
const float INFINITE = 9000*42; //IT'S OVER 9000!

const Color FLOOR(100, 100, 100);
const Color SKY(165, 200, 255);
const Color WALL(123, 60, 46);