import sys
import collections
input = sys.stdin.readline


LC, LH = map(int, input().rstrip().split())
Hcut = [-LC]
Vcut = [-LC]
H = int(input().rstrip())
Hcut.extend(list(map(int, input().rstrip().split())))
V = int(input().rstrip())
Vcut.extend(list(map(int, input().rstrip().split())))
ans = 0
Hcut.sort()
Vcut.sort()
Hcut.append(LC)
Vcut.append(LC)

for i in range(1, len(Hcut)):
    for j in range(1, len(Vcut)):
        if not (Hcut[i-1] >= -LH and Hcut[i] <= LH and Vcut[j-1] >= -LH and Vcut[j] <= LH):
            ans += 1
        if Hcut[i-1] < -LH and Hcut[i] > LH and Vcut[j-1] >= -LH and Vcut[j] <= LH:
            ans += 1
        if Hcut[i-1] >= -LH and Hcut[i] <= LH and Vcut[j-1] < -LH and Vcut[j] > LH:
            ans += 1

print(ans)
