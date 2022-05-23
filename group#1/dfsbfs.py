import sys
import collections

# graph = collections.defaultdict(list)
# graph[3].append(1)
# graph[1].append(3)
# graph[3].append(4)
# graph[3].append(5)
# print(graph)

# N = 100
# dist = [[0]*101 for _ in range(101)]
# dist[1][1] = 0

for k in range(1, 101):
    for i in range(1, 101):
        for j in range(1, 101):
            if dist[i][j] > dist[i][k] + dist[k][j]:
                dist[i][j] = dist[i][k] + dist[k][j]

# n = int(sys.stdin.readline())
# dp = [0]*1001
# dp[1] = 1
# dp[2] = 2
# dp[3] = 3

# for i in range(4, 1001):
#     dp[n] = (dp[n-1] + dp[n-2])%10007

N = 6
A = [10, 20, 10, 30, 20, 50]
dp = [0]*1001
dp[1] = 1

for i in range(2, N+1):
    dp[i] = max()
