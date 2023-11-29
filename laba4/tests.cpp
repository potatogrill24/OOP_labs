#include <gtest/gtest.h>
#include "src/farray.h"

TEST(test_1, creating_triangle) {
    Triangle<double> t;
    ASSERT_TRUE(t.getArea() == 0);
}

TEST(test_2, creating_hexagon) {
    Hexagon<double> h;
    ASSERT_TRUE(h.getArea() == 0);
}

TEST(test_3, creating_octagon) {
    Octagon<double> o;
    ASSERT_TRUE(o.getArea() == 0);
}

TEST(test_4, creating_triangle_with_points) {
    Point<double> t1(1, 1), t2(3, 1), t3(3, 3);
    Triangle<double> t(t1, t2, t3);
    ASSERT_TRUE(t.getArea() == 2);
}

TEST(test_5, creating_hexagon_with_points) {
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    Hexagon<double> h(h1, h2, h3, h4, h5, h6);
    ASSERT_TRUE(h.getArea() == 24);
}

TEST(test_6, creating_octagon_with_points) {
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    Octagon<double> o(o1, o2, o3, o4, o5, o6, o7, o8);
    ASSERT_TRUE(o.getArea() == 24);
}

TEST(test_7, creating_bad_triangle) {
    bool check;
    Point<double> t1(1, 0), t2(1, 0), t3(3, 2);
    try {
        Triangle<double> t(t1, t2, t3);
    }
    catch(std::exception &ex) {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_8, creating_bad_hexagon) {
    bool check;
    Point<double> h1(3, 1), h2(3, 1), h3(3, 1), h4(6, 7), h5(7, 4), h6(6, 1);
    try {
        Hexagon<double> h(h1, h2, h3, h4, h5, h6);
    }
    catch(std::exception &ex) {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_9, creating_bad_octagon) {
    bool check;
    Point<double> o1(4, 1), o2(4, 1), o3(4, 1), o4(4, 1), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    try {
        Octagon<double> o(o1, o2, o3, o4, o5, o6, o7, o8);
    }
    catch(std::exception &ex) {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_10, creating_shared_ptr_triangle) {
    Point<double> t1(1, 1), t2(3, 1), t3(3, 3);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Triangle<double>>(t1, t2, t3));
    ASSERT_TRUE(arr.get()->getArea() == 2);
}

TEST(test_11, creating_shared_ptr_hexagon) {
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6));
    ASSERT_TRUE(arr.get()->getArea() == 24);
}

TEST(test_12, creating_shared_ptr_octagon) {
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8));
    ASSERT_TRUE(arr.get()->getArea() == 24);
}

TEST(test_13, finding_shared_ptr_triangle_center) {
    Point<double> t1(6, 0), t2(12, 0), t3(9, 3);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Triangle<double>>(t1, t2, t3));
    Point<double> center = arr.get()->center();
    Point<double> exp_center(9, 1);
    ASSERT_TRUE(center.Equal(exp_center));
}

TEST(test_14, finding_shared_ptr_hexagon_center) {
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6));
    Point<double> center = arr.get()->center();
    Point<double> exp_center(4.5, 4);
    ASSERT_TRUE(center.Equal(exp_center));
}

TEST(test_15, finding_shared_ptr_octagon_center) {
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8));
    Point<double> center = arr.get()->center();
    Point<double> exp_center(4, 4);
    ASSERT_TRUE(center.Equal(exp_center));
}

TEST(test_16, copy_operator_shared_ptr_triangle) {
    Point<double> t1(1, 0), t2(3, 0), t3(3, 2);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Triangle<double>>(t1, t2, t3));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = arr;
    ASSERT_TRUE(arr_new.get()->getArea() == 2);
}

TEST(test_17, copy_operator_shared_ptr_hexagon) {
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = arr;
    ASSERT_TRUE(arr_new.get()->getArea() == 24);
}

TEST(test_18, copy_operator_shared_ptr_octagon) {
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = arr;
    ASSERT_TRUE(arr_new.get()->getArea() == 24);
}

TEST(test_19, move_operator_shared_ptr_triangle) {
    Point<double> t1(1, 0), t2(3, 0), t3(3, 2);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Triangle<double>>(t1, t2, t3));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = std::move(arr);
    ASSERT_TRUE(arr_new.get()->getArea() == 2);
}

TEST(test_20, move_operator_shared_ptr_hexagon) {
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = std::move(arr);
    ASSERT_TRUE(arr_new.get()->getArea() == 24);
}

TEST(test_21, move_operator_shared_ptr_octagon) {
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = std::move(arr);
    ASSERT_TRUE(arr_new.get()->getArea() == 24);
}

TEST(test_22, creating_figure_array) {
    Point<double> t1(1, 0), t2(3, 0), t3(3, 2);
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                        std::make_shared<Triangle<double>>(t1, t2, t3),
                        std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6),
                        std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8)
                        };
    ASSERT_TRUE(mega_arr.arr_size() == 3);
}

TEST(test_23, finding_triangle_center_and_area_from_figure_array) {
    Point<double> t1(0, 0), t2(6, 0), t3(3, 6);
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                        std::make_shared<Triangle<double>>(t1, t2, t3),
                        std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6),
                        std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8)
                        };
    Point<double> center(3, 2);
    ASSERT_TRUE(mega_arr[0].get()->center().Equal(center) && mega_arr[0].get()->getArea() == 18);
}

TEST(test_24, finding_hexagon_center_and_area_from_figure_array) {
    Point<double> t1(0, 0), t2(6, 0), t3(3, 6);
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                        std::make_shared<Triangle<double>>(t1, t2, t3),
                        std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6),
                        std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8)
                        };
    Point<double> center(4.5, 4);
    ASSERT_TRUE(mega_arr[1].get()->center().Equal(center) && mega_arr[1].get()->getArea() == 24);
}

TEST(test_25, finding_octagon_center_and_area_from_figure_array) {
    Point<double> t1(0, 0), t2(6, 0), t3(3, 6);
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                        std::make_shared<Triangle<double>>(t1, t2, t3),
                        std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6),
                        std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8)
                        };
    Point<double> center(4, 4);
    ASSERT_TRUE(mega_arr[2].get()->center().Equal(center) && mega_arr[2].get()->getArea() == 24);
}

TEST(test_26, finding_area_sum) {
    Point<double> t1(0, 0), t2(6, 0), t3(3, 6);
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                        std::make_shared<Triangle<double>>(t1, t2, t3),
                        std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6),
                        std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8)
                        };
    double expect_sum_area = 66;
    ASSERT_TRUE(mega_arr.sum_area() == expect_sum_area);
}

TEST(test_27, removing_figure_from_figure_array) {
    Point<double> t1(0, 0), t2(6, 0), t3(3, 6);
    Point<double> h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    Point<double> o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                        std::make_shared<Triangle<double>>(t1, t2, t3),
                        std::make_shared<Hexagon<double>>(h1, h2, h3, h4, h5, h6),
                        std::make_shared<Octagon<double>>(o1, o2, o3, o4, o5, o6, o7, o8)
                        };
    mega_arr.remove(2);
    ASSERT_TRUE(mega_arr.arr_size() == 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
