#include <iostream>
#include <vector>
#include <stack>

int main() 
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int temp, n;
    std::stack<std::pair<int,int>> s;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i=0; i<n; i++) {
        std::cin >> temp;

        if (s.empty()) {
            s.push({i, temp});
            continue;
        }

        if (temp < s.top().second) {
            s.push({i, temp});
        } else {
            while (!s.empty() && temp > s.top().second) {
                v[s.top().first] = temp;
                s.pop();
            }
            s.push({i, temp});
        }
    }
    while (!s.empty()) {
        v[s.top().first] = -1;
        s.pop();
    }

    for (auto e : v) {
        std::cout << e << ' ';
    }
    return 0;
}