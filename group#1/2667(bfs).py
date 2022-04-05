import sys
import collections

input = sys.stdin.readline

N = int(input())
graph = [list(map(int, input().strip())) for _ in range(N)]
total = 0
houses = []
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


for i in range(N):
    for j in range(N):
        if graph[i][j] == 1:
            q = collections.deque()
            q.append((i, j))
            graph[i][j] = 0
            total = 1

            while q:
                x, y = q.popleft()
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]

                    # 범위를 벗어나면 continue
                    if nx < 0 or nx >= N or ny < 0 or ny >= N:
                        continue

                    # 아직 방문하지 않았을 경우
                    if graph[nx][ny] == 1:
                        q.append((nx, ny))
                        graph[nx][ny] = 0
                        total += 1

            houses.append(total)

houses.sort()
print(len(houses))
for house in houses:
    print(house)
