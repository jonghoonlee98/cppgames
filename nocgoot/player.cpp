//#include "stdafx.h"
#include "player.h"
 
// This the constructor and it is called when we create an object
Player::Player(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
 
    playerShape.setSize(sf::Vector2f(25, 25));
    playerShape.setPosition(position);
}

FloatRect Player::getPosition()
{
    return playerShape.getGlobalBounds();
}
 
RectangleShape Player::getShape()
{
    return playerShape;
}
 
float Player::getXPos()
{
    return position.x;
}

float Player::getYPos()
{
    return position.y;   
}

void Player::moveLeft()
{
	if(int(position.x)!=0)
    	position.x -= playerSpeed;
}
 
void Player::moveRight()
{
	if(int(position.x)!=1511)
        position.x += playerSpeed;
}

void Player::moveUp()
{
	if(int(position.y)!=0)
    	position.y -= playerSpeed;
}
 
void Player::moveDown()
{
	if(int(position.y)!=1127)
    	position.y += playerSpeed;
}
 
void Player::update()
{
    playerShape.setPosition(position);
}