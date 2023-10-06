#include "eleven.h"

Eleven::Eleven(): _size(0), _array{nullptr} {}

Eleven::Eleven(const size_t &n, unsigned char t) {
    if (n == 0) {
        throw logic_error("array can't has size 0");
    }
    if (not((t <= '9' and t >= '0') or t == 'a' or t == 'A')) {
        throw logic_error("wrong number");
    }
    _array = new unsigned char[n];
    for (size_t i = 0; i < n; i++) {
        _array[i] = t;
    }
    _size = n;
}

Eleven::Eleven(const initializer_list< unsigned char> &t) {
    if (t.size() == 0) {
        throw logic_error("array can't has size 0");
    }
    _array = new unsigned char[t.size()];
    size_t i{t.size() - 1};
    for (auto &c: t) {
        if ((c <= '9' and c >= '0') or c == 'a' or c == 'A') {
            _array[i--] = c;
        }
        else {
            throw logic_error("wrong number");
        }
        _size = t.size();
    }

    for (size_t i = _size - 1; _array[i] == '0' and i > 0; --i) {
        _size--;
    }
}

Eleven::Eleven(const string &t) {
    if (t.size() == 0) {
        throw logic_error("array can't has size 0");
    }
    else {
        _array = new unsigned char[t.size()];
        _size  = t.size();

        for(size_t i{0}; i<_size; ++i) {                                                //неясная вещь, возможно придеться править
            if (((t[_size - 1 - i] <= '9' and t[_size - 1 - i] >= '0')) or (t[_size - 1 - i] == 'a' or t[_size - 1 - i] == 'A')) {
                _array[i] = t[_size - 1 - i];
            }
            else {
                throw logic_error("wrong number");
            }
        }
        for (size_t i = _size - 1; _array[i] == '0' and i > 0; --i) {
            _size--;
        }

    } 
}

Eleven::Eleven(const Eleven &other) {
    _size  = other._size;
    _array = new unsigned char[_size];
    for(size_t i{0} ;i < _size; ++i) {
        _array[i] = other._array[i];
    }
}

Eleven::Eleven(Eleven&& other) noexcept {
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}


Eleven::~Eleven() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

Eleven Eleven::ten_to_el(size_t num){
    string result = "";
    if(!num) result += '0';
    while(num){
        if(num % 11 < 10){
            char tmp = num%11 + '0';
            result = tmp + result;
        }else{
            result = 'a' + result;
        }
        num /= 11;
    }
    return Eleven{result};
}

size_t Eleven::el_to_ten() noexcept{
    size_t res = 0;
    int pow = 1;
    int digit = 0;

    for(size_t i{0}; i<_size; ++i){
        if (_array[i] == 'a' or _array[i] == 'A') {
            digit = 10;
        }
        else {
            digit = _array[i] - '0';
        }
        res += digit * pow;
        pow *= 11;
    }
    
    return res;

}

bool Eleven::bigger(const Eleven &other) const {
    if (_size < other._size) {
        return false;
    }
    if (_size > other._size) {
        return true;                        //могут быть какие-то неполадки здесь!
    }
    for (int i = _size - 1; i >= 0; --i) {
        if (tolower(_array[i]) < tolower(other._array[i])) {
            return false;
        }
        if (tolower(_array[i]) > tolower(other._array[i])) {
            return true;
        }
    }
    return false;
}

bool Eleven::smaller(const Eleven &other) const {
    if (_size < other._size) {
        return true;
    }
    if (_size > other._size) {
        return false;
    }
    for (int i = _size - 1; i >= 0; --i) {
        if (tolower(_array[i]) < tolower(other._array[i])) {
            return true;
        }
        if (tolower(_array[i]) > tolower(other._array[i])) {
            return false;
        }
    }
    return false;
}

bool Eleven::equal(const Eleven &other) const {
    bool eql{false};
    int digit_1;
    int digit_2;
    if (_size == other._size) {
        size_t temp{_size};
        eql = true;
        while (temp) {
            if (_array[temp - 1] == 'a' or _array[temp - 1] == 'A') {
                digit_1 = 10;
            }
            else {
                digit_1 = _array[temp - 1] - '0';
            }
            if (other._array[temp - 1] == 'a' or other._array[temp - 1] == 'A') {
                digit_2 = 10;
            }
            else {
                digit_2 = other._array[temp - 1] - '0';
            }
            eql = (digit_1 == digit_2) and eql;
            temp--;
        }
    }
    return eql;
}

Eleven Eleven::copy(const Eleven& other){
    this->_size = other._size;
    for(size_t i{0}; i < other._size; ++i){ 
        this->_array[i] = other._array[i];
    }
    return *this;
}

Eleven Eleven::addition(const Eleven& other) {
    this->copy(ten_to_el(this->el_to_ten() + Eleven{other}.el_to_ten()));
    return *this;
}

Eleven Eleven::subtraction(const Eleven& other) {
    if (this->smaller(other)) {
        throw logic_error("number can't be negative\n");
    }
    else {
        this->copy(ten_to_el(this->el_to_ten() - Eleven{other}.el_to_ten()));
    }
    return *this;
}

std::ostream &Eleven::print(std::ostream &os) {
    for (size_t i = 1; i <= _size; ++i) {
        os << _array[_size - i];
    }
}





// int main () {
//     Eleven a{"A89"};
//     Eleven c{"aaa"};
//     bool result = a.smaller(c);
//     bool res = a.equal(c); 
//     size_t b = a.el_to_ten();
//     size_t d = c.el_to_ten();
//     cout << "a: " << b << endl;
//     cout << "c: " << d << endl;
//     if (res) {
//         cout << "they are equal!\n";
//     }
//     else {
//         cout << "they are not equal!\n";
//     }
//     if (result) {
//         cout << "a is smaller than c" << endl;
//     }
//     else {
//         cout << "a is bigger than c" << endl;
//     }
// }