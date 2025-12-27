#include <iostream>
#include <queue>
#include <vector>

bool map[1001][1001];
int visited[1001][1001][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;

bool isin(const int& y, const int& x) {
    return (y >= 1 && y <= n && x >= 1 && x <= m);
}

int bfs() {
    std::queue<std::vector<int>> q;
    int x, y;
    bool isbroken;
    q.push({1, 1, 0});
    visited[1][1][0] = 1;
    while (!q.empty()) {
        y = q.front()[0];
        x = q.front()[1];
        isbroken = q.front()[2];
        q.pop();

        if (y == n && x == m) {
            return visited[y][x][isbroken];
        }

        for (int i = 0; i<4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (isin(new_y, new_x) && visited[new_y][new_x][isbroken] == 0) {
                if (!isbroken && map[new_y][new_x]) {
                    visited[new_y][new_x][1] = visited[y][x][isbroken] + 1;
                    q.push({new_y, new_x, 1});
                } else if (!map[new_y][new_x]){
                    visited[new_y][new_x][isbroken] = visited[y][x][isbroken] + 1;
                    q.push({new_y, new_x, isbroken});
                }
            }
        }
    }
    return -1;
}

int main(void) {    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    std::vector<std::string> v(n);

    for (int i=0; i<n; i++) {
        std::cin >> v[i];
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            map[i][j] = v[i-1][j-1] - '0';
        }
    }
    std::cout << bfs();
    return 0;
}