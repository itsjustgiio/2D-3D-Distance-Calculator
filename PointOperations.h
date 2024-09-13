#ifndef POINTOPERATIONS_H
#define POINTOPERATIONS_H

#include <vector>
#include <tuple>
#include "Point2D.h"
#include "Point3D.h"

using namespace std;

void readFile(const string &filename, vector<Point2D> &points2D, vector<Point3D> &points3D);
int count2DPoints(const vector<Point2D> &points2D);                                      // Function for counting 2D points
int count3DPoints(const vector<Point3D> &points3D);                                      // Function for counting 3D points
int countDuplicate2DPoints(const vector<Point2D> &points2D);                             // Function for counting duplicate 2D points
int countDuplicate3DPoints(const vector<Point3D> &points3D);                             // Function for counting duplicate 3D points
tuple<double, Point2D, Point2D> calculateMaxDistance2D(const vector<Point2D> &points2D); // Function for calculating maximum distance between 2D points
tuple<double, Point3D, Point3D> calculateMaxDistance3D(const vector<Point3D> &points3D); // Functon for calculating maximum distance between 3D points

#endif // POINTOPERATIONS_H
