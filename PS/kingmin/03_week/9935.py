import sys
input = lambda:sys.stdin.readline().rstrip()

target = input()
bomb = input()

answer = []
for i in target:
    answer.append(i)
    if len(answer) >= len(bomb):
        is_match = True
        for j in range(len(bomb)-1, -1, -1):
            if answer[j-len(bomb)] != bomb[j]: 
                is_match = False
                break
        if is_match:
            for _ in range(len(bomb)): answer.pop()

print(*answer if answer else "FRULA", sep = "")