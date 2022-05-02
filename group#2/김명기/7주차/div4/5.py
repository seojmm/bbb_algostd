# 2-Letter Strings
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    arr = [input().strip() for i in range(n)]
    d = {}
    for i in arr:
        try:
            d[i] += 1
        except:
            d[i] = 1
    l = len(d)
    ans = 0
    key = d.keys()
    key = [i for i in key]
    for i in range(l):
        for j in range(i+1, l):
            if (key[i][0] == key[j][0] or key[i][1] == key[j][1]) and key[i] != key[j]:
                ans += d[key[i]]*d[key[j]]
    print(ans)
