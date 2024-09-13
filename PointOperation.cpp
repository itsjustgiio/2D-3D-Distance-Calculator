#include "PointOperations.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <cmath>

using namespace std;

void readFile(const string &filename, vector<Point2D> &points2D, vector<Point3D> &points3D)
{ // Function to read data from a file
    ifstream file("1m.txt");
    ; // Open the test file
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    } // If the File cant open, it will print "Error opening file"

    string line; // String to hold each line from the file

    while (getline(file, line))
    { // Loop through each line in the file

        stringstream stringContents(line); // stringstream to extract values from the line

        // Variables to hold extracted values
        string extract;
        int x;
        int y;
        int z;
        char ch;

        // Extract values from the line that arent the X or Y coordinates
        stringContents >> extract;
        stringContents >> ch;
        stringContents >> x;
        stringContents >> ch;
        stringContents >> extract;
        stringContents >> ch;
        stringContents >> y;

        if (stringContents >> ch >> extract >> ch >> z)
        { // If there is 3 variables then push into 3D vector
            points3D.push_back({x, y, z});
        }
        else
        { // Else Push into 2D vector
            points2D.push_back({x, y});
        }
    }

    file.close();
}

int count2DPoints(const vector<Point2D> &points2D)
{
    return points2D.size(); // Outputting how many 2D points there are
}

int count3DPoints(const vector<Point3D> &points3D)
{
    return points3D.size(); // Outputting how many 3D points there are
}

int countDuplicate2DPoints(const vector<Point2D> &points2D)
{
    /********
    This code was adapted from the Answers in:

    https://stackoverflow.com/questions/46084249/finding-repeated-points-in-2d-plane

    AND

    https://stackoverflow.com/questions/40320455/comparing-unordered-map-vs-unordered-set

    Insight: We wanted to properly count the duplicates without recounting duplicated points, and came across the unordered_map and unordered_set method on stackoverflow and just used it because intiially the duplicate count didn't output correct amount.

    Accessed May 2024
    *********/

    unordered_map<Point2D, int> freq; // Create an unordered_map to count the frequency of each Point2D

    for (const auto &point : points2D)
    {                  // Iterate through each point in the points2D vector
        freq[point]++; // Increment the count for this point in the frequency map
    }

    int duplicateCount = 0; // Initializing the counter for duplicate points
    for (const auto &entry : freq)
    {
        if (entry.second > 1)
        { // Checks the Frequency Count, if it is greater than 1, then it is a duplicate
            duplicateCount++;
        }
    }

    return duplicateCount;
}

int countDuplicate3DPoints(const vector<Point3D> &points3D)
{
    unordered_map<Point3D, int> freq;

    for (const auto &point : points3D)
    {
        freq[point]++; // Increment the count for this point in the frequency map
    }

    int duplicateCount = 0; // Initializing the counter for duplicate points
    for (const auto &entry : freq)
    { // Checks the Frequency Count, if it is greater than 1, then it is a duplicate
        if (entry.second > 1)
        {
            duplicateCount++;
        }
    }

    return duplicateCount;
}

tuple<double, Point2D, Point2D> calculateMaxDistance2D(const vector<Point2D> &points2D)
{ // Function to calculate the maximum distance between two points in 2D space
    double maxDistance = 0.0;
    Point2D point1;
    Point2D point2;

    for (size_t i = 0; i < points2D.size(); ++i)
    { // Loop for all points in the 2D vector
        for (size_t j = i + 1; j < points2D.size(); ++j)
        {
            double distance = sqrt(pow(points2D[i].x - points2D[j].x, 2) + pow(points2D[i].y - points2D[j].y, 2)); // Calculate distance between two points (distance forumla)

            if (distance > maxDistance)
            { // If the calculated distance is greater than the current maximum distance, update maxDistance and the corresponding points
                maxDistance = distance;
                point1 = points2D[i];
                point2 = points2D[j];
            }
        }
    }

    return make_tuple(maxDistance, point1, point2); // Return the data
}

tuple<double, Point3D, Point3D> calculateMaxDistance3D(const vector<Point3D> &points3D)
{ // Function to calculate the maximum distance between two points in 3D space

    double maxDistance = 0.0;
    Point3D point1;
    Point3D point2;

    for (size_t i = 0; i < points3D.size(); ++i)
    {
        for (size_t j = i + 1; j < points3D.size(); ++j)
        { // Calculate distance between two points in 3D space
            double distance = sqrt(pow(points3D[i].x - points3D[j].x, 2) +
                                   pow(points3D[i].y - points3D[j].y, 2) +
                                   pow(points3D[i].z - points3D[j].z, 2));
            if (distance > maxDistance)
            { // If the calculated distance is greater than the current maximum distance, update maxDistance and the corresponding points
                maxDistance = distance;
                point1 = points3D[i];
                point2 = points3D[j];
            }
        }
    }

    return make_tuple(maxDistance, point1, point2); // Return the data
}
