#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Ghost
{
private:
	Vector2f position;
	CircleShape ghost;
	float ghostSpeed=0.2f;
public:
	Ghost();
    FloatRect getPosition();
    CircleShape getShape();
    void update();
    void chase(float xpos,float ypos);
    void gameover();
};