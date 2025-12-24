#include <iostream>
#include <vector>

int n;
char map[101][101];
bool check1[101][101];
bool check2[101][101];

bool isin(const int& i, const int& j) {
    return (i>=1 && i <= n && j >= 1 && j <= n);
}

bool change(char a) {
    if (a == 'B')
        return true;
    return false;
}

void dfs1(const int& y, const int& x) {
    check1[y][x] = true;
    char state = map[y][x];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for(int i=0; i<4; i++) {
        int new_y = y + dy[i];
        int new_x = x + dx[i];
        if (check1[new_y][new_x]) {
            continue;
        }
        if (isin(new_y, new_x) && map[new_y][new_x] == state) {
            dfs1(new_y, new_x);
        } 
    }
}

void dfs2(const int& y, const int& x) {
    check2[y][x] = true;
    bool state = change(map[y][x]);
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for(int i=0; i<4; i++) {
        int new_y = y + dy[i];
        int new_x = x + dx[i];
        if (check2[new_y][new_x]) {
            continue;
        }
        if (isin(new_y, new_x) && change(map[new_y][new_x]) == state) {
            dfs2(new_y, new_x);
        } 
    }
}

int main() 
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;

    int cnt1 = 0, cnt2 = 0;

    for(int i=1; i<=n; i++) {
        std::cin >> (map[i] + 1);
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if (!check1[i][j]) {
                dfs1(i, j);
                cnt1++;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if (!check2[i][j]) {
                dfs2(i, j);
                cnt2++;
            }
        }
    }

    std::cout << cnt1 << ' ' << cnt2;
    return 0;
}