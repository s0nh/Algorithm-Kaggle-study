import sys
input = lambda:sys.stdin.readline().rstrip()
import heapq

for _ in range(int(input())):
    n = int(input())
    applicants = []
    for _ in range(n):
        g1, g2 = map(int, input().split())
        heapq.heappush(applicants, (g1, g2))

    top_grade = -1
    ans = 0
    while applicants:
        i, grade = heapq.heappop(applicants)
        if top_grade == -1:
            top_grade = grade
            ans += 1
            continue
        if grade < top_grade:
            top_grade = grade
            ans += 1
    print(ans)
