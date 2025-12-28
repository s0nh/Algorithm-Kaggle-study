import sys
input = lambda:sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    dp = [[0]*(n+1) for _ in range(4)]
    for i in range(1, 4):
        dp[i][0] = 1
        for j in range(1, n+1):
            if i > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i][j-i]
    print(dp[-1][-1])