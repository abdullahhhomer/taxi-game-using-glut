//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<cstdlib>
#include<fstream>
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */


void level_1();
void level_2();
void level_3();
void grid(); 
void frame();
void menu();
void track();
//void data_handling();
void ranging();
//void pass();
//void pass_drop();
void hard1();
void SetCanvasSize(int width, int height)
{

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();

}

int x1_tree,y1_tree,x2_tree,y2_tree,x3_tree,y3_tree,x4_tree,y4_tree;// global varibales
int x1_box,y1_box,x2_box,y2_box,x3_box,y3_box;
int pass_x,pass_y;


int first,second,third,value;
int axis_x,axis_y;
int dx,dy,total=0;



void hard2();









void obs_level1()
{
	x1_tree=300,y1_tree=320;
	x2_tree=500,y2_tree=640;
	x3_tree=100,y3_tree=120;
	DrawCircle(x1_tree+6,y1_tree+29,14,colors[GREEN]);
	DrawRectangle(x1_tree,y1_tree,13,24,colors[BROWN]);
	
	DrawCircle(x2_tree+6,y2_tree+29,14,colors[GREEN]);
	DrawRectangle(x2_tree,y2_tree,13,24,colors[BROWN]);
	
	DrawCircle(x3_tree+6,y3_tree+29,14,colors[GREEN]);
	DrawRectangle(x3_tree,y3_tree,13,24,colors[BROWN]);	

}
void obs_level2()
{
	x1_tree=300,y1_tree=320;
	x2_tree=500,y2_tree=640;
	x3_tree=100,y3_tree=120;
	x4_tree=420,y4_tree=520;
	DrawCircle(x1_tree+6,y1_tree+29,14,colors[GREEN]);
	DrawRectangle(x1_tree,y1_tree,13,24,colors[BROWN]);
	
	DrawCircle(x2_tree+6,y2_tree+29,14,colors[GREEN]);
	DrawRectangle(x2_tree,y2_tree,13,24,colors[BROWN]);
	
	DrawCircle(x3_tree+6,y3_tree+29,14,colors[GREEN]);
	DrawRectangle(x3_tree,y3_tree,13,24,colors[BROWN]);

	DrawCircle(x4_tree+6,y4_tree+29,14,colors[GREEN]);
	DrawRectangle(x4_tree,y4_tree,13,24,colors[BROWN]);	

}
void obs_level3()
{
	x1_tree=300,y1_tree=320;
	x2_tree=500,y2_tree=640;
	x3_tree=100,y3_tree=120;
	x4_tree=420,y4_tree=520;
	x1_box=200,y1_box=640;
	x2_box=480,y2_box=200;
	x3_box=560,y3_box=480;


	DrawCircle(x1_tree+6,y1_tree+29,14,colors[GREEN]);
	DrawRectangle(x1_tree,y1_tree,13,24,colors[BROWN]);
	
	DrawCircle(x2_tree+6,y2_tree+29,14,colors[GREEN]);
	DrawRectangle(x2_tree,y2_tree,13,24,colors[BROWN]);
	
	DrawCircle(x3_tree+6,y3_tree+29,14,colors[GREEN]);
	DrawRectangle(x3_tree,y3_tree,13,24,colors[BROWN]);

	DrawCircle(x4_tree+6,y4_tree+29,14,colors[GREEN]);
	DrawRectangle(x4_tree,y4_tree,13,24,colors[BROWN]);	

	DrawSquare(x1_box,y1_box,40,colors[BROWN]);
	DrawSquare(x2_box,y2_box,40,colors[BROWN]);
	DrawSquare(x3_box,y3_box,40,colors[BROWN]);
}





int xI = 40, yI = 80; // taxi coordinates
int x=120, y=450,x_1=400,y_1=160            ;//obs cars cord

void drawCar1() {//obstacle cars
	
	
	DrawRectangle(x_1,y_1 ,35 , 30, colors[BLUE]);
	DrawCircle(x_1+30,y_1,6,colors[BLACK]);
	DrawCircle(x_1+10,y_1,6,colors[BLACK]);
	
	glutPostRedisplay();
}
void drawCar2()
{	

	DrawRectangle(x,y,35 , 30, colors[BLUE]);
	DrawCircle(x+30,y,6,colors[BLACK]);
	DrawCircle(x+10,y,6,colors[BLACK]);
	
}	

void drawCar() {//taxi
	DrawRectangle(xI,yI ,35 , 30, colors[ORANGE]);
	DrawCircle(xI+30,yI,6,colors[BLACK]);
	DrawCircle(xI+10,yI,6,colors[BLACK]);
	glutPostRedisplay();
}	

bool car_flag=true;
void move()
{
	


if (xI > 10 && car_flag) {
	
		cout << "going left";
		if(xI < 40)
			
			car_flag = false;

	}
	else if (xI < 1010 && !car_flag) {
		cout << "go right";
		xI += 10;
		if (xI > 700)
			car_flag = true;
	}


}

bool flag=true;

/*void moveCar() {
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}
*/

void moveCar_x() {
	
	if (x_1 > 10 && flag) {
		x_1 -= 10;
		cout << "going left";
		if(x_1 < 400)
			
			flag = false;

	}
	else if (x_1 < 1010 && !flag) {
		cout << "go right";
		x_1 += 10;
		if (x_1 > 700)
			flag = true;
	}
	if (x > 10 && flag) {
		x -= 10;
		cout << "going left";
		if(x < 120)
			
			flag = false;

	}
	else if (x < 1010 && !flag) {
		cout << "go right";
		x += 10;
		if (x > 600)
			flag = true;
	}
	
}
bool flag1=true;
/*void moveCar_y() {
	
	if (y > 10 && flag1) {
		y += 10;
		cout << "going up";
		    
		
		
		
		if(y < 600)
			
			flag1 =true ;

	}
	else if (y < 820 && !flag1) {
		cout << "go down";
		y -= 10;
		if (y > 600)
			flag1 = false;
	}
	if (y_ > 10 && flag1) {
		y -= 10;
		cout << "going left";
		if(y < 100)
			
			flag1 = false;

	}
	else if (y < 1010 && !flag1) {
		cout << "go right";
		y += 10;
		if (y > 900)
			flag1 = true;
	}

	
}
*/
/*
 * Main Canvas drawing function.
 * */
bool a=true;

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	///*glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
	//		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
//	menu();

	DrawString(820,820,"score"+Num2Str(total),colors[BLUE]);
	grid();
	frame();
	track();
	
	
	
	level_3();

	hard1();
	hard2();


	// random number generation attempt
	/*while(true)
	{
		if(a)
		{
		pass();
		}
		if(value==32)
		{

			if((xI+20>=axis_x&&xI-20<=axis_x )&&(yI+20>=axis_y&&yI-20<=axis_y )  )
			{
				pass_drop();		
				a=false;
					
			}
		}
		if((xI+20>=dx&&xI-20<=dx )&&(yI+20>=dy&&yI-20<=dy )  )
		{
			break;
		}
	}*/
	glutSwapBuffers(); // do not modify this line..

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
	xI-=10;
	
		if(xI < 40)
			xI=45;
			

	}
	
	
	 else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) 
		{
			xI += 10;
			if(xI > 720)
				xI=720;
		}
	 else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
		if(yI>760)
			yI=758;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
		if(yI<40)
			yI=42;
	}
	else if(key==32)
	value=key;

	/*else if(value==32)
	{
		if((xI+20>=axis_x&&xI-20<=axis_x )&&(yI+20>=axis_y&&yI-20<=axis_y )  )
		{

		}
	}

*/
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}



/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) 
{
	if (key == 27/* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
//	moveCar_y();
	moveCar_x();
	//move();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) 
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
 
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Abdullah Omer"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters

//	data_handling();
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
	
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */

// displays the grid of the whole game 

void grid()
{
	for(int i=0;i<=760;i+=40)
	{
		for(int j=0;j<=800;j+=40)
		{
			DrawSquare(i, j, 39, colors[AQUA_MARINE]);
		}
		cout<<endl;
	}

}
void frame()
{
	for(int i=0;i<800;i+=40)
	{
		DrawSquare(i,800,39,colors[DARK_BLUE]);
	}
	for(int i=0;i<800;i+=40)
	{
		DrawSquare(760,i,39,colors[DARK_BLUE]);
	}
	for(int i=0;i<800;i+=40)
	{
		DrawSquare(i,0,39,colors[DARK_BLUE]);
	}
	for(int i=0;i<800;i+=40)
	{
		DrawSquare(0,i,39,colors[DARK_BLUE]);
	}
}



void track()
{
//	DrawRectangle(int sx, int sy, int width, int height, colors[LIGHT_YELLOW])
	DrawRectangle(160, 280,40 , 160, colors[BLUE]);//verticle rectangle in lower left  corner
	DrawRectangle(160,240 ,160 , 40, colors[BLUE]); // horizontal rectangle in middle
	DrawRectangle(600,560 ,40 , 160, colors[BLUE]);
	DrawRectangle(160,560,160,40,colors[BLUE]);
	DrawRectangle(280,560,40,160,colors[BLUE]);
	DrawRectangle(600, 240,40 , 160, colors[BLUE]);//verticle rectangle in lower left  corner
	DrawRectangle(480,400 ,160 , 40, colors[BLUE]); // horizontal rectangle in middle
}
void level_1()
{
	drawCar();
	drawCar1();
	obs_level1();
	ranging();
}

void level_2()
{
	drawCar();
	drawCar1();
	drawCar2();
	obs_level2();	
	move();
	ranging();
}
void level_3()
{
	drawCar();
	drawCar1();
	drawCar2();

	obs_level3();	
	
	move();
	ranging();
}





void data_handling()
{
	cin.ignore();
	ofstream myfile;
	string name="namedhighscores.txt",info;
	
	myfile.open(name);
	getline(cin,info);
	myfile<<info;
	myfile.close();
}

void ranging()
{

	/*
		RANGING USED FOR TREES	
	*/
	if(( xI>=260&&xI<=320) && (yI>=310&&yI<=360      )        )
	{
		xI-=10;
		yI-=10;
		total-=2;
	}
	else if(( xI>=470&&xI<=530) && (yI>=635&&yI<=680      )        )
	{
		xI-=10;
		yI-=10;
		total-=2;
	}
	else if(( xI>=420&&xI<=460) && (yI>=480&&yI<=530     )        )
	{
		xI-=10;
		yI-=10;
		total-=2;
	}
	else if(( xI>=70&&xI<=120) && (yI>=120&&yI<=160      )        )
	{
		xI-=10;
		yI-=10;
		total-=2;
	}

	 if (( xI>=180&&xI<=220) && (yI>=620&&yI<=660      ))
	 {
		xI-=10;
		yI-=10;
		total-=2;
	 }
	 else if(( xI>=460&&xI<=500) && (yI>=180&&yI<=220      ))
	 {
		xI-=10;
		yI-=10;
		total-=2;
	 }
	 else if(( xI>=520&&xI<=560) && (yI>=460&&yI<=500      ))
	 {
		xI-=10;
		yI-=10;
		total-=2;
	 }

	 else if(xI==x && yI==y)  
	 {	
	 yI-=20;
	 total-=2;
	 }
    else if(xI==x_1&& yI==y_1  )
	 {	
	 yI-=20;
	 total-=2;
	 }
	else if( (xI>=130&&xI<=180) && (yI>=280&&yI<=440)  )
	{
		xI-=30;
		yI-=30;
	}
	else if( (xI>=570&&xI<=630) && (yI>=550&&yI<=720)  )
	{
		xI-=30;
		yI-=30;
	}
	else if( (xI>=250&&xI<=310) && (yI>=550&&yI<=720)  )
	{
		xI-=30;
		yI-=30;
	}
	else if( (xI>=570&&xI<=630) && (yI>=240&&yI<=400)  )
	{
		xI-=30;
		yI-=30;
	}
	
	
	
	
	else if( (xI>=120&&xI<=320) && (yI>=210&&yI<=270)  )
	{
		xI-=30;
		yI-=30;
	}
	else if( (xI>=120&&xI<=320) && (yI>=530&&yI<=590)  )
	{
		xI-=30;
		yI-=30;
	}
	else if( (xI>=440&&xI<=600) && (yI>=370&&yI<=430)  )
	{
		xI-=30;
		yI-=30;
	}





}
//bool h1=true;
int h=80,x23=640;
int h1=240,x3=400;
void hard1()
{

		
		DrawSquare(h,x23,30,colors[GREEN]);	
		
		if(xI==h&&yI==x23)
		{
			
		
		
		
		
			DrawSquare(h1,x3,30,colors[RED]);
			h=20000;
			x23=33333;
		}	
		DrawSquare(h1,x3,30,colors[RED]);
		if(xI==h1&&yI==x3)
		{h1=44444;
		x23=444444;
		total+=10;

		

		}
		


}
int h34=640,x22=120;
int h13=120,x33=400;
void hard2()
{

		
		DrawSquare(h34,x22,30,colors[GREEN]);	
		
		if(xI==h34&&yI==x22)
		{
			
		
		
		
		
			DrawSquare(h13,x33,30,colors[RED]);
			h34=20000;
			x22=33333;
		}	
		DrawSquare(h13,x33,30,colors[RED]);
		if(xI==h13&&yI==x33)
		{h13=44444;
		x33=444444;
		total+=10;

		

		}
		


}


bool ps=true;
void pass()
{
	srand(time(0));
	while (ps)
	{
		pass_x=rand()%820;	
		pass_y=rand()%820;
		if(( pass_x>=260&&pass_x<=320) && (pass_y>=310&&pass_y<=360      )        )
	 {
		continue;
			}
	else if(( pass_x>=470&&pass_x<=530) && (pass_y>=635&&pass_y<=680      )        )
	{
		
		continue;
	}
	else if(( pass_x>=420&&pass_x<=460) && (pass_y>=480&&pass_y<=530     )        )
	{
		continue;
	}
	else if(( pass_x>=70&&pass_x<=120) && (pass_y>=120&&pass_y<=160      )        )
	{
		continue;	}

	 if (( pass_x>=180&&pass_x<=220) && (pass_y>=620&&pass_y<=660      ))
	 {
		continue;
	 }
	 else if(( pass_x>=460&&pass_x<=500) && (pass_y>=180&&pass_y<=220      ))
	 {
		continue;
	 }
	 else if(( pass_x>=520&&pass_x<=560) && (pass_y>=460&&pass_y<=500      ))
	 {
		continue;
	 }	
	 else if(pass_x==0 && (pass_y>=0&&pass_y<=720 )  )
	 continue;
	else if(pass_x==720 && (pass_y>=0&&pass_y<=720 )  )
	 continue;
	 else if((pass_x>=0&&pass_x<=720 )&&pass_y==0   )
	 continue;
	 else if((pass_x>=0&&pass_x<=720 )&&pass_y==720   )
	 continue;
	else if(pass_x==40&&pass_y==40)
	continue;
	else
	break;

	}
	DrawSquare(pass_x,pass_y,38,colors[GREEN_YELLOW]);
	ps=false;		
	axis_x=pass_x;
	axis_y=pass_y;	

}

void pass_drop()
{
	srand(time(0));
	while (!ps)
	{
		pass_x=rand()%820;	
		pass_y=rand()%820;
		if(( pass_x>=260&&pass_x<=320) && (pass_y>=310&&pass_y<=360      )        )
	 {
		continue;
			}
	else if(( pass_x>=470&&pass_x<=530) && (pass_y>=635&&pass_y<=680      )        )
	{
		
		continue;
	}
	else if(( pass_x>=420&&pass_x<=460) && (pass_y>=480&&pass_y<=530     )        )
	{
		continue;
	}
	else if(( pass_x>=70&&pass_x<=120) && (pass_y>=120&&pass_y<=160      )        )
	{
		continue;	}

	 if (( pass_x>=180&&pass_x<=220) && (pass_y>=620&&pass_y<=660      ))
	 {
		continue;
	 }
	 else if(( pass_x>=460&&pass_x<=500) && (pass_y>=180&&pass_y<=220      ))
	 {
		continue;
	 }
	 else if(( pass_x>=520&&pass_x<=560) && (pass_y>=460&&pass_y<=500      ))
	 {
		continue;
	 }	
	 else if(pass_x==0 && (pass_y>=0&&pass_y<=720 )  )
	 continue;
	else if(pass_x==720 && (pass_y>=0&&pass_y<=720 )  )
	 continue;
	 else if((pass_x>=0&&pass_x<=720 )&&pass_y==0   )
	 continue;
	 else if((pass_x>=0&&pass_x<=720 )&&pass_y==720   )
	 continue;
	else if(pass_x==40&&pass_y==40)
	continue;
	}

	while(true)
	{
		if(pass_y!=axis_y||pass_x!=axis_x )
		{
			break;
		}
	}

	dx=pass_x;
	dy=pass_y;

	DrawSquare(pass_x,pass_y,38,colors[RED]);
	ps=true;		
	
	


}









