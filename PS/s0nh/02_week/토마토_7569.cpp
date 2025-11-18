#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

bool tmp[101][101][101] = {0};
int map[101][101][101] = {0};
int cnt[101][101][101] = {0};
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

bool isOut(int x, int y, int z, int m, int n, int h) {
    return x > m || x < 1 || y > n || y < 1 || z > h || z < 1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int m, n, h, count = 0, iter = 0;
    queue<tuple<int, int, int>> q;
    tuple<int, int, int> t;
    cin >> m >> n >> h;
    int max = m*n*h;

    for (int i=1; i<=h; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=m; k++) {
                int a;
                cin >> a;
                map[i][j][k] = a;

                if (a == -1) {
                    max--;
                    map[i][j][k] = a;
                    tmp[i][j][k] = true;
                }

                if (a == 1) {
                    count++;
                    q.push({i, j, k});
                    tmp[i][j][k] = true;
                }
            }
        }
    }

    if (count == max) {
        cout << 0;
        return 0;
    }

    while (!q.empty()) {
        t = q.front();
        q.pop();
        int x = get<2>(t);
        int y = get<1>(t);
        int z = get<0>(t);

        for (int i=0; i<6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (isOut(nx, ny, nz, m, n, h)) {
                continue;
            }

            if (!tmp[nz][ny][nx]) {

                map[nz][ny][nx] = 1;
                tmp[nz][ny][nx] = true;
                cnt[nz][ny][nx] = cnt[z][y][x] + 1;

                if (cnt[nz][ny][nx] > iter) {
                    iter = cnt[nz][ny][nx];
                }
                q.push({nz, ny, nx});
            }
        }
    }

    for (int i=1; i<=h; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=m; k++) {
                if (map[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << iter;
    return 0;
}