# Treelabeling
# 4.cpp와 같은 코드인데 dfs에서 스택 오버플로우

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)

for _ in range(int(input())):
    n = int(input())
    g = [[] for i in range(n+1)]
    c = [-1] * (n+1)
    for i in range(n-1):
        x, y = map(int, input().split())
        g[x].append(y)
        g[y].append(x)

    def dfs(x, p, ix=0):
        global c
        c[x] = ix
        for i in g[x]:
            if i != p:
                dfs(i, x, 1-ix)
    dfs(1, 0)
    w, b = 0, 0
    s = 0
    for i in range(1, n+1):
        if c[i]:
            w += 1
        else:
            b += 1
    if w > b:
        w, b = b, w
        c = [-1] + [1-i for i in c[1:]]

    numbers = [[]]
    tmp = []
    for i in range(1, n+1):
        if len(tmp) == 0:
            tmp.append(i)
        else:
            if len(bin(i)) != len(bin(tmp[-1])):
                numbers.append(tmp)
                tmp = [i]
            else:
                tmp.append(i)
    if tmp:
        numbers.append(tmp)
    answer = []
    www = w
    w = list(map(int, list(bin(w)[2:])))[::-1]
    check = [0] * len(numbers)
    ww, bb = [], []
    for i in range(len(w)):
        if w[i]:
            ww.extend(numbers[i+1])
            check[i+1] = True
    for i in range(1, len(numbers)):
        if not check[i]:
            bb.extend(numbers[i])
    wix, bix = 0, 0
    for i in range(1, n+1):
        if c[i] != s:
            answer.append(ww[wix])
            wix += 1
        else:
            answer.append(bb[bix])
            bix += 1
    print(*answer)
