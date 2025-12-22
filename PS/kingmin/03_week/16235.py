import sys
input = lambda: sys.stdin.readline()
from collections import deque

n, m, k = map(int, input().split())

land = [[5]*n for _ in range(n)]
energy = [list(map(int, input().split())) for _ in range(n)]
trees = []
for _ in range(n):
    p = []
    for j in range(n):
        p.append(deque([]))
    trees.append(p)
for _ in range(m):
    x, y, age = map(int, input().split())
    trees[x-1][y-1].append(age)
for _ in range(k):
    can_prop = []
    for x in range(n):
        for y in range(n):
            new_trees = deque([])
            dead_energy = 0
            for age in trees[x][y]:
                if age <= land[x][y]:
                    land[x][y] -= age
                    age += 1
                    if age % 5 == 0:
                        can_prop.append((x, y))
                    new_trees.append(age)
                else:
                    dead_energy += age//2
            land[x][y] += (dead_energy + energy[x][y])
            trees[x][y] = new_trees
    for x, y in can_prop:
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                nx, ny = x+dx, y+dy
                if (dx == dy == 0) or not (0 <= nx < n and 0 <= ny < n):
                    continue
                trees[nx][ny].appendleft(1)

total = 0
for x in range(n):
    for y in range(n):
        total += len(trees[x][y])

print(total)