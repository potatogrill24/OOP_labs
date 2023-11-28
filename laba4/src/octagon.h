#ifndef OCTAGON_H
#define OCTAGON_H
#include "figure.h"

template <class T>
class Octagon : public Figure<T> {
public:
    Octagon();
    Octagon(Point<T>& p_1, Point<T>& p_2, Point<T>& p_3, Point<T>& p_4, Point<T>& p_5, Point<T>& p_6, Point<T>& p_7, Point<T>& p_8);

    virtual T getArea() const override;
    virtual operator double() const override;

    Octagon<T>& operator=(Octagon<T>& other);
    Octagon<T>& operator=(Octagon<T>&& other);
    bool operator==(const Octagon<T>& other);

    ~Octagon(){
        this->n = 0;
        delete [] this->p;
        this->p = nullptr;
    }
};

template <class T>
Octagon<T>::Octagon () {
    this->n = 8;
    this->p = new Point<T>[this->n];
}

template <class T>
Octagon<T>::Octagon(Point<T>& p_1, Point<T>& p_2, Point<T>& p_3, Point<T>& p_4, Point<T>& p_5, Point<T>& p_6, Point<T>& p_7, Point<T>& p_8) {
    this->n = 8;
    this->p = new Point<T>[this->n];
    std::vector<Point<T>> ar;
    ar.push_back(p_1);
    ar.push_back(p_2);
    ar.push_back(p_3);
    ar.push_back(p_4);
    ar.push_back(p_5);
    ar.push_back(p_6);
    ar.push_back(p_7);
    ar.push_back(p_8);
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
    this->p[6] = p_7;
    this->p[7] = p_8;
}

template <class T>
T Octagon<T>::getArea() const {
    T area = 0;
    for (int i = 0; i < this->n; i++) {
        Point<T> p_x = this->p[i];
        Point<T> p_y = this->p[(i + 1) % this->n];
        area += p_x.x * p_y.y - p_y.x * p_x.y;
    }
    return 0.5 * abs(area);
}

template <class T>
bool Octagon<T>::operator==(const Octagon<T>& other) {
    return static_cast<T>(*this) == static_cast<T>(other);
}

template <class T>
Octagon<T>& Octagon<T>::operator=(Octagon<T>& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 8; i++) {
            this->p[i] = other.p[i];
        }
        this->n = other.n;
        delete [] other.p;
    }
    return *this;                      
}

template <class T>
Octagon<T>& Octagon<T>::operator=(Octagon<T>&& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 8; i++) {
            this->p[i] = std::move(other.p[i]);
        }
        this->n = other.n;
    }
    return *this;
}

template <class T>
Octagon<T>::operator double() const {
    return getArea();
}

#endif