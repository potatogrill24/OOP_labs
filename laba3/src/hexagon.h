#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure {
public:
    Hexagon();
    Hexagon(Point& p_1, Point& p_2, Point& p_3, Point& p_4, Point& p_5, Point& p_6);
    
    virtual double getArea() const override;
    virtual operator double() const override;

    Hexagon& operator=(Hexagon& other);
    Hexagon& operator=(Hexagon&& other);
    bool operator==(const Hexagon& other);

    ~Hexagon(){
        n = 0;
        delete [] p;
        p = nullptr;
    }
};

#endif