#include <iostream>
#include "func.h"
#include <string>

using namespace std;

int main () {
    setlocale(LC_ALL, "ru");
    const int m_length = 100;
    string Word;
    getline(cin, Word, '\n');
    if (Word.length() > m_length) {
        cout << "Превышена максимальная длина ввода\n";
        return 1;
    }
    cout << Word;
    if (checkBr(Word)) {
        cout << " => true" << endl;
    }
    else {
        cout << " => false" << endl;
    }
    return 0;
}