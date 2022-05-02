# Colorful Stamp
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    arr = input().strip().split("W")
    arr = [i for i in arr if i]
    flag = True
    for i in arr:
        if len(i) == 1:
            flag = False
            break
        else:
            f = False
            for j in range(len(i)-1):
                if i[j] != i[j+1]:
                    f = True
            if not f:
                flag = False
    if not flag:
        print("NO")
    else:
        print("YES")
