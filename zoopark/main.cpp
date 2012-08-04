// File: main.cpp
// Author: Simon Bosley
// Copyright: Sunday 8th July, 2012
// Synopsis: Program to launch our application

// Standard Template Library includes
#include <iostream>
#include <string>

// Standard C++ headers
#include <stdlib.h>
#include <stdio.h>

// OpenGL Headers
#include <OpenGL/OpenGL.h>
//#include <GL/gl.h>
#include <OpenGL/glu.h>
//#include <OpenGL/glut.h>
#include <GLUT/GLUT.h>

// If we want to save sometime then uncomment the following line....
//using namespace std;

static void redraw( void );

int main( int argc, char* argv[] )
{
	std::string greeting("Starting zoopark...");
	std::cout << greeting << std::endl;


	for (int i=0; i<argc; ++i)
	{
		std::cout << argv[i] << std::endl;
	}

	glutInit(&argc,argv);                                         //initializes the GLUT framework
  	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);   //sets up the display mode
    	glutCreateWindow("My first GLUT program");                  //creates a window
      	glutDisplayFunc(redraw);                                    //specifies our redraw function
      
	glMatrixMode(GL_PROJECTION);   //changes the current matrix to the projection matrix

	//sets up the projection matrix for a perspective transform
	gluPerspective(	45,     //view angle
			1.0,    //aspect ratio
			10.0,   //near clip
			200.0); //far clip 
	
	//When we're done we switch the current matrix to the modelview matrix. The modelview matrix is a 4x4 matrix used to transform points from their actual positions (in world space) into their positions relative to the camera. It's the matrix we use to specify our camera position and the position of anything we draw. The glutMainLoop() function is the main loop of the GLUT framework and we need to call it next.
	glMatrixMode(GL_MODELVIEW);   //changes the current matrix to the modelview matrix
	    
	glutMainLoop();               //the main loop of the GLUT framework
	
	return 0;
}

static void redraw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //clears the colour and depth buffers

	glPushMatrix();       //saves the current matrix on the top of the matrix stack
	glTranslatef(0,0,-100); //translates the current matrix 0 in x, 0 in y and -100 in z
	
	glBegin(GL_TRIANGLES);  //tells OpenGL that we're going to start drawing triangles
	glColor3f(1,0,0);     //sets the current colour to red
	glVertex3f(-30,-30,0);  //specifies the first vertex of our triangle
	      
	glColor3f(0,1,0);     //sets the current colour to green
	glVertex3f(30,-30,0);   //specifies the second vertex of our triangle
		    
	glColor3f(0,0,1);     //sets the current colour to blue
	glVertex3f(-30,30,0);   //specifies the third vertex of our triangle
	glEnd();                //tells OpenGL that we've finished drawing
	glPopMatrix();          //retrieves our saved matrix from the top of the matrix stack
	glutSwapBuffers();      //swaps the front and back buffers
}	
