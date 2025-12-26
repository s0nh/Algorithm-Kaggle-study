#include <iostream>
#include <cstring>
#include <stack>

int n, m;
int map[301][301];
int melt[301][301];
bool check[301][301];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isin(const int& y, const int& x) {
    return (y >= 1 && y <= n && x >= 1 && x <= m);
}

void dfs(int i, int j) {
    std::stack<std::pair<int, int>> s;

    s.push({i, j});
    while (!s.empty()) {
        int y = s.top().first;
        int x = s.top().second;
        int cnt = 0;
        s.pop();

        for (int k=0; k<4; k++) {
            int new_y = y + dy[k];
            int new_x = x + dx[k];
            if (map[new_y][new_x] == 0) {
                cnt++;
            }
            if (isin(new_y, new_x) && !check[new_y][new_x]) {
                check[new_y][new_x] = true;
                s.push({new_y, new_x});
            }
        }
        melt[y][x] = cnt;
    }
}
int main(void) {    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int day = 0, region = 0;
    std::cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int a;
            std::cin >> a;
            if (a==0) {
                check[i][j] = true;
            }
            map[i][j] = a;
        }
    }

    while (true) {
        for(int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (!check[i][j]) {
                    dfs(i, j);
                    region++;
                }
            }
        }

        if (region > 1) {
            break;
        } else if (region == 0) {
            std::cout << 0;
            return 0;
        }

        region = 0;
        for(int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                map[i][j] = map[i][j] > melt[i][j] ? map[i][j] - melt[i][j] : 0;
                check[i][j] = map[i][j] == 0 ? true : false;
            }
        }
        day++;
    }

    std::cout << day;


    return 0;
}