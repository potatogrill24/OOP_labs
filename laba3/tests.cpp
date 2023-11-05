#include <gtest/gtest.h>
#include "src/farray.h"

TEST(test_1, create_triangle) {
    Triangle triangle;
    ASSERT_TRUE(triangle.is_correct());
}

TEST(test_2, create_hexagon) {
    Hexagon hex;
    ASSERT_TRUE(hex.is_correct());
}

TEST(test_3, create_octagon) {
    Octagon oct;
    ASSERT_TRUE(oct.is_correct());
}

TEST(test_4, create_triangle_with_points) {
    Point p1(1, 1), p2(3, 1), p3(3, 3);
    Triangle triangle(p1, p2, p3);
    ASSERT_TRUE(triangle.is_correct());
}

TEST(test_5, create_octagon_with_points) {
    Point h1(3, 1), h2(2, 4), h3(3, 7), h4(6, 7), h5(7, 4), h6(6, 1);
    Hexagon hex(h1, h2, h3, h4, h5, h6);
    ASSERT_TRUE(hex.is_correct());
}

TEST(test_6, create_octagon_with_points) {
    Point o1(4, 1), o2(2, 2), o3(1, 4), o4(2, 6), o5(4, 7), o6(6 ,6), o7(7, 4), o8(6, 2);
    Octagon oct(o1, o2, o3, o4, o5, o6, o7, o8);
    ASSERT_TRUE(oct.is_correct());
}

TEST(test_7, create_bad_triangle_with_points) {
    Point p1(0, 0), p2(0, 0), p3(0, 0);
    bool check = true;
    try {
        Triangle triangle(p1, p2, p3);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_8, create_bad_hexagon_with_points) {
    Point p1(0, 0), p2(0, 0), p3(0, 0), p4(1, 1), p5(1, 2), p6(1, 3);
    bool check = true;
    try {
        Hexagon hex(p1, p2, p3, p4, p5, p6);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_9, create_bad_octagon_with_points) {
    Point p1(0, 0), p2(0, 0), p3(0, 0), p4(1, 1), p5(1, 2), p6(1, 3), p7(9, 1), p8(1, 0);
    bool check = true;
    try {
        Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_10, find_triangle_center) {
    Point p1(6, 0), p2(12, 0), p3(9, 3);
    Triangle triangle(p1, p2, p3);
    Point center = triangle.center();
    Point exp_center(9, 1);
    ASSERT_TRUE(center.Equal(exp_center));
}

TEST(test_11, find_hexagon_center) {
    Point p1(8, 0), p2(6, 1), p3(6, 3), p4(8, 4), p5(10, 3), p6(10, 1);
    Hexagon hex(p1, p2, p3, p4, p5, p6);
    Point center = hex.center();
    Point exp_center(8, 2);
    ASSERT_TRUE(center.Equal(exp_center));
}

TEST(test_12, find_octagon_center) {
    Point p1(8, 0), p2(6, 1), p3(5, 3), p4(6, 5), p5(8, 6), p6(10, 5), p7(11, 3), p8(10, 1);
    Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    Point center = oct.center();
    Point exp_center(8, 3);
    ASSERT_TRUE(center.Equal(exp_center));
}

TEST(test_13, find_triangle_area) {
    Point p1(6, 0), p2(12, 0), p3(9, 3);
    Triangle triangle(p1, p2, p3);
    double area = triangle.getArea();
    double exp_area = 9.0;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_14, find_hexagon_area) {
    Point p1(8, 0), p2(6, 1), p3(6, 3), p4(8, 4), p5(10, 3), p6(10, 1);
    Hexagon hex(p1, p2, p3, p4, p5, p6);
    double area = hex.getArea();
    double exp_area = 12;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_15, find_octagon_area) {
    Point p1(8, 0), p2(6, 1), p3(5, 3), p4(6, 5), p5(8, 6), p6(10, 5), p7(11, 3), p8(10, 1);
    Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    double area = oct.getArea();
    double exp_area = 24;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_16, copy_operator_triangle) {
    Point p1(6, 0), p2(12, 0), p3(9, 3);
    Triangle triangle1(p1, p2, p3);
    Triangle triangle2;
    triangle2 = triangle1;
    ASSERT_TRUE((triangle1 == triangle2) and (triangle1.center().Equal(triangle2.center())) and (triangle1.getArea() == triangle2.getArea()));
}

TEST(test_17, move_operator_triangle) {
    Point p1(6, 0), p2(12, 0), p3(9, 3);
    Triangle triangle1(p1, p2, p3);
    Triangle triangle2;
    triangle2 = std::move(triangle1);
    ASSERT_TRUE((triangle1 == triangle2) and (triangle1.center().Equal(triangle2.center())) and (triangle1.getArea() == triangle2.getArea()));
}

TEST(test_18, copy_operator_hexagon) {
    Point p1(8, 0), p2(6, 1), p3(6, 3), p4(8, 4), p5(10, 3), p6(10, 1);
    Hexagon hex1(p1, p2, p3, p4, p5, p6);
    Hexagon hex2;
    hex2 = hex1;
    ASSERT_TRUE((hex1 == hex2) and (hex1.center().Equal(hex2.center())) and (hex1.getArea() == hex2.getArea()));
}

TEST(test_19, move_operator_hexagon) {
    Point p1(8, 0), p2(6, 1), p3(6, 3), p4(8, 4), p5(10, 3), p6(10, 1);
    Hexagon hex1(p1, p2, p3, p4, p5, p6);
    Hexagon hex2;
    hex2 = std::move(hex1);
    ASSERT_TRUE((hex1 == hex2) and (hex1.center().Equal(hex2.center())) and (hex1.getArea() == hex2.getArea()));
}

TEST(test_20, copy_operator_octagon) {
    Point p1(8, 0), p2(6, 1), p3(5, 3), p4(6, 5), p5(8, 6), p6(10, 5), p7(11, 3), p8(10, 1);
    Octagon oct1(p1, p2, p3, p4, p5, p6, p7, p8);
    Octagon oct2;
    oct2 = oct1;
    ASSERT_TRUE((oct1 == oct2) and (oct1.center().Equal(oct2.center())) and (oct1.getArea() == oct2.getArea()));
}

TEST(test_21, move_operator_octagon) {
    Point p1(8, 0), p2(6, 1), p3(5, 3), p4(6, 5), p5(8, 6), p6(10, 5), p7(11, 3), p8(10, 1);
    Octagon oct1(p1, p2, p3, p4, p5, p6, p7, p8);
    Octagon oct2;
    oct2 = std::move(oct1);
    ASSERT_TRUE((oct1 == oct2) and (oct1.center().Equal(oct2.center())) and (oct1.getArea() == oct2.getArea()));
}

TEST(test_22, Figure_array_add) {
    Point t1(6, 0), t2(12, 0), t3(9, 3);
    Triangle trg(t1, t2, t3);

    Point h1(8, 0), h2(6, 1), h3(6, 3), h4(8, 4), h5(10, 3), h6(10, 1);
    Hexagon hex(h1, h2, h3, h4, h5, h6);

    Point o1(8, 0), o2(6, 1), o3(5, 3), o4(6, 5), o5(8, 6), o6(10, 5), o7(11, 3), o8(10, 1);
    Octagon oct(o1, o2, o3, o4, o5, o6, o7, o8);

    Farray *far = create_arr();
    add_figure(far, trg);
    add_figure(far, hex);
    add_figure(far, oct);
    ASSERT_TRUE(far->size == 3);
}

TEST(test_23, Figure_array_sum_area) {
    Point t1(6, 0), t2(12, 0), t3(9, 3);
    Triangle trg(t1, t2, t3);

    Point h1(8, 0), h2(6, 1), h3(6, 3), h4(8, 4), h5(10, 3), h6(10, 1);
    Hexagon hex(h1, h2, h3, h4, h5, h6);

    Point o1(8, 0), o2(6, 1), o3(5, 3), o4(6, 5), o5(8, 6), o6(10, 5), o7(11, 3), o8(10, 1);
    Octagon oct(o1, o2, o3, o4, o5, o6, o7, o8);

    Farray *far = create_arr();
    add_figure(far, trg);
    add_figure(far, hex);
    add_figure(far, oct);
    ASSERT_TRUE(sum_area(far) == 45);
}

TEST(test_24, Figure_array_rm_figure) {
    Point t1(6, 0), t2(12, 0), t3(9, 3);
    Triangle trg(t1, t2, t3);

    Point h1(8, 0), h2(6, 1), h3(6, 3), h4(8, 4), h5(10, 3), h6(10, 1);
    Hexagon hex(h1, h2, h3, h4, h5, h6);

    Point o1(8, 0), o2(6, 1), o3(5, 3), o4(6, 5), o5(8, 6), o6(10, 5), o7(11, 3), o8(10, 1);
    Octagon oct(o1, o2, o3, o4, o5, o6, o7, o8);

    Farray *far = create_arr();
    add_figure(far, trg);
    add_figure(far, hex);
    add_figure(far, oct);
    far->arr = rm_figure(far, 0);
    far->size--;
    ASSERT_TRUE(far->size == 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}