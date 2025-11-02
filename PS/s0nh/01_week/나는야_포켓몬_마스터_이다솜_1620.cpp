#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    string name, temp;
    map<string, int> set;
    cin >> n >> m;
    vector<string> v(n);

    for (int i=0; i<n; i++) {
        cin >> name;
        v[i] = name;
        set.insert({name, i+1});
    }

    for (int i=0; i<m; i++) {
        cin >> temp;
        if (temp[0] > '0' && temp[0] <= '9') {
            cout << v[atoi(temp.c_str())-1] << '\n';
        } else {
            cout << set[temp] << '\n';
        }
    }
    
    return 0;
}