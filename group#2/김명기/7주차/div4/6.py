# Eating Candies
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    l, r = 0, n-1
    a, b = 0, 0
    while l <= r:
        if a == b:
            ans = max(ans, l+n-1-r)
            b += arr[r]
            r -= 1
        elif a > b:
            b += arr[r]
            r -= 1
        else:
            a += arr[l]
            l += 1
    if a == b:
        ans = max(ans, l+n-1-r)
    print(ans)
