import sys
input = lambda:sys.stdin.readline().rstrip()

r, c, m = map(int, input().split())

before = [[None]*c for _ in range(r)]
sharks = []
for _ in range(m):
    x, y, s, d, z = map(int, input().split())
    x -= 1
    y -= 1
    before[x][y] = (z, s, d)
    sharks.append((x, y))

direction = [
    (0, 0),
    (-1, 0),
    (1, 0),
    (0, 1),
    (0, -1),
]

total = 0

for j in range(c):
    after = [[None]*c for _ in range(r)]
    new_sharks = []
    for i in range(r):
        if before[i][j] is not None:
            total += before[i][j][0]
            before[i][j] = None
            break
    for x, y in sharks:
        if before[x][y] is None:
            continue
        z, s, d = before[x][y]

        if d <= 2:
            s %= (r-1)*2
        else:
            s %= (c-1)*2
        for _ in range(s):
            dx, dy = direction[d]
            if not (0 <= x+dx < r and 0 <= y+dy < c):
                if d == 1: d = 2
                elif d == 2: d = 1
                elif d == 3: d = 4
                elif d == 4: d = 3
            dx, dy = direction[d]
            x, y = x+dx, y+dy
        new_sharks.append((x, y))
        if after[x][y] is not None:
            after[x][y] = max(after[x][y], (z, s, d))
        else:
            after[x][y] = (z, s, d)
    before = after
    sharks = new_sharks

print(total)