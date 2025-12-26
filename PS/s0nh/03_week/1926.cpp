#include <iostream>

int n, m;
int map[501][501];
int check[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isin(const int& y, const int& x) {
    return (y >= 1 && y <= n && x >= 1 && x <= m);
}

int dfs(const int& y, const int& x) {
    int nums = 0;

    for (int i=0; i<4; i++) {
        int new_x = dx[i] + x;
        int new_y = dy[i] + y;

        if (isin(new_y, new_x) && !check[new_y][new_x] && map[new_y][new_x] == 1) {
            check[new_y][new_x] = true;
            nums += dfs(new_y, new_x);
        }
    }

    if (nums == 0) {
        return 1;
    }
    return nums + 1;
}

int main(void) {    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int max = 0;
    int cnt = 0;
    std::cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (map[i][j] && !check[i][j]) {
                cnt++;
                check[i][j] = true;
                int num = dfs(i, j);
                max = num > max ? num : max; 
            }
        }
    }

    std::cout << cnt << '\n' << max;

    return 0;
}