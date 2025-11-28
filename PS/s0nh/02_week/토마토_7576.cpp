#include <iostream>
#include <queue>

using namespace std;

int box[1001][1001] = {0};

bool isEscape(const pair<int, int>& x, int m, int n);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n, cycle_len=0;
    queue<pair<int, int>> q;
    pair<int, int> tmp;
    int cnt = 0, iter = 0;
    cin >> m >> n;
    int max = m*n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> box[i+1][j+1];
            if (box[i+1][j+1] == 1) {
                cnt++;
                cycle_len++;
                q.push({i+1, j+1});
            } else if (box[i+1][j+1] == -1) {
                max--;
            }
        }
    }

    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        cycle_len--;

        if (!isEscape(tmp, m, n) && cnt < max) {
            if ((box[tmp.first][tmp.second] == 1 && iter>0) || (box[tmp.first][tmp.second] == -1)) {
                if (cnt == max)
                    break;
                if (cycle_len == 0) {
                    iter++;
                    cycle_len += q.size();
                }
                continue;
            }
            if (iter>0) {
                cnt++;
            }

            box[tmp.first][tmp.second] = 1;

            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, -1, 0, 1};

            for (int i=0; i<4; i++) {
                q.push({tmp.first+dy[i], tmp.second+dx[i]});
            }

        }
        if (cnt == max) {
            break;
        }
        if (cycle_len == 0) {
            iter++;
            cycle_len += q.size();
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (box[i][j] == 0) {
                iter = -1;
            }
        }
    }

    cout << iter;

    return 0;
}

bool isEscape(const pair<int, int>& x, int m, int n) {
    return x.first > n || x.first < 1 || x.second > m || x.second < 1;
}