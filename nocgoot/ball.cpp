//#include "stdafx.h"
#include "ball.h"
#include "stdlib.h" 

using namespace std;
using namespace sf;

Ball::Ball()
{
    ballShape.setRadius(10);
    ballShape.setPosition(position);
    ballShape.setFillColor(Color::Red);
}

void Ball::changePos(float x,float y) {
	position.x=x;
	position.y=y;
}

void Ball::changeVel(float x,float y) {
	xVelocity=x;
	yVelocity=y;
}

FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}
 
CircleShape Ball::getShape()
{
    return ballShape;
}
 
float Ball::getXVelocity()
{
    return xVelocity;
}
 
void Ball::reboundSides()
{
    xVelocity = -xVelocity;
}
 
void Ball::reboundBotOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
}
 
void Ball::hitBottom()
{
    position.y = 1;
    position.x = 500;
}
 
void Ball::update()
{
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;
 
    // Move the ball and the bat
    ballShape.setPosition(position);
}

bool Ball::inPlay()
{
    return in_play;
}

void Ball::nowInPlay()
{
    in_play=true;
}

void Ball::changeColor()
{
    if(ballShape.getFillColor()==Color::Red)
        ballShape.setFillColor(Color::Black);
    else
        ballShape.setFillColor(Color::Red);
}