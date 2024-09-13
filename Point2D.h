#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <functional>

using namespace std;

struct Point2D
{   // Define the Point2D struct to represent a point in 2D space
    /***********
    The following method is inspired by JLBORGES

    https://cplusplus.com/forum/general/59326/

    and

    https://www.w3schools.com/cpp/cpp_structs.asp

    Accessed May 2024

    ***********/
    int x;
    int y;
    bool operator==(const Point2D &other) const; // This function is saying how to check if 2 points are equal.

    /**********
    The Follwing method was addapted by the Answer to the question on this page:

    https://stackoverflow.com/questions/65632067/how-to-use-overloaded-operator-to-check-if-2d-point-and-3d-point-are-identical

    Accessed May 2024

    **********/
};

/* -----
HashMaps and unordered_maps were suggest by ChatGPT

when prompted 'Is there an alternative to using an array for storing points and accessing them later?'
the generated text helped me write the following code:

Accessed: May 2024
 -------- */

template <>
struct hash<Point2D>
{ // Template allows us to use the hash function for Point2D. Since we can tell it what data type we are using, we can use the hash function for that data type.
    size_t operator()(const Point2D &point) const
    {
        return hash<int>()(point.x) ^ hash<int>()(point.y); // Basically for each and every point we are getting there key(address) and its values.

        // ^ is the bitwise XOR operator, which basically means that 2 keys(addresses) are becoming one new one. That way when it accesses the key, it will get the value or both x and y.
    }
};

#endif // POINT2D_H
