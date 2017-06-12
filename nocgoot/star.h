#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Star
{
private:
	Vector2f position;
	ConvexShape star;
public:
	Star();
    FloatRect getPosition();
    ConvexShape getShape();
    void update();
    void changePos(float x,float y);
};