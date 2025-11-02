#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int s = 0;
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "add")
        {
            std::cin >> x;
            s |= (1 << x);
        }
        else if (cmd == "remove")
        {
            std::cin >> x;
            s &= ~(1 << x);
        }
        else if (cmd == "check")
        {
            std::cin >> x;
            std::cout << (int)((s & (1 << x)) > 0) << "\n";
        }
        else if (cmd == "toggle")
        {
            std::cin >> x;
            s ^= (1 << x);
        }
        else if (cmd == "all")
        {
            s = (1 << 21);
            s--;
        }
        else if (cmd == "empty")
        {
            s = 0;
        }
    }
    return 0;
}