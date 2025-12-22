import sys
import heapq
input = lambda:sys.stdin.readline().rstrip()

board = []
for _ in range(3):
    board += list(map(int, input().split()))

def heuristic(board):
    cost = 0
    for i in range(9):
        num = board[i]-1
        cost += abs(i//3-num//3)+abs(i%3-num%3)
    return cost

pq = [(heuristic(board), 0, board)]
while pq:
    f, g, bd = heapq.heappop(pq)
    if f == g:
        break
    zero_idx =l