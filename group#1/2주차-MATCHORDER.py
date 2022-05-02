import sys
import collections
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

C = int(input())

while C:
    N = int(input())
    russia = list(map(int, input().rstrip().split()))
    korea = list(map(int, input().rstrip().split()))
    russia.sort()
    korea.sort()

    cnt = 0

    for i in range(N):
        if korea[i] < russia[cnt]:
            continue

        cnt += 1

    print(cnt)

    C -= 1
