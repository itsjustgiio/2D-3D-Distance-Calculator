#include "Point3D.h"

bool Point3D::operator==(const Point3D &other) const
{
    return this->x == other.x && this->y == other.y && this->z == other.z; // Used to check if 2 3D points are the same
}
