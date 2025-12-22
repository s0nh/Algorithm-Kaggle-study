import sys
input = lambda: sys.stdin.readline()

n = int(input())

def matmul(x, y):
    answer = [[0, 0], [0, 0]]
    answer[0][0] = (x[0][0]*y[0][0] + x[0][1]*y[1][0]) % 1000000007
    answer[0][1] = (x[0][0]*y[0][1] + x[0][1]*y[1][1]) % 1000000007
    answer[1][0] = (x[1][0]*y[0][0] + x[1][1]*y[1][0]) % 1000000007
    answer[1][1] = (x[1][0]*y[0][1] + x[1][1]*y[1][1]) % 1000000007
    return answer

def solution(n):
    I = [[0, 1], [1, 1]]
    if n == 1:
        return I
    temp = solution(n//2)
    if n%2 == 0:
        return matmul(temp,temp)
    return matmul(matmul(temp,temp), I)

print(solution(n)[0][1])