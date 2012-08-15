//
//  opengl.cpp
//  zoopark
//
//  Created by Simon Bosley on 05/08/2012.
//  Copyright (c) 2012 Simon Bosley. All rights reserved.
//

// Project headers
#include "opengl.h"
#include "scene.h"
#include "render2D.h"

// STL headers
#include <iostream>
#include <vector>

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

void createScene( Scene2D<GLdouble>& s );

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
    
    // Create the scene
    createScene( Render2D::scene );
    
    // Set the drawing function
    glutDisplayFunc( Render2D::redraw );
    
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

void createScene( Scene2D<GLdouble>& s )
{
    // let's create a square...
    SceneObject2D<GLdouble> object;
    Point2D<GLdouble> point;
    
    // top left
    point.x = 50;
    point.y = 50;
    object.points.push_back( point );
    
    // top right
    point.x = 250;
    point.y = 50;
    object.points.push_back( point );
    
    // bottom left
    point.x = 50;
    point.y = 250;
    object.points.push_back( point );
    
    // bottom right
    point.x = 250;
    point.y = 250;
    object.points.push_back( point );

    s.objects.push_back( object );
}

