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

// Project headers
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

	
