#ifndef FIGURE_H
#define FIGURE_H


#include <iostream>
#include <stdexcept>
#include <cmath>
#include "point.h"
#include <vector>

class Figure {

    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, Figure *figure);

public:
    virtual double getArea() const = 0;
    virtual operator double() const = 0;
    Point center() const;
    bool is_correct();
    virtual ~Figure() = default;
protected:
    int n;
    Point *p;
};

#endif