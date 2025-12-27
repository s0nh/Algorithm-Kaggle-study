#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

char map[2001][2001];
bool visited[2001][2001];
int dx[7] = {1, 1, 1, 0, -1, -1, -1};
int dy[7] = {1, 0, -1, 1, -1, 0, 1};
int n;

bool isin(const int& y, const int& x) {
    return (y >= 1 && y <= n && x >= 1 && x <= n);
}

int bfs(const int& i, const int& j) {
    std::queue<std::pair<int, int>> q;
    int x, y, nums=0;
    q.push({i, j});
    while (!q.empty()) {
        x = q.front().second;
        y = q.front().first;
        q.pop();
        visited[y][x] = true;

        for (int i = 0; i<7; i++) {
            int new_x = x + dx[i];
            int new_y = y - dy[i];

            if (isin(new_y, new_x) && map[new_y][new_x] != '#' && !visited[new_y][new_x]) {
                visited[new_y][new_x] = true;
                q.push({new_y, new_x});
                nums++;
            }
        }
    }
    return nums;
}

int main(void) {    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    std::vector<std::string> v(n);

    for (int i=0; i<n; i++) {
        std::cin >> v[i];
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            map[i][j] = v[i-1][j-1];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if(!visited[i][j] && map[i][j] == 'F') {
                std::cout << bfs(i, j);
                return 0;
            }
        }
    }

    return 0;
}