//
//  btree.h
//  BTree
//
//  Created by Simon Bosley on 29/07/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef BTree_btree_h
#define BTree_btree_h

//
//  btree.cpp
//  BTree
//
//  Created by Simon Bosley on 29/07/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include <string>
#include <sstream>
#include "btree.h"

int btree_unit_test();

//
// Create a BTree
//

template <class T>
class BTree
{
    // member functions
public:
    BTree( T v )
    {
        value = v;
        lhs = 0;
        rhs = 0;
    }
    
    // member variables
public:
    BTree* lhs;
    BTree* rhs;
    T value;
};

template <class T>
void AddNode( BTree<T>* node, T value );

template <class T>
void AddNode( BTree<T>* node, T value )
{
    // If it's less than this node go left, else go right
    if( value < node->value )
    {
        if( node->lhs != 0 )
        {
            AddNode( node->lhs, value );
        }
        else
        {
            node->lhs = new BTree<T>( value );
        }
    }
    else
    {
        if ( node->rhs != 0 )
        {
            AddNode( node->rhs, value );
        }
        else
        {
            node->rhs = new BTree<T>( value );
        }
    }
}
   
// Printing a tree node
template <class T>
std::string ToString( BTree<T>& node, std::stringstream& ss );

template <class T>
std::string ToString( BTree<T>& node, std::stringstream& ss )
{
    ss << node.value << " ";
    return ss.str();
}

// Printing a tree
template <class T>
void PrintTree( BTree<T>* node, std::stringstream& ss );

template <class T>
void PrintTree( BTree<T>* node, std::stringstream& ss )
{
    if( node->lhs != 0 )
    {
        PrintTree( node->lhs, ss );
    }
    
    ToString( *node, ss );
    
    if ( node->rhs != 0 )
    {
        PrintTree( node->rhs, ss );
    }
}

#endif