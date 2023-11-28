#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"

template <class T>
class Triangle : public Figure<T> {
public:
    Triangle();
    Triangle(Point<T>& p_1, Point<T>& p_2, Point<T>& p_3);

    virtual T getArea() const override;
    virtual operator double() const override;

    Triangle<T>& operator=(Triangle<T>& other);
    Triangle<T>& operator=(Triangle<T>&& other);
    bool operator==(const Triangle<T>& other);

    ~Triangle(){
        this->n = 0;
        delete [] this->p;
        this->p = nullptr;
    }
};

template <class T>
Triangle<T>::Triangle () {
    this->n = 3;
    this->p = new Point<T>[this->n];
}

template <class T>
Triangle<T>::Triangle(Point<T>& p_1, Point<T>& p_2, Point<T>& p_3) {
    if (p_1.Equal(p_2)|| p_1.Equal(p_3) || p_2.Equal(p_3)) {
        throw std::logic_error("Points can't be simular!\n");
    }
    this->n = 3;
    this->p = new Point<T>[this->n];
    this->p[0] = p_1;
    this->p[1] = p_2;
    this->p[2] = p_3;
}

template <class T>
T Triangle<T>::getArea() const {
    if (this->n == 0) {
        return 0.0;
    }
    T x1, y1, x2, y2, x3, y3;
    x1 = this->p[0].x;
    y1 = this->p[0].y;
    x2 = this->p[1].x;
    y2 = this->p[1].y;
    x3 = this->p[2].x;
    y3 = this->p[2].y;

    T area = abs(0.5 * (((x1 * y2) - (y1 * x2)) + ((x2 * y3) - (y2 * x3)) + ((x3 * y1) - (y3 * x1))));
    return area;
}

template <class T>
bool Triangle<T>::operator==(const Triangle<T>& other) {
    return static_cast<T>(*this) == static_cast<T>(other);
}

template <class T>
Triangle<T>& Triangle<T>::operator=(Triangle<T>& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 3; i++) {
            this->p[i] = other.p[i];
        }
        this->n = other.n;
        delete [] other.p;
    }
    return *this;                      
}

template <class T>
Triangle<T>& Triangle<T>::operator=(Triangle<T>&& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 3; i++) {
            this->p[i] = std::move(other.p[i]);
        }
        this->n = other.n;
    }
    return *this;
}

template <class T>
Triangle<T>::operator double() const {
    return getArea();
}

#endif