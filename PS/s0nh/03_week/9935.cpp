#include <iostream>
#include <string>

int main() 
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string s, temp, result;
    std::cin >> s >> temp;
    
    for(int i=0; i<s.length(); i++) {
        result.push_back(s[i]);

        if (result.length() >= temp.length()) {
            for(int j=0; j<temp.length(); j++) {
                if (result[result.length()-temp.length() + j] != temp[j]) {
                    break;
                }
                if (j == temp.length()-1) {
                    for(int i=0; i<temp.length(); i++) {
                        result.pop_back();
                    }
                }
            }
        }
    }

    if (result.length() == 0) {
        std::cout << "FRULA";
    } else {
        std::cout << result;
    }
    
    return 0;
}