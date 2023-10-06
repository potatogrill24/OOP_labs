#pragma once

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Eleven {
public:
    Eleven();
    Eleven(const size_t & n, unsigned char t = 0);
    Eleven(const initializer_list< unsigned char> &t);
    Eleven(const string &t);
    Eleven(const Eleven& other);
    Eleven(Eleven&& other) noexcept;

    Eleven ten_to_el (size_t num);
    size_t el_to_ten() noexcept;

    bool bigger(const Eleven &other) const;
    bool smaller(const Eleven &other) const;
    bool equal(const Eleven& other) const;

    Eleven copy(const Eleven& other);
    Eleven addition(const Eleven& other);
    Eleven subtraction(const Eleven& other);

    ostream& print(ostream &os);

    virtual ~Eleven() noexcept;
private:
    size_t _size;
    unsigned char *_array;
};