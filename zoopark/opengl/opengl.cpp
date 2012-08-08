//
//  opengl.cpp
//  zoopark
//
//  Created by Simon Bosley on 05/08/2012.
//  Copyright (c) 2012 Simon Bosley. All rights reserved.
//

// Project headers
#include "opengl.h"

// STL headers
#include <iostream>

// Mac OS X headers
#ifdef TARGET_MAC_OS
    #include <GLUT/GLUT.h>
#endif

// Linux headers
#ifdef TARGET_LINUX_OS
   #include <GL/OpenGL.h>
   #include <GL/glu.h>
#endif

void window( int argc, char* argv[] )
{
    // Initializes the GLUT framework
    glutInit( &argc, argv );                                         
    
    // Sets up the display mode
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    
    // Set the initial window position and size
    glutInitWindowPosition( 100, 100 );
    glutInitWindowSize( 300, 300 );
    
    // Creates a window
    glutCreateWindow( "My first GLUT program" );
    
    // Set the drawing function
    glutDisplayFunc( redraw );
    
    // Set the current matrix to projection type
    glMatrixMode( GL_PROJECTION );
    
	// Sets up the projection matrix for a perspective transform
    // [view angle, aspect ratio, near clip, far clip]
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
    
    GLint viewport[4];
    
    glGetIntegerv( GL_VIEWPORT, viewport );
    
    std::cout << "GL_VIEWPORT x1: " << viewport[0] << ", y1: " << viewport[1] << ", x2: " << viewport[2] << ", y2 = " << viewport[3] << std::endl;
    
    // The main loop of the GLUT framework
	glutMainLoop();
}

void redraw()
{
    // Clears the colour and depth buffers
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    // Push the current matrix on the top of the matrix stack at [x, y, z] : [0, 0, -100]
	glPushMatrix();
	glTranslated( 0, 0, -100 );
	
    // Drawing triangles, specify the first vertex color and position
	glBegin( GL_TRIANGLES );
	glColor3d( 1, 0, 0 );
	glVertex3d( -30, -30, 0 );
    
    // Set the colour to green and set the second vertex
	glColor3d( 0, 1, 0 );
	glVertex3d( 30, -30, 0 );
    
    // Second vertex in blue
	glColor3d( 0, 0, 1 );
	glVertex3d( -30, 30, 0 );
    
    // Finish drawing, pop the matrix off the stack
	glEnd();
	glPopMatrix();
	
    // Send the output to the screen
    glutSwapBuffers();
}

