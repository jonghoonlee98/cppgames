#include "ghost.h"

Ghost::Ghost()
{
	ghost.setRadius(20);
	ghost.setFillColor(Color::Blue);
	position.x=0;
	position.y=0;
}

FloatRect Ghost::getPosition()
{
    return ghost.getGlobalBounds();
}
 
CircleShape Ghost::getShape()
{
    return ghost;
}

void Ghost::update()
{
    ghost.setPosition(position);
}

void Ghost::chase(float xpos,float ypos)
{
	if(position.x<=xpos)
		position.x+=ghostSpeed;
	else
		position.x-=ghostSpeed;
	if(position.y<=ypos)
		position.y+=ghostSpeed;
	else
		position.y-=ghostSpeed;
}

void Ghost::gameover()
{
	ghostSpeed=0.0f;
}