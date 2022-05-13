import sys
import collections
import heapq
input = sys.stdin.readline

N, M = map(int, input().split())
graph = []
tree_dist = [[-1]*M for _ in range(N)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
q = collections.deque()
px, py = -1, -1

for i in range(N):
    graph.append(list(input().rstrip()))
    for j in range(M):
        if graph[i][j] == '+':
            q.append((i, j, 0))
            tree_dist[i][j] = 0
        elif graph[i][j] == 'V':
            px, py = i, j

# set distance from trees
while q:
    x, y, d = q.popleft()
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if nx < 0 or nx >= N or ny < 0 or ny >= M: continue
        if tree_dist[nx][ny] != -1: continue
        tree_dist[nx][ny] = d + 1
        q.append((nx, ny, d+1))

def dijkstra():
    pq = []
    ans = 987654321
    visited = [[False]*M for _ in range(N)]

    heapq.heappush(pq, (-tree_dist[px][py], px, py))
    visited[px][py] = True

    while pq:
        d, curX, curY = heapq.heappop(pq)
        ans = min(ans, -d)

        if graph[curX][curY] == 'J':
            return ans
        
        for i in range(4):
            nx, ny = curX + dx[i], curY + dy[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= M: continue
            if visited[nx][ny]: continue
            heapq.heappush(pq, (-tree_dist[nx][ny], nx, ny))
            visited[nx][ny] = True

print(dijkstra())