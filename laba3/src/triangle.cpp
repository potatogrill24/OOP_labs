#include "triangle.h"

Triangle::Triangle () {
    n = 3;
    p = new Point[n];
}

Triangle::Triangle (Point& p_1, Point& p_2, Point& p_3) {
    if (p_1.Equal(p_2)|| p_1.Equal(p_3) || p_2.Equal(p_3)) {
        throw std::logic_error("Points can't be simular!\n");
    }
    n = 3;
    p = new Point[n];
    p[0] = p_1;
    p[1] = p_2;
    p[2] = p_3;
}

double Triangle::getArea() const {
    if (n == 0) {
        return 0.0;
    }
    double x1, y1, x2, y2, x3, y3;
    x1 = p[0].x;
    y1 = p[0].y;
    x2 = p[1].x;
    y2 = p[1].y;
    x3 = p[2].x;
    y3 = p[2].y;

    double area = abs(0.5 * (((x1 * y2) - (y1 * x2)) + ((x2 * y3) - (y2 * x3)) + ((x3 * y1) - (y3 * x1))));
    return area;
}

bool Triangle::operator==(const Triangle& other) {
    return static_cast<double>(*this) == static_cast<double>(other);
}

Triangle& Triangle::operator=(Triangle& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 3; i++) {
            this->p[i] = other.p[i];
        }
        this->n = other.n;
    }
    return *this;                      
}

Triangle& Triangle::operator=(Triangle&& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 3; i++) {
            this->p[i] = std::move(other.p[i]);
        }
        this->n = other.n;
    }
    return *this;
}

Triangle::operator double() const {
    return getArea();
}

