#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
 
class Player
{
private:
    Vector2f position;
    // A RectangleShape object
    RectangleShape playerShape;
 
    float playerSpeed = 1.2f;
 
public:
    Player(float startX, float startY);
 
    FloatRect getPosition();
 
    RectangleShape getShape();
 
    float getXPos();

    float getYPos();

    void moveLeft();
 
    void moveRight();

    void moveUp();

    void moveDown();
 
    void update();

    void gameover();
 
};
