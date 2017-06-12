#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Ball
{
private:
    Vector2f position;
 
    // A RectangleShape object called ref
    CircleShape ballShape;
 
    float xVelocity = 0;
    float yVelocity = 0;
    bool in_play=false;
 
public:
    Ball();
 
    FloatRect getPosition();
 
    CircleShape getShape();
 
    float getXVelocity();
 
    void reboundSides();
 
    void reboundBotOrTop();
 
    void hitBottom();
 
    void update();
 
    void changePos(float x,float y);

    void changeVel(float x,float y);

    bool inPlay();

    void nowInPlay();

    void changeColor();
};
