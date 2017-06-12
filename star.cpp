#include "star.h"

using namespace sf;

Star::Star()
{
	star.setPointCount(10);
	star.setPoint(0, Vector2f(25,0));
	star.setPoint(1, Vector2f(31,20));
	star.setPoint(2, Vector2f(49,20));
	star.setPoint(3, Vector2f(34,29));
	star.setPoint(4, Vector2f(40,50));
	star.setPoint(5, Vector2f(25,37));
	star.setPoint(6, Vector2f(10,50));
	star.setPoint(7, Vector2f(16,29));
	star.setPoint(8, Vector2f(0,20));
	star.setPoint(9, Vector2f(19,20));
	star.setFillColor(Color::Yellow);
}

FloatRect Star::getPosition()
{
    return star.getGlobalBounds();
}
 
ConvexShape Star::getShape()
{
    return star;
}

void Star::update()
{
    star.setPosition(position);
}

void Star::changePos(float x,float y)
{
	position.x=x;
	position.y=y;
}