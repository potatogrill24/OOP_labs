#include <iostream>
#include "figure.h"

std::istream& operator>>(std::istream& is, Figure& figure) {
    for (int i = 0; i < figure.n; i++) {
        is >> figure.p[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, Figure *figure) {
    for (int i = 0; i < figure->n; i++) {
        os << i + 1 << ": " << figure->p[i] << std::endl;
    }
    return os;
}

Point Figure::center() const {
    double x_sum = 0, y_sum = 0;
    for (int i = 0; i < n; i++) {
        x_sum += p[i].x;
        y_sum += p[i].y;
    }
    return Point(x_sum / n, y_sum / n);
}

double orientation(Point& p1, Point& p2, Point& p3) {
    double val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) {
        return 0;
    }
    else if (val > 0) {
        return 1;
    }
    else {
        return 2;
    }
}

bool Figure::is_correct() {
    if (n < 3) {
        return false;
    }
    double OrientationVal = orientation(p[0], p[1], p[2]);
    for (int i = 1; i < n; i++) {
        int nextIdx = (i + 1) % n;
        if (OrientationVal != orientation(p[i], p[nextIdx], p[(nextIdx + 1) % n])) {
            return false;
        }
    }
    return true;
}