# Maximal AND
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    brr = arr.copy()
    d = [0] * 31
    arr = [bin(i)[2:] for i in arr]
    arr = ['0'*(31-len(i)) + i for i in arr]
    for i in arr:
        for j in range(31):
            if i[j] == '1':
                d[j] += 1
    d = [n-i for i in d]
    ix = 0
    ans = brr[0]

    for i in range(1, n):
        ans &= brr[i]

    for i in range(31):
        if d[i] <= k:
            ans |= pow(2, 30-i)
            k -= d[i]

    print(ans)
