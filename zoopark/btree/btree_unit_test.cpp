//
//  main.cpp
//  BTree
//
//  Created by Simon Bosley on 29/07/2012.
//  Copyright (c) 2012 Simon Bosley. All rights reserved.
//

#include <sstream>
#include <iostream>
#include "btree.h"

#ifdef TARGET_LINUX_OS
    #include <cstdlib>
#endif

int btree_unit_test()
{
    int test_ret_code = 0;
    
    // seed the random generator
    srand( (unsigned)time(0) );
    
    // Create some values to populate the tree with
    const int node_count = 10;
    
    // Create the root of the tree
    BTree<int>* root;
    
    // Create some nodes and add them to our tree
    for( int i = 0; i < node_count; ++i )
    {
        int value = rand() % node_count + 1;
        
        // If this is the first node then save it as the root, otherwise add it to the root
        if( i == 0 )
        {
            root = new BTree<int>( value );
        }
        else
        {
            AddNode( root, value );
        }
    }
    
    // Build a string stream for the tree
    std::stringstream ss;
    
    // Print the tree
    PrintTree( root, ss );
    
    // Wrap that value with a node for the tree
    std::cout << ss.str() << std::endl;
    
    BTree<std::string>* stringTree = new BTree<std::string>( "igor" );
    
    AddNode( stringTree, std::string("simon") );
    AddNode( stringTree, std::string("bob" ) );
    AddNode( stringTree, std::string("zak" ) );
    AddNode( stringTree, std::string("michael" ) );
    AddNode( stringTree, std::string("dawn" ) );
    
    ss.str( std::string() );
    ss.clear();
    
    PrintTree( stringTree, ss );
    
    // Wrap that value with a node for the tree
    std::cout << ss.str() << std::endl;
    
    return test_ret_code;
}

