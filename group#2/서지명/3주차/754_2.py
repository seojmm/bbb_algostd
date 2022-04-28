import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    s = list(map(int, input().rstrip()))
    
    tmp = sorted(s)
    ans = []
    flag = True

    for i in range(n):
        if s[i] != tmp[i]:
            ans.append(i+1)
            flag = False
    
    if flag:
        print(0)
        continue
    
    print(1)
    print(len(ans), end=" ")
    for a in ans:
        print(a, end=" ")
    print()
