//
//  render2D.h
//  zoopark
//
//  Created by Simon Bosley on 15/08/2012.
//  Copyright (c) 2012 Simon Bosley. All rights reserved.
//

#ifndef zoopark_render2D_h
#define zoopark_render2D_h

// Mac OS X headers
#ifdef TARGET_MAC_OS
#include <GLUT/GLUT.h>
#endif

// Linux headers
#ifdef TARGET_LINUX_OS
#include <GL/freeglut_std.h>
#endif

class Render2D
{
public:
    static Scene2D<GLdouble> scene;
    
    static void redraw()
    {
        // Clears the colour
        glClear( GL_COLOR_BUFFER_BIT );
        
        // Loop through the scene onbjects
        std::vector<SceneObject2D<GLdouble > >::iterator itO = scene.objects.begin();
        std::vector<SceneObject2D<GLdouble > >::iterator itOEnd = scene.objects.end();
        
        for( ; itO != itOEnd; ++itO )
        {
            // Draw the points of our object
            std::vector<Point2D<GLdouble > >::iterator itP = itO->points.begin();
            std::vector<Point2D<GLdouble > >::iterator itPEnd = itO->points.end();
            
            // Draw the current point
            glBegin( GL_POINTS );
            
            for( ; itP != itPEnd; ++itP )
                glVertex2d( GLdouble( itP->x + 0.5 ), GLdouble( itP->y + 0.5 ) );
            
            glEnd();
        }
        
        // Send the output to the screen
        glutSwapBuffers();
    }
};

Scene2D<GLdouble> Render2D::scene;

#endif
