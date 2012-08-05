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

// Mac OS X headers
#ifdef TARGET_OS_MAC
//#include <OpenGL/OpenGL.h>
//#include <OpenGL/glu.h>
//#include <GLUT/GLUT.h>
#endif

// Linux
#ifdef __linux__
//#include <GL/gl.h>
//#include <OpenGL/glut.h>
#endif

#ifdef _WIN32
// Windows Includes Here
#error Can't be compiled on Windows yet
#endif

#ifdef _WIN64
#error Can't be compiled on Windows yet
#endif

#include "opengl/opengl.h"
#include "btree/btree.h"

int main( int argc, char* argv[] )
{
	std::string greeting( "Starting zoopark..." );
	std::cout << greeting << std::endl;

	for( int i=1; i<argc; ++i )
	{
		std::cout << argv[i] << std::endl;
	}
    
    // test out some of our lovely data structures
    btree_unit_test();

    window( argc, argv );
    
    
    
	return 0;
}

	
