#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

std::vector<int> edge[20001];
int dist[20001];

int main() 
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m, x, y, max = -1;
    memset(dist, -1, sizeof(dist));
    std::queue<int> q;
    std::cin >> n >> m;

    while(m--) {
        std::cin >> x >> y;
        edge[y].push_back(x);
        edge[x].push_back(y);
    }

    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();

        for (auto e: edge[temp]) {
            if (dist[e] != -1) {
                continue;
            }
            q.push(e);
            dist[e] = dist[temp] + 1;
            if (max < e) {
                max = dist[e];
            }
        }
    }

    int num = 0;
    for(int i=1; i<=n; i++) {
        if (dist[i]==max) {
            std::cout << i << ' ' << dist[i] << ' ';
            break;
        }
    }

    for (int i=1; i<=n; i++) {
        if (dist[i] == max) {
            num++;
        }
    }

    std::cout << num;

    return 0;
}