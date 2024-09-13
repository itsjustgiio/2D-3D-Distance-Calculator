#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>
#include <functional>

// Same comments as the one in Point2D.h

using namespace std;

struct Point3D
{
    int x;
    int y;
    int z;
    bool operator==(const Point3D &other) const;
};

template <>
struct hash<Point3D>
{
    size_t operator()(const Point3D &point) const
    {
        return hash<int>()(point.x) ^ hash<int>()(point.y) ^ hash<int>()(point.z);
    }
};

#endif // POINT3D_H
