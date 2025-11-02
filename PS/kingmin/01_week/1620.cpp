#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string name;
    std::string key;

    int m, n;
    std::map<std::string, int> dict;
    std::vector<std::string> v;
    std::cin >> m;
    std::cin >> n;
    for (int i = 0; i < m; i++)
    {
        std::cin >> name;
        dict[name] = i + 1;
        v.push_back(name);
    }

    for (int j = 0; j < n; j++)
    {
        std::cin >> key;
        if (dict.find(key) != dict.end())
        {
            std::cout << dict[key] << "\n";
        }
        else
        {
            std::cout << v[stoi(key) - 1] << "\n"; // stoi: string -> int
        }
    }
    return 0;
}