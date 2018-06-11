#include "point.h"

Point::Point(int x, int y): x(x), y(y){}

int Point::getX()const { return x;}
int Point::getY()const { return y;}

void Point::setX(int x){this->x =x;}
void Point::setY(int y){this->y =y;}

void Point::setXY(int x, int y){this->x =x, this->y = y;}
void Point::setLastLocation(int x, int y){this->lastx =x, this->lasty = y;}

int Point::getLastLocation(){return lastx, lasty;}


void Point::print() const {cout << "Point@" << x << " , " << y << endl; }
