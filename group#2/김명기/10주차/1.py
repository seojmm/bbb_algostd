# 경사로
n, l = map(int, input().split())
arr = [list(map(int, input().split())) for i in range(n)]


def check(arr):
    i = 0
    v = [0] * n
    while i < n-1:
        diff = abs(arr[i] - arr[i+1])
        if diff == 1:
            if arr[i] > arr[i+1]:
                if i+l > n-1:
                    return False
                for j in range(i+1, i+1+l):
                    if v[j] or arr[j] != arr[i+1]:
                        return False
                    v[j] = 1
            else:
                if i-l+1 < 0:
                    return False
                for j in range(i, i-l, -1):
                    if v[j] or arr[j] != arr[i]:
                        return False
                    v[j] = 1
        elif diff > 1:
            return False
        i += 1
    return True


ans = 0

for i in range(n):
    brr = arr[i].copy()
    ans += check(brr)
    brr = [arr[j][i] for j in range(n)]
    ans += check(brr)
print(ans)
