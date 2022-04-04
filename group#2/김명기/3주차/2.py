# Reverse Sort

import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = list(map(int, list(input().rstrip())))
    t = s.copy()
    t.sort()
    if s == t:
        print(0)
        continue
    ss = sum(s)
    cnt = 0
    zeros = {}
    for i in range(n-1,n-ss-1,-1):
        if s[i] == 0:
            zeros[i] = 1
            cnt+=1
    ones = {}
    for i in range(n):
        if s[i] == 1:
            ones[i] = 1
            if len(ones) == cnt:
                break
    ans = []
    for i in ones:
        ans.append(i+1)
    for i in zeros:
        ans.append(i+1)
    ans.sort()
    print(1)
    print(len(ans), *ans)