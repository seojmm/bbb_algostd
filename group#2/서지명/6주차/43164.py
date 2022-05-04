import sys
import collections

def solution(tickets):
    answer = []
    graph = collections.defaultdict(list)

    for ticket in sorted(tickets):
        graph[ticket[0]].append(ticket[1])
    
    def dfs(v):
        while graph[v]:
            dfs(graph[v].pop(0))
        answer.append(v)
    
    dfs("ICN")

    return answer[::-1]
