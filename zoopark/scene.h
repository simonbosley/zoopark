//
//  scene.h
//  zoopark
//
//  Created by Simon Bosley on 12/08/2012.
//  Copyright (c) 2012 Simon Bosley. All rights reserved.
//

#ifndef zoopark_scene_h
#define zoopark_scene_h

#include <vector>

template <class T>
class Point2D
{
public:
    T x;
    T y;
};

template <class T>
class SceneObject2D
{
public:
    std::vector< Point2D<T> > points;
};

template <class T>
class Scene2D
{
public:
    std::vector< SceneObject2D<T> > objects;
};

#endif
