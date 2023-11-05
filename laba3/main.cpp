#include <iostream>
#include "src/farray.h"

int main () {
    Farray *array = create_arr();

    std::cout << "Треугольник:" << std::endl;
    Point t1(1, 1), t2(3, 1), t3(3, 3);
    Triangle triang(t1, t2, t3);
    if (triang.is_correct()) {
        add_figure(array, triang);
        std::cout << "Площадь:" << std::endl;
        std::cout << array->arr[0]->getArea() << std::endl;
        std::cout << "Текущая сумма площадей:" << std::endl;
        std::cout << sum_area(array) << std::endl;
        Point с(array->arr[0]->center());
        std::cout << "Центр треугольника: " << с << std::endl;
    }
    else {
        std::cout << "Некорректная фигура!" << std::endl;
        return 1;
    }
    std::cout << std::endl;

    std::cout << "Шестиугольник:" << std::endl;
    Point h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    Hexagon hex(h1, h2, h3, h4, h5, h6);
    if (hex.is_correct()) {
        add_figure(array, hex);
        std::cout << "Площадь:" << std::endl;
        std::cout << array->arr[1]->getArea() << std::endl;
        std::cout << "Текущая сумма площадей:" << std::endl;
        std::cout << sum_area(array) << std::endl;
        Point c_1(array->arr[1]->center());
        std::cout << "Центр шестиугольника: " << c_1 << std::endl;
    }
    else {
        std::cout << "Некорректная фигура!" << std::endl;
        return 1;
    }
    std::cout << std::endl;
    
    std::cout << "Восьмиугольник:" << std::endl;
    Point o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    Octagon oct(o1, o2, o3, o4, o5, o6, o7, o8);
    if (oct.is_correct()) {
        add_figure(array, oct);
        std::cout << "Площадь:" << std::endl;
        std::cout << array->arr[2]->getArea() << std::endl;
        std::cout << "Текущая сумма площадей:" << std::endl;
        std::cout << sum_area(array) << std::endl;
        Point c_3(array->arr[2]->center());
        std::cout << "Центр восьмиугольника: " << c_3 << std::endl;
    }
    else {
        std::cout << "Некорректная фигура!" << std::endl;
        return 1;
    }
    std::cout << std::endl;
    
    std::cout << "Фигуры в текущем массиве:" << std::endl;
    for (int i = 0; i < array->size; i++) {
        std::cout << array->arr[i] << std::endl;
    }
    
    //удаление 1-го элемента массива
    std::cout << "Массив после удаления 1-го элемента (треугольника):" << std::endl;
    array->arr = rm_figure(array, 0);
    array->size--;
    int s = array->size;
    for (int i = 0; i < s; i++) {
        std::cout << array->arr[i] << std::endl;
    }

    std::cout << "Текущая сумма площадей:" << std::endl;
    std::cout << sum_area(array) << std::endl;
    rm_arr(array);

    // Point j1(6, 0), j2(12, 0), j3(9, 3);
    // Triangle tr(j1, j2, j3);
    // Point c9(tr.center());
    // std::cout << c9 << std::endl;
}