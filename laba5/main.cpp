#include "forward_list.h"
#include <map>

int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

int main() {
    std::map<int, int, std::less<>, MAllocator<std::pair<int, int>, 10>> mymap;

    for (int i = 0; i < 10; i++) {
        mymap[i] = factorial(i);
        std::cout << "Ключ: " << i << ", Значение: " << mymap[i] << std::endl;
    }

    std::cout << "|------------------------------------------------|" << std::endl;
    std::cout << "Список из 20 цифр:" << std::endl;

    MForwardList<int, 21, MAllocator<int, 20>> lst;
    for(int i = 0; i < 20; i++) {
        lst.push_front(i);
    }

    for (auto& value : lst) {
        std::cout << value << ' ';
    }

    std::cout << std::endl;
}
