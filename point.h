#ifndef POINT_H
#define POINT_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define field1   7, 20
#define field5  19, 20
#define field9  19,  8
#define field11 25,  8
#define field15 25, 20
#define field19 27, 20
#define field21 37, 26
#define field25 25, 26
#define field29 25, 38
#define field31 19, 38
#define field35 29, 26
#define field39  7, 23

using namespace std;

class Point
{
public:
    Point(int x=0, int y=0);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    void setXY(int x, int y);
    void setLastLocation(int lastx, int lasty);
    int getLastLocation();
    void print() const;

    int lastx, lasty;




private:
    int x,y;
};

#endif // POINT_H
