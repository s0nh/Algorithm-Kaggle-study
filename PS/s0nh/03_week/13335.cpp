#include <iostream>
#include <vector>
#include <queue>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
 
    int n, w, l, t = 0, i = 0;
    std::cin >> n >> w >> l;
    std::vector<int> v(n);
    std::queue<std::pair<int, int>> q;

    for (int i=0; i<n; i++) {
        std::cin >> v[i];    
    }

    while(i < n) {
        int a = 0;

        for(int k=0; k<q.size(); k++) {
                std::pair<int, int> f = q.front();
                q.pop();
                a += f.first;
                q.push(f);
        }

        if (q.size() <= w && a + v[i] <= l) {
            if (!q.empty() && q.front().second == w) {
                q.pop();
            }
            for(int k=0; k<q.size(); k++) {
                std::pair<int, int> f = q.front();
                q.pop();
                f.second += 1;
                q.push(f);
            }
            q.push(std::make_pair(v[i], 1));
            t += 1;
            i += 1;
        } else {
            int cost = w - q.front().second;
            t += cost;
            q.pop();
            for(int k=0; k<q.size(); k++) {
                std::pair<int, int> f = q.front();
                q.pop();
                f.second += cost;
                q.push(f);
            }
        }
    }
    if (!q.empty()) {
        t += w - q.back().second + 1;
    }
    std::cout << t;

    return 0;
}