#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkBrackets(const string& str) {
    stack<char> stk;  

    for (size_t i = 0; i < str.size(); ++i) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stk.empty()) {
                cout << "Ошибка в строке: " << str.substr(0, i + 1) << endl;
                return false;
            }

            char top = stk.top();
            stk.pop();

            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                cout << "Ошибка в строке: " << str.substr(0, i + 1) << endl;
                return false;
            }
        }
    }

    if (stk.empty()) {
        cout << "Строка корректна." << endl;
        return true;
    }
    else {
        cout << "Ошибка в строке: " << str << endl;
        return false;
    }
}

int main() {
    string input;
    cout << "Введите строку с символами (заканчивающуюся на ';'): ";
    getline(cin, input);

    if (input.back() == ';') {
        input.pop_back();
    }

    checkBrackets(input);

    return 0;
}
