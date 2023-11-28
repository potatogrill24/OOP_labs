#include <memory>
#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"

template <class T>
class Array {

private:
    int size;
    std::shared_ptr<T[]> arr;

public:
    Array() {
        size = 0;
        arr = nullptr;
    }

    Array(const std::initializer_list<T> &list) {
        arr = std::shared_ptr<T[]>(new T[list.size()]);
        int i = 0;
        for (auto &c : list) {
            arr[i++] = c; 
        }
        size = list.size();
    }

    Array(const Array &other) {
        size = other.size;
        arr = std::shared_ptr<T[]>(new T[size]);
        for (int i = 0; i < size; i++) {
            arr[i] = other[i];
        }
    }

    Array(Array &&other) {
        size = other.size;
        arr = other.arr;

        other.size = 0;
        other.arr = nullptr;
    }

    T& operator[](int index) {
        if (index >= this->size || index < 0) {
            throw std::logic_error("Wrong index");
        }
        return arr[index];
    }

    void remove(int index) {
        if (index >= this->size || index < 0) {
            throw std::logic_error("Wrong index");
        }
        std::shared_ptr<T[]> new_arr = std::shared_ptr<T[]>(new T[this->size - 1]);
        int mover = 0;
        for (int i = 0; i < this->size; i++) {
            if (i == index) {
                mover = 1;
                continue;
            }
            new_arr[i - mover] = arr[i];
        }
        this->size--;
        this->arr = new_arr;
    }

    int arr_size() {
        return size;
    }

    ~Array() {
        size = 0;
        for (int i = 0; i < size; i++) {
            delete arr[i].get();
        }
        arr = nullptr;
    }

    double sum_area() {
        double sum;
        for (int i = 0; i < this->size; i++) {
            sum += this->arr[i].get()->getArea();
        }
        return sum;
    }

};
