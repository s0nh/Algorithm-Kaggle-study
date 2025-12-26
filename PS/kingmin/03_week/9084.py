import sys
input = lambda:sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    coins = list(map(int, input().split()))
    m = int(input())
    dp = [[0]*(m+1) for _ in range(len(coins)+1)]
    for i in range(1, len(coins)+1):
        dp[i][0] = 1
        coin = coins[i-1]
        for j in range(1, m+1):
            if coin > j:
                dp[i][j] = dp[i-1][j]
                continue
            dp[i][j] = dp[i-1][j] + dp[i][j-coin]
    print(dp[-1][-1])
