#include "eleven.h"

int main () {
    cout << "TEST SOME CONSTRUCTORS:" << endl;
    cout << "Default constructor:" << endl;
    Eleven a;
    cout << "Something created..." << endl;
    cout << "Second constructor:" << endl;
    Eleven second(5, 'A');
    second.print(cout);
    cout << endl;
    cout << "Third constructor:" << endl;
    Eleven third {'A', 'A', 'A', '8', '9'};
    third.print(cout);
    cout << endl;
    cout << "Fourth costructor:" << endl;
    Eleven fourth("AA865");
    fourth.print(cout);
    cout << endl;
    cout << "Fifth constructor:" << endl;
    Eleven fifth("AA");
    Eleven fifth_alternative(fifth);
    fifth_alternative.print(cout);
    cout << endl;
    cout << "Sixth constructor:" << endl;
    Eleven sixth(move(fifth_alternative));
    sixth.print(cout);

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "TEST SOME COMPARE FUNCTIONS:" << endl;
    cout << endl;

    cout << "1) Bigger than:" << endl;
    Eleven l_1("AAAAAAAA"), r_1("AAAAAAA9");
    cout << "left:";
    l_1.print(cout);
    cout << endl;
    cout << "right:";
    r_1.print(cout);
    cout << endl;
    try {
        bool result_2 = l_1.bigger(r_1);
        if (result_2) {
            cout << "left is bigger than right" << endl; 
        }
        else {
            cout << "left is not bigger than right" << endl;
        }
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
    cout << endl;

    cout << "2) Smaller than:" << endl;
    Eleven l_2("AAa819"), r_2("AAaaA99");
    cout << "left:";
    l_2.print(cout);
    cout << endl;
    cout << "right:";
    r_2.print(cout);
    cout << endl;
    try {
        bool result_1 = l_2.smaller(r_2);
        if (result_1) {
            cout << "left is smaller than right" << endl; 
        }
        else {
            cout << "left is not smaller than right" << endl;
        }
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
    cout << endl;

    cout << "3) Equal:" << endl;
    Eleven l_3("57291"), r_3("57291");
    cout << "left:";
    l_3.print(cout);
    cout << endl;
    cout << "right:";
    r_3.print(cout);
    cout << endl;
    try {
        bool result_3 = l_3.equal(r_3);
        if (result_3) {
            cout << "left and right are equal" << endl; 
        }
        else {
            cout << "left and right are not equal" << endl;
        }
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
    cout << endl;
    cout << endl;

    cout << "TEST SOME ARITHMETICS FUNCTIONS:" << endl;
    cout << endl;

    cout << "1) Addition:" << endl;
    Eleven l_4("A841A"), r_4("A7193");
    cout << "left:";
    l_4.print(cout);
    cout << endl;
    cout << "right:";
    r_4.print(cout);
    cout << endl;
    try {
        cout << "Result: ";
        l_4.addition(r_4).print(cout);
        cout << endl;
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
    cout << endl;
    cout << endl;

    cout << "2) Subtraction:" << endl;
    Eleven l_5("A8492"), r_5("88979");
    cout << "left:";
    l_5.print(cout);
    cout << endl;
    cout << "right:";
    r_5.print(cout);
    cout << endl;
    try {
        cout << "Result: ";
        l_5.subtraction(r_5).print(cout);
        cout << endl;
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
    cout << endl;

}