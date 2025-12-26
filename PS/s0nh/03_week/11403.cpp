#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

std::vector<int> v[101];
bool visited[10001];
bool result[101][101];

bool bfs(int start, int end) {
    std::queue<int> q;

    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        visited[node] = true;
        q.pop();

        for (auto e : v[node]) {
            if (e == end) {
                return true;
            }
            if (!visited[e]) {
                visited[e] = true;
                q.push(e);
            }
        }
        
    }

    return false;
}

int main(void) {    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int a;
            std::cin >> a;
            if(a) {
                v[i].push_back(j);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            result[i][j] = bfs(i, j);
            memset(visited, 0, sizeof(visited));
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            std::cout << result[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}