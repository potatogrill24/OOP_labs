#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
public:
    Triangle();
    Triangle(Point& p_1, Point& p_2, Point& p_3);

    virtual double getArea() const override;
    virtual operator double() const override;

    Triangle& operator=(Triangle& other);
    Triangle& operator=(Triangle&& other);
    bool operator==(const Triangle& other);

    ~Triangle(){
        n = 0;
        delete [] p;
        p = nullptr;
    }
};

#endif