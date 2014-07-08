//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// height and width of paddle
#define HEIGHTPAD 15
#define WIDTHPAD 60


// number of rows of bricks
#define ROWS 6

// number of columns of bricks
#define COLS 8

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);
string colors[6] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "BLACK"};

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    waitForClick();
    //Display "You Lost" if lives reaches 0.
    if(lives == 0){
   		GLabel lost;
   		double x, y;
    	lost = newGLabel("YOU LOST!");
    	setFont(lost, "sansSerif-40");
   		x = (getWidth(window) - getWidth(lost)) / 2;
   		y = (getHeight(window) + getFontAscent(lost)) / 2;
   		setLocation(lost, x, y);
   		add(window, lost);
    	waitForClick();
    }
    // keep playing until game over
    double Yvelocity = 0.1;
    double Xvelocity = 0.1;
    while (lives > 0 && bricks > 0){
    	//Win display
    	if(points >= bricks){
    		GLabel win;
    		double x, y;
    		win = newGLabel("YOU WON!");
    		setFont(win, "sansSerif-40");
    		x = (getWidth(window) - getWidth(win)) / 2;
    		y = (getHeight(window) + getFontAscent(win)) / 2;
    		setLocation(win, x, y);
    		add(window, win);
    		waitForClick();
    		closeGWindow(window);
    		return 0;
    	}
    	//checks collision with bricks and paddle!
    	GObject object = detectCollision(window, ball);
    	move(ball, Xvelocity, Yvelocity);
    	if(object != NULL){

			if(strcmp(getType(object), "GRect") == 0 && object != paddle){
				removeGWindow(window, object);
				Yvelocity = (-Yvelocity * 1.1);
				points++;
				updateScoreboard(window, label, points);
				setColor(ball, colors[points %6]);
			}
			else if(object == paddle){
				Yvelocity = -0.1;
			}
		}
		//Bounce of off walls.
		if(getY(ball) <= 0){
			Yvelocity = -Yvelocity;
		}
		else if(getY(ball) + 15 >= 600){
			lives--;
			setLocation(ball, WIDTH / 2 - 20, HEIGHT / 2 - 20);
			if(lives > 0){
				waitForClick();

			}
				
		}
		if(getX(ball) <= 0){
			Xvelocity = -Xvelocity;
		}
		else if(getX(ball) + 15 >= 400){
		Xvelocity = -Xvelocity;
		}	
		
		
		//paddle follows mouse.
        GEvent event = getNextEvent(MOUSE_EVENT);
       	double y = 550;
        if(getX(paddle) <= 0){
        	setLocation(paddle, 0, y);
        }
        else if(getX(paddle) + WIDTHPAD >= 400){
        	setLocation(paddle, 400 - WIDTHPAD, y);
        }
        if(event != NULL){
        	if(getEventType(event) == MOUSE_MOVED){
        		double x = getX(event);

        		setLocation(paddle, x, y);
        	
        	}
        }
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{	
	
	double w = WIDTH / 10;
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			GRect brick = newGRect(w * j + 10 * j , 50 + 25 * i, w, HEIGHTPAD );
			setColor(brick, colors[5 - i]);
			setFilled(brick, true);
			add(window, brick);
		}
	}



}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
	GOval ball = newGOval(WIDTH / 2 - 20, HEIGHT / 2 - 20, 20, 20);
	setFilled(ball, true);
    add(window, ball);
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window){
    GRect rect = newGRect(WIDTH / 2 - (WIDTHPAD/2) , 550, WIDTHPAD, HEIGHTPAD);
	setFilled(rect, true);
	setColor(rect, "BLACK");
	add (window, rect);
    
    
    return rect;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window){
	GLabel label;
	label = newGLabel("");
	setFont(label, "SansSerif-50");
	setColor(label, "GRAY");
	add(window, label);


    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
