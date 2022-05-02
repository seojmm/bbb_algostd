# Triple
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    d = {}
    for i in arr:
        try:
            d[i] += 1
        except:
            d[i] = 1
    for i in d:
        if d[i] >= 3:
            print(i)
            break
    else:
        print(-1)
