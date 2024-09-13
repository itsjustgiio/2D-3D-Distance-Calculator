#include "Point2D.h"

bool Point2D::operator==(const Point2D &other) const
{
    return this->x == other.x && this->y == other.y; // Used to check if 2 2D points are the same
}
