import sys
sys.setrecursionlimit(10**5)

def solution(n, computers):
    answer = 0
    visited = [0]*200

    def dfs(v):
        visited[v] = 1

        for i in range(n):
            if computers[v][i] == 1:
                if visited[i] == 0 and v != i:
                    dfs(i)

        

    
    for i in range(n):
        if not visited[i]:
            dfs(i)
            answer += 1

    return answer
