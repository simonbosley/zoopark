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
    #include <GL/freeglut_std.h>
#endif

// Window Settings
class Viewport
{
public:
    Viewport( GLdouble settings[6] )
    {
        left = settings[0];
        right = settings[1];
        bottom = settings[2];
        top = settings[3];
        zNear = settings[4];
        zFar = settings[5];
    }
    
    GLdouble left;
    GLdouble right;
    GLdouble bottom;
    GLdouble top;
    GLdouble zNear;
    GLdouble zFar;
};

class Render
{
public:
    static void redraw()
    {
        // Clears the colour
        glClear( GL_COLOR_BUFFER_BIT );
        
        // Draws a single point
        glBegin( GL_POINTS );
        glVertex2f( 100 + 0.5, 200 + 0.5 );
        glEnd();
        
        // Send the output to the screen
        glutSwapBuffers();
    }
};

void window( int argc, char* argv[] )
{
    // Initializes the GLUT framework
    glutInit( &argc, argv );                                         
    
    // Sets up the display mode
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    
    // Set the initial window position and size
    glutInitWindowPosition( 100, 100 );
    glutInitWindowSize( 640.0, 480.0 );
    
    // Creates a window
    glutCreateWindow( "My first GLUT program" );
    
    // Set the drawing function
    glutDisplayFunc( Render::redraw );
    
    // Disable depth as we're 2D
    glDisable( GL_DEPTH_TEST );
    
    // Set-up a 2D view for drawing
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    GLdouble settings[] = { 0.0, 640.0, 480.0, 0.0, 0.0, 1.0 };
    Viewport vp( settings );
    glOrtho( vp.left, vp.right, vp.bottom, vp.top, vp.zNear, vp.zFar );
    
    glMatrixMode( GL_MODELVIEW );
    
    // The main loop of the GLUT framework
	glutMainLoop();
}

void redraw()
{
    // Clears the colour
    glClear( GL_COLOR_BUFFER_BIT );
    
    // Draws a single point
    glBegin( GL_POINTS );
    glVertex2f( 100 + 0.5, 200 + 0.5 );
    glEnd();
	
    // Send the output to the screen
    glutSwapBuffers();
}

