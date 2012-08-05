//
//  opengl.cpp
//  zoopark
//
//  Created by Simon Bosley on 05/08/2012.
//  Copyright (c) 2012 Simon Bosley. All rights reserved.
//

#include "opengl.h"

#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>

void window( int argc, char* argv[] )
{
    glutInit( &argc, argv );                                         //initializes the GLUT framework
  	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );   //sets up the display mode
    
    glutCreateWindow( "My first GLUT program" );                  //creates a window
    
    // Set the drawing function
  	glutDisplayFunc( redraw );
    
    // Set the current matrix to projection type
	glMatrixMode( GL_PROJECTION );
    
	// Sets up the projection matrix for a perspective transform [view angle, aspect ratio, near clip, far clip]
	gluPerspective( 45, 1.0, 10.0, 200.0 );
	
	/*
     
        When we're done we switch the current matrix to the modelview matrix.
        The modelview matrix is a 4x4 matrix used to transform points from their 
        actual positions (in world space) into their positions relative to the camera. 
        It's the matrix we use to specify our camera position and the position of 
        anything we draw. The glutMainLoop() function is the main loop of the GLUT 
        framework and we need to call it next.
     
     */
    
	glMatrixMode( GL_MODELVIEW );
    
    //the main loop of the GLUT framework
	glutMainLoop();
}

void redraw()
{
    // Clears the colour and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Push the current matrix on the top of the matrix stack at [x, y, z] : [0, 0, -100]
	glPushMatrix();
	glTranslatef( 0,0,-100 );
	
    // Drawing triangles, specify the first vertex color and position
	glBegin( GL_TRIANGLES );
	glColor3f( 1,0,0 );
	glVertex3f( -30,-30,0 );
    
    // Set the colour to green and set the second vertex
	glColor3f( 0, 1, 0 );
	glVertex3f( 30, -30, 0 );
    
    // Second vertex in blue
	glColor3f( 0, 0, 1 );
	glVertex3f( -30, 30, 0 );
    
    // Finish drawing, pop the matrix off the stack
	glEnd();
	glPopMatrix();
	
    // Send the output to the screen
    glutSwapBuffers();
}