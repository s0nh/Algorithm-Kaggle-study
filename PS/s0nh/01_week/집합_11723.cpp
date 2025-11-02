#include <iostream>
#include <set>

using namespace std;

int main(void) {    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, temp;
    string code;
    set<int> s;
    cin >> m;

    for (int i=0; i<m; i++) {
        cin >> code;

        if (code == "add") {
            cin >> temp;
            s.insert(temp);
        } else if (code == "remove") {
            cin >> temp;
            s.erase(temp);
        } else if (code == "check") {
            cin >> temp;
            if (s.find(temp) != s.end())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else if (code == "toggle") {
            cin >> temp;
            if (s.find(temp) != s.end()) {
                s.erase(temp);
            } else {
                s.insert(temp);
            }
        } else if (code == "all") {
            for (int i=0; i<20; i++) {
                s.insert(i+1);
            }
        } else {
            s.clear();
        }
    }
    
    return 0;
}