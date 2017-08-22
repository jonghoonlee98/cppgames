#include "player.h"
#include "ball.h"
#include "ghost.h"
#include "star.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;
void playGame(RenderWindow &,int,int);

int main()
{
	int windowWidth = 1536;
    int windowHeight = 1152;
    RenderWindow window(VideoMode(windowWidth, windowHeight), "nocgoot");
	playGame(window,windowWidth,windowHeight);
    return 0;
}

void playGame(RenderWindow &window,int windowWidth,int windowHeight)
{
	srand(time(NULL));



    int score = 0;
    int lives = 1;
 	bool gameover=false;
 	int time_new_level=15000;

    Player player (windowWidth / 2, windowHeight - 25);
 
    Ghost ghost;

    Star star;
    float star_xpos = rand()/(float)RAND_MAX*(windowWidth-60)+10;
   	float star_ypos = rand()/(float)RAND_MAX*(windowHeight-60)+10;
    star.changePos(star_xpos,star_ypos);

    vector<Ball> ball;
    int num_balls=0;

   	bool blink[5]={false,false,false,false,false};

	Text hud;
 
	Font font;

	font.loadFromFile("arial.ttf");
	 
	hud.setFont(font);
	 
	hud.setCharacterSize(40);
	 
	hud.setColor(Color::White);

	Clock clock;

	while (window.isOpen())
	{
	    /*
	        Handle the player input
	        ***************************************************************
	        ***************************************************************
	        ***************************************************************
	    */
	 
	    Event event;
	    while (window.pollEvent(event))
	    {
	        if (event.type == Event::Closed)
	            // Someone closed the window- bye
	            window.close();
	    }
	 
	    if (Keyboard::isKeyPressed(Keyboard::Left))
	    {
	        // move left...
	        player.moveLeft();
	    }
	    else if (Keyboard::isKeyPressed(Keyboard::Right))
	    {
	        // move right...
	        player.moveRight();
	    }
	    else if (Keyboard::isKeyPressed(Keyboard::Up))
	    {
	        // move up...
	        player.moveUp();
	    }
	    else if (Keyboard::isKeyPressed(Keyboard::Down))
	    {
	        // move down...
	        player.moveDown();
	    }
	    else if (Keyboard::isKeyPressed(Keyboard::Escape))
	    {
	    	// quit
	        // Someone closed the window- bye
	        window.close();
	    }

	    /*
	    Update the frame
	    ****************************************************************
	    ****************************************************************
	    ****************************************************************
		*/
		int xpos=player.getXPos();
		int ypos=player.getYPos();
	    ghost.chase(xpos,ypos);

		int dur=clock.getElapsedTime().asMilliseconds();

		Ball new_ball;
	   	if((dur>time_new_level&&num_balls<10)&&blink[0]==false) {
	   		num_balls++;
	   		float x = rand()/(float)RAND_MAX*(windowWidth-30)+10;
	    	float y = rand()/(float)RAND_MAX*(windowHeight-30)+10;
	    	new_ball.changePos(x,y);
	    	ball.push_back(new_ball);
	    	time_new_level+=500;
	    	blink[0]=true;
	   	}

	   	if(dur>time_new_level&&blink[1]==false) {
	   		ball[num_balls-1].changeColor();
	   		time_new_level+=500;
	   		blink[1]=true;
	   	}

	   	if(dur>time_new_level&&blink[2]==false) {
	   		ball[num_balls-1].changeColor();
	   		time_new_level+=500;
	   		blink[2]=true;
	   	}

	   	if(dur>time_new_level&&blink[3]==false) {
	   		ball[num_balls-1].changeColor();
	   		time_new_level+=500;
	   		blink[3]=true;
	   	}

	   	if(dur>time_new_level&&blink[4]==false) {
	   		ball[num_balls-1].changeColor();
	   		time_new_level+=500;
	   		blink[4]=true;
	   	}

	   	if(dur>time_new_level) {
	   		float xspeed,yspeed;
	   		int x=rand()%2;
	   		int y=rand()%2;
	   		if(x==0)
	   			xspeed = (rand()/(float)RAND_MAX*0.4)+0.65;
	   		else
	   			xspeed = -((rand()/(float)RAND_MAX*0.4)+0.65);
	   		if(y==0)
	    		yspeed = (rand()/(float)RAND_MAX*0.4)+0.65;
	    	else
	    		yspeed = -((rand()/(float)RAND_MAX*0.4)+0.65);
	   		ball[num_balls-1].changeVel(xspeed,yspeed);
	   		time_new_level+=22500;
	   		ball[num_balls-1].nowInPlay();
	   		for(int i=0;i<5;i++)
	   			blink[i]=false;
	   	}

 		for(int i=0;i<num_balls;i++) {
			// Handle ball hitting the bottom or top
			if (ball[i].getPosition().top > windowHeight ||
				ball[i].getPosition().top < 0)
			{
			 	ball[i].reboundBotOrTop();
			}
			 
			// Handle ball hitting sides
			if (ball[i].getPosition().left < 0 ||
			 	ball[i].getPosition().left + 10 > windowWidth)
			{
			    ball[i].reboundSides();
			}
			 
			// Has the ball hit the player?
			if (ball[i].getPosition().intersects(player.getPosition())&&ball[i].inPlay()==true)
			{
				gameover=true;
				break;
			}
		}

		if (ghost.getPosition().intersects(player.getPosition()))
		{
			gameover=true;
		}

		if (star.getPosition().intersects(player.getPosition())&&gameover==false)
		{
			score+=5;
		    float star_xpos = rand()/(float)RAND_MAX*(windowWidth-60)+10;
			float star_ypos = rand()/(float)RAND_MAX*(windowHeight-60)+10;
			star.changePos(star_xpos,star_ypos);
		}
			

		for(int i=0;i<num_balls;i++)
			ball[i].update();
		player.update();
		ghost.update();
		star.update();
		 
		// Update the HUD text
		stringstream ss;
		ss << "Score:" << score << "    Lives:" << lives;
		hud.setString(ss.str());

		if(gameover==true) {
			player.gameover();
			ghost.gameover();
			stringstream ss;
			ss << "GAMEOVER" << endl << "Final Score: " << score <<
			endl<<"To play again, press 1";
			hud.setString(ss.str());	
			if(Keyboard::isKeyPressed(Keyboard::Num1))
				playGame(window,windowWidth,windowHeight);
		}

         /*
            Draw the frame
            ***************************************************************
            ***************************************************************
            ***************************************************************
        */
 
        // Clear everything from the last frame
        window.clear(Color(Color::Black));
 
        window.draw(player.getShape());

        window.draw(ghost.getShape());

        window.draw(star.getShape());
 
 		for(int i=0;i<num_balls;i++)
        	window.draw(ball[i].getShape());
 
        // Draw our score
        window.draw(hud);
 
        // Show everything we just drew
        window.display();
    }	// This is the end of the "while" loop
  
}
