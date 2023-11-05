#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, Point& p);
    friend Point operator+(const Point& l, const Point& r);
    friend Point operator-(const Point& l, const Point& r);

public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    bool Equal(const Point& other);
    bool NotEqual(const Point& other);
    Point& operator=(const Point& other);
    double x;
    double y;
};

#endif