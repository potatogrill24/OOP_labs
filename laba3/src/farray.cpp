#include "farray.h"

Farray *create_arr() {
    Farray *arr = new Farray;
    arr->arr = new Figure* [10];
    arr->size = 0;
    arr->capacity = 10;
    return arr;
}

void increase_size(Farray *arr) {
    Figure **new_arr = new Figure* [arr->capacity + 10];
    for (int i = 0; i < arr->size; i++) {
        new_arr[i] = arr->arr[i];
    }
    delete [] arr->arr;
    arr->arr = new_arr;
    arr->capacity += 10;
}

void add_figure(Farray* arr, Figure& figure) {
    if (arr->size == arr->capacity) {
        increase_size(arr);
    }
    arr->arr[arr->size] = &figure;
    arr->size++;
}

double sum_area(Farray *arr) {
    double sum = 0;
    for (int i = 0; i < arr->size; i++) {
        sum += arr->arr[i]->getArea();
    }
    return sum;
}

Figure **rm_figure(Farray *arr, int index) {
    Figure **new_arr = new Figure* [arr->capacity];
    int flag = 0;
    for (int i = 0; i < arr->size; i++) {
        if (i == index) {
            flag = 1;
            continue;
        }
        new_arr[i - flag] = arr->arr[i];
    }
    delete [] arr->arr;
    return new_arr;
}

void rm_arr(Farray *arr) {
    arr->capacity = 0;
    arr->size = 0;
    delete [] arr->arr;
    arr->arr = nullptr;
    delete [] arr;
    arr = nullptr;
}