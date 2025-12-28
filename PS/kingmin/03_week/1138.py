import sys
input = lambda:sys.stdin.readline().rstrip()

n = int(input())

dp = [0] * (n+1)
for i in range(1, n+1):
    if i == 3: dp[i] = 1
    if i == 5: dp[i] = 1
    if i >= 3 and dp[i-3]:
        dp[i] = dp[i-3] + 1
    if i >= 5 and dp[i-5]:
        dp[i] = dp[i-5] + 1
print(dp)
print(dp[-1] if dp[-1] else -1)