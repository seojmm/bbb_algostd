import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    s = input().rstrip()

    ans = -1

    arr = ['aa', 'aba', 'aca', 'abca', 'acba', 'abbacca', 'accabba']

    for val in arr:
        if val in s:
            ans = len(val)
            break

    print(ans)
