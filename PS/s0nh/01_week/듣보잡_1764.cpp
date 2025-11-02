#include <iostream>
#include <set>

using namespace std;

int main() {
    set<string> s, answer;

    int m, n;
    string name;
    cin >> m >> n;
    
    for (int i=0; i<m; i++) {
        cin >> name;
        s.insert(name);
    }

    for (int i=0; i<n; i++) {
        cin >> name;
        if (s.find(name) != s.end()) {
            answer.insert(name);
        }
    }

    cout << answer.size() << '\n';
    for (auto iter=answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << '\n';
    }
    return 0;
}