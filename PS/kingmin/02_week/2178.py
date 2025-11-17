import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())

board = []
for _ in range(n):
    board.append(list(map(int, list(input()))))

def heuristic(x, y):
    return n-1-x + m-1-y

pq = [(1+heuristic(0, 0), 1, 0, 0)]\

INF = int(1e9)
dist = [[INF]*m for _ in range(n)]
dist[0][0] = 1

while pq:
    f, g, x, y = heapq.heappop(pq)
    if x == n-1 and y == m-1:
        print(g)
        break
    for dx, dy in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
        if 0 <= x+dx < n and 0 <= y+dy < m:
            if board[x+dx][y+dy] == 1:
                if g+1 < dist[x+dx][y+dy]:
                    dist[x+dx][y+dy] = g+1
                    heapq.heappush(pq, (g+1+heuristic(x+dx, y+dy), g+1, x+dx, y+dy))