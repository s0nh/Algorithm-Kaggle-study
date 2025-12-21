#include <iostream>
#include <string>
#include <vector>

int convert2Int(const std::string& s) {
    std::string array[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    for (int i=0; i<10; i++) {
        if (array[i] == s) {
            return i;
        }
    }

    if (s == "+" || s == "-" || s == "x" ||  s == "/" ||  s == "=" ) {
        return 10;
    }

    return -1;
}

std::string convert2String(const char& i) {
    std::string array[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    return array[i - '0'];
}

int main(void) {    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string str, temp = "";
    std:: cin >> str;
    std::vector<std::string> tokens;

    tokens.push_back(std::string(""));

    for (int i=0; i<str.length(); i++) {
        temp += str[i];

        int c = convert2Int(temp);
        switch(c) {
            case 10:
                tokens.push_back(temp);
                tokens.push_back(std::string(""));
                temp = "";
                break;
            case -1:
                if (str[i+1] == '-' || str[i+1] == '+' || str[i+1] == 'x' || str[i+1] == '/' || str[i+1] == '=') {
                    std::cout << "Madness!";
                    return 0;
                }
                break;
            default:
                tokens[tokens.size()-1] += '0' + c;
                temp = "";
                break;
        }
    }

    long result = std::stoi(tokens[0]);
    std::string p = tokens[0];
    
    try {
        for (int i=1; i<tokens.size(); i++) {
            if (tokens[i] == "+") {
                result += std::stoi(tokens[i+1]);
            } else if (tokens[i] == "-") {
                result -= std::stoi(tokens[i+1]);
            } else if (tokens[i] == "x") {
                result *= std::stoi(tokens[i+1]);
            } else if (tokens[i] == "/") {
                result /= std::stoi(tokens[i+1]);
            }
            p += tokens[i];
        }

        std::cout << p << '\n';
        std::string result_str = std::to_string(result);

        for (int i=0; i<result_str.length(); i++) {
            if (result_str[i] >= '0' && result_str[i] <= '9') {
                std::cout << convert2String(result_str[i]);
            } else {
                std::cout << result_str[i];
            }
        }
    } catch (...) {
        std::cout << "Madness!";
        return 0;
    }

    return 0;
}