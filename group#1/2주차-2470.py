import sys
import collections

sys.setrecursionlimit(10**5)
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().rstrip().split()))
arr.sort()

l, r = 0, N-1
ans1, ans2 = l, r
minVal = arr[l] + arr[r]

while l < r:

    tmp = arr[l] + arr[r]
    if abs(tmp) < abs(minVal):
        ans1, ans2 = l, r
        minVal = tmp

        if minVal == 0:
            break

    if tmp < 0:
        l += 1
    else:
        r -= 1

print(arr[ans1], arr[ans2])
