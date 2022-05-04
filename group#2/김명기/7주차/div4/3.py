# Odd/Even Increments
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    o, e = [], []
    for i in range(n):
        if i % 2:
            o.append(arr[i] % 2)
        else:
            e.append(arr[i] % 2)
    oo = True
    ee = True
    for i in range(len(o)-1):
        if o[i] != o[i+1]:
            oo = False
    for i in range(len(e)-1):
        if e[i] != e[i+1]:
            ee = False
    if oo and ee:
        print("YES")
    else:
        print("NO")
