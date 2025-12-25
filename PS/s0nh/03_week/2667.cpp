#include <iostream>
#include <vector>
#include <algorithm>

int n;
bool map[26][26];
bool check[26][26];
std::vector<int> v;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isin(const int& y, const int& x) {
    return (y >= 1 && y <= n && x >= 1 && x <= n);
}

int dfs(const int& y, const int& x) {
    int nums = 0;
    for (int i=0; i<4; i++) {
        int new_y = dy[i] + y;
        int new_x = dx[i] + x;

        if (isin(new_y, new_x) && map[new_y][new_x] && !check[new_y][new_x]) {
            check[new_y][new_x] = true;
            nums += dfs(new_y, new_x);
        }
    }

    if (nums == 0) {
        return 1;
    }
    return nums+1;
}

int main(void) {    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    std::vector<std::string> s(n+1);

    for (int i=1; i<=n; i++) {
        std::cin >> s[i];
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            map[i][j] = bool(s[i][j-1] - '0');
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!check[i][j] && map[i][j]) {
                check[i][j] = true;
                int num = dfs(i, j);
                v.push_back(num);
            }
        }
    }

    if (v.size() == 0) {
        std::cout << 0;
        return 0;
    }

    std::sort(v.begin(), v.end());

    std::cout << v.size() << '\n';
    for (auto e : v) {
        std::cout << e << '\n';
    }
    return 0;
}