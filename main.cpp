#include <iostream>
#include <vector>
#include <tuple>
#include "Point2D.h"
#include "Point3D.h"
#include "PointOperations.h"

using namespace std;

int main()
{
    vector<Point2D> points2D; // Declaring the Vector for 2D Points
    vector<Point3D> points3D; // Declaring the Vector for 3D Points

    readFile("1m.txt", points2D, points3D); // Reading the data from the file and Storing it in the Vectors

    cout << "Number of 2D points: " << count2DPoints(points2D) << endl;                    // Outputting the number of 2D points
    cout << "Number of 3D points: " << count3DPoints(points3D) << endl;                    // Outputting the number of 3D points
    cout << "Number of duplicate 2D points: " << countDuplicate2DPoints(points2D) << endl; // Output of 2D dupes
    cout << "Number of duplicate 3D points: " << countDuplicate3DPoints(points3D) << endl; // Output of 3D dupes

    tuple<double, Point2D, Point2D> result2D = calculateMaxDistance2D(points2D); // Calculating the max distance between 2D points, in a turple

    /********
      The idea for using a tuple came from https://youtu.be/T9-agjKW4PQ?si=jxVSbWHwWmhxiVtb

      Accessed May, 2024
      *************/

    double maxDistance2D = get<0>(result2D); // Get Max distance from the tuple
    Point2D point1_2D = get<1>(result2D);    // Get the first point from the tuple
    Point2D point2_2D = get<2>(result2D);    // Get the second point from the tuple

    cout << "Farthest distance between two 2D points: " << maxDistance2D << endl; // Print Max Distance
    cout << "The 2D Points: (" << point1_2D.x << ", " << point1_2D.y << ") and (" << point2_2D.x << ", " << point2_2D.y << ")" << endl;
    // point1_2D.x prints the x coordinate of the first 2D point.
    // point1_2D.y prints the y coordinate of the first 2D point.
    // point1 is the smaller and point2 is the larger.

    // The Following is basically the same as the above, but for 3D points
    tuple<double, Point3D, Point3D> result3D = calculateMaxDistance3D(points3D);
    double maxDistance3D = get<0>(result3D);
    Point3D point1_3D = get<1>(result3D);
    Point3D point2_3D = get<2>(result3D);

    cout << "Farthest distance between two 3D points: " << maxDistance3D << endl;
    cout << "The 3D Points: (" << point1_3D.x << ", " << point1_3D.y << ", " << point1_3D.z << ") and (" << point2_3D.x << ", " << point2_3D.y << ", " << point2_3D.z << ")" << endl;

    return 0;
}
// Bye :)