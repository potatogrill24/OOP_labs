#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"

typedef struct {
    Figure **arr;
    int size;
    int capacity;
} Farray;

Farray *create_arr();
void add_figure(Farray *arr, Figure& figure);
double sum_area(Farray *arr);
void increase_size(Farray *arr);
Figure **rm_figure(Farray *arr, int index);
void rm_arr(Farray *arr);