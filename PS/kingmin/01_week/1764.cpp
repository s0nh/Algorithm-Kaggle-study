#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::string name;
    std::map<std::string, bool> dict;
    std::vector<std::string> ans;
    std::cin >> n;
    std::cin >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> name;
        dict[name] = true;
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> name;
        if (dict.find(name) != dict.end())
        {
            ans.push_back(name);
        }
    }
    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << '\n';
    }
    return 0;
}