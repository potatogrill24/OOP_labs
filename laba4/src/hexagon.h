#ifndef HEXAGON_H
#define HEXAGON_H
#include "figure.h"

template <class T>
class Hexagon : public Figure<T> {
public:
    Hexagon();
    Hexagon(Point<T>& p_1, Point<T>& p_2, Point<T>& p_3, Point<T>& p_4, Point<T>& p_5, Point<T>& p_6);

    virtual T getArea() const override;
    virtual operator double() const override;

    Hexagon<T>& operator=(Hexagon<T>& other);
    Hexagon<T>& operator=(Hexagon<T>&& other);
    bool operator==(const Hexagon<T>& other);

    ~Hexagon(){
        this->n = 0;
        delete [] this->p;
        this->p = nullptr;
    }
};

template <class T>
Hexagon<T>::Hexagon () {
    this->n = 6;
    this->p = new Point<T>[this->n];
}

template <class T>
Hexagon<T>::Hexagon(Point<T>& p_1, Point<T>& p_2, Point<T>& p_3, Point<T>& p_4, Point<T>& p_5, Point<T>& p_6) {
    this->n = 6;
    this->p = new Point<T>[this->n];
    std::vector<Point<T>> ar;
    ar.push_back(p_1);
    ar.push_back(p_2);
    ar.push_back(p_3);
    ar.push_back(p_4);
    ar.push_back(p_5);
    ar.push_back(p_6);
    for (int i = 0; i < ar.size(); i++) {
        for (int j = i + 1; j < ar.size(); j++) {
            if (ar[i].Equal(ar[j])) {
                throw std::logic_error("Points can't be simular!\n");
            }
        }
    }
    this->p[0] = p_1;
    this->p[1] = p_2;
    this->p[2] = p_3;
    this->p[3] = p_4;
    this->p[4] = p_5;
    this->p[5] = p_6;
}

template <class T>
T Hexagon<T>::getArea() const {
    T area = 0;
    for (int i = 0; i < this->n; i++) {
        Point<T> p_x = this->p[i];
        Point<T> p_y = this->p[(i + 1) % this->n];
        area += p_x.x * p_y.y - p_y.x * p_x.y;
    }
    return 0.5 * abs(area);
}

template <class T>
bool Hexagon<T>::operator==(const Hexagon<T>& other) {
    return static_cast<T>(*this) == static_cast<T>(other);
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 6; i++) {
            this->p[i] = other.p[i];
        }
        this->n = other.n;
        delete [] other.p;
    }
    return *this;                      
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 6; i++) {
            this->p[i] = std::move(other.p[i]);
        }
        this->n = other.n;
    }
    return *this;
}

template <class T>
Hexagon<T>::operator double() const {
    return getArea();
}

#endif