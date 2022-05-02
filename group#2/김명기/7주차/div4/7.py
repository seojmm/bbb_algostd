# Fall Down
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, m = map(int, input().split())
    arr = [list(input().strip()) for i in range(n)]
    s = [0] * m
    ans = [['.'] * m for i in range(n)]
    for i in range(m):
        cnt = 0
        for j in range(n):
            if arr[j][i] == '*':
                cnt += 1
            elif arr[j][i] == 'o':
                ans[j][i] = 'o'
                for k in range(cnt):
                    ans[j-k-1][i] = '*'
                cnt = 0
        if cnt:
            for k in range(cnt):
                ans[j-k][i] = '*'

    for i in ans:
        print(''.join(i))
    print()
