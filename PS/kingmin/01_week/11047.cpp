#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k, a;
    int answer = 0;
    std::vector<int> coins;
    std::cin >> n;
    std::cin >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a;
        coins.push_back(a);
    }
    int j = coins.size() - 1;
    while (k > 0)
    {
        answer += k / coins[j];
        k %= coins[j];
        j--;
    }
    std::cout << answer << '\n';
    return 0;
}