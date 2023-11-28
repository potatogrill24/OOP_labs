#ifndef FIGURE_H
#define FIGURE_H
#include <stdexcept>
#include <cmath>
#include "point.h"
#include <vector>

template <typename T>

class Figure {
    template <class F>
    friend std::istream& operator>>(std::istream& is, Figure<F>& figure);
    template <class F>
    friend std::ostream& operator<<(std::ostream& os, Figure<F>& figure);

public:
    virtual T getArea() const = 0;

    virtual operator double() const = 0;

    Point<T> center() const;

    virtual ~Figure() = default;
protected:
    int n;
    Point<T> *p;
};

template <class T>
Point<T> Figure<T>::center() const {
    T x_sum = 0, y_sum = 0;
    for (int i = 0; i < n; i++) {
        x_sum += p[i].x;
        y_sum += p[i].y;
    }
    return Point<T>(x_sum / n, y_sum / n);
}

template <class T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) {
    for (int i = 0; i < figure.n; i++) {
        is >> figure.p[i];
    }
    return is;
}

template <class T>
std::ostream& operator<<(std::ostream& os, Figure<T>& figure) {
    for (int i = 0; i < figure.n; i++) {
        os << i + 1 << ": " << figure.p[i] << std::endl;
    }
    return os;
}

#endif