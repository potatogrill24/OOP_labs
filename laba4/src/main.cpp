#include "farray.h"

int main() {
    std::cout << "Creating all types of shared_ptr figures:\n" << std::endl;

    std::cout << "Triangle:\n" << std::endl;
    Point<double> t1(1, 1), t2(3, 1), t3(3, 3);
    std::shared_ptr<Figure<double>> arr1(std::make_shared<Triangle<double>>(t1, t2, t3));
    std::cout << *arr1 << std::endl;
    Point<double> c1 = arr1.get()->center();
    std::cout << "Triangle center is " << c1 << std::endl;
    std::cout << std::endl; 

    std::cout << "Hexagon:\n" << std::endl;
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    std::shared_ptr<Figure<double>> arr2(std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6));
    std::cout << *arr2 << std::endl;
    Point<double> c2 = arr2.get()->center();
    std::cout << "Hexagon center is " << c2 << std::endl;
    std::cout << std::endl;

    std::cout << "Octagon:\n" << std::endl;
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    std::shared_ptr<Figure<double>> arr3(std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8));
    std::cout << *arr3 << std::endl;
    Point<double> c3 = arr3.get()->center();
    std::cout << "Octagon center is " << c3 << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Creating array containing all figure types simultaneously:\n" << std::endl;
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                            std::make_shared<Triangle<double>>(t1, t2, t3),
                            std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6),
                            std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8)
                            };

    for (int i = 0; i < mega_arr.arr_size(); i++) {
        std::cout << *mega_arr[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Getting area of each figure in array:\n" << std::endl;
    for (int i = 0; i < mega_arr.arr_size(); i++) {
        std::cout << mega_arr[i].get()->getArea() << std::endl << std::endl;
    }

    std::cout << "Getting the sum of the ares of all the figures from array:\n" << std::endl;
    double sum = mega_arr.sum_area();
    std::cout << sum << std::endl;

    std::cout << std::endl;
    std::cout << "Removing second figure from array:\n" << std::endl;
    mega_arr.remove(1);
    
    std::cout << "Quantity of figures after removing: " << mega_arr.arr_size() << std::endl;
    std::cout << "Figures remaining in the array:\n" << std::endl;
    for (int i = 0; i < mega_arr.arr_size(); i++) {
        std::cout << *mega_arr[i] << std::endl;
    }
    
    return 0;
}
