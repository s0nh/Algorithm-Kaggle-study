#include <iostream>
#include <vector>
#include <stack>

int compare(char a) {
    switch (a) {
        case '(':
            return 0;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }
    return -1;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
 
    std::stack<char> op;
    std::string str;
    std::cin >> str;

    for (int i=0; i<str.length(); i++) {
        char c = str[i];

        if (c >= 'A' && c <= 'Z') {
            std::cout << c;
            continue;
        }
        
        if (op.empty()) {
            op.push(c); 
        } else if (c == '(') {
            op.push(c);
        } else if (c == ')') {
            while(!op.empty() && op.top() != '(') {
                char oper = op.top();
                op.pop();
                std::cout << oper;
            }
            op.pop();
        } else {
            if (!op.empty() && compare(c) > compare(op.top())) {
                op.push(c);
            } else {
                while (!op.empty() && compare(c) <= compare(op.top())) {
                    std::cout << op.top();
                    op.pop();
                }
                op.push(c);
            }
        }
    }
    while (!op.empty()) {
        std::cout << op.top();
        op.pop();
    }
    return 0;
}