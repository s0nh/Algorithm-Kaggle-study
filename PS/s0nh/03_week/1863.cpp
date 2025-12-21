#include <iostream>
#include <stack>

int main(void) {    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::stack<double> s;
    int n;
    double y, temp;
    int ans = 0;

    std::cin >> n;
    s.push(-1.0);

    for (int i=0; i<n; i++) {
        std::cin >> temp >> y;

        if (y > 0 && s.top() < y) {
            s.push(y);
        } else {
            while(s.top() > y) {
                s.pop();
                ans++;
                if (y > 0 && s.top() < y) {
                    s.push(y);
                }
            }
        }
    }

    while(s.size() != 1) {
        s.pop();
        ans++;
    }
    std::cout << ans;

    return 0;
}