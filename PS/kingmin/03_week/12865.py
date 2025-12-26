import sys
input = lambda:sys.stdin.readline().rstrip()

n, k = map(int, input().split())
obj = []
for _ in range(n):
    obj.append(tuple(map(int, input().split())))

dp = [[0]*(k+1) for _ in range(n+1)]

for i in range(1, n+1):
    w, v = obj[i-1]
    for j in range(1, k+1):
        if w > j:
            dp[i][j] = dp[i-1][j]
            continue
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v)

print(dp[-1][-1])