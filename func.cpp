#include "func.h"
#include <string>
#include <stack>

bool checkBr(const std::string& Word) {
    std::stack <char> stack;
    for (char c: Word) {
        if (c == '(') {
            stack.push(c);
        }
        else if (c == ')') {
            if (stack.empty()) {
                return false;
            }
            char head = stack.top();
            stack.pop();
            if (c == ')' && head != '(') {
                return false;
            }
        }
        else if (c == '\0') {
            return true;
        }
        else {
            return false;
        }
    }
    return stack.empty();
}