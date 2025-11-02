#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    set<string> s, answer;

    int n, k, temp, cnt=0;
    vector<int> a;
    cin >> n >> k;
    
    for (int i=0; i<n; i++) {
        cin >> temp;
        a.push_back(temp);
    }

    for (auto iter = rbegin(a); iter != rend(a); iter++) {
        if (k / *iter > 0) {
            cnt += k/(*iter);
            k -= (k / *iter) * (*iter);
        }
    }

    cout << cnt;
    
    return 0;
}