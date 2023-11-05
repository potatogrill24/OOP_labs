#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

class Octagon : public Figure {
public:
    Octagon();
    Octagon(Point& p_1, Point& p_2, Point& p_3, Point& p_4, Point& p_5, Point& p_6, Point& p_7, Point& p_8);
    
    virtual double getArea() const override;
    virtual operator double() const override;

    Octagon& operator=(Octagon& other);
    Octagon& operator=(Octagon&& other);
    bool operator==(const Octagon& other);

    ~Octagon() {
        n = 0;
        delete [] p;
        p = nullptr;
    }
};

#endif