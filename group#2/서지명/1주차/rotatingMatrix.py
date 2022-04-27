import sys
import collections
sys.setrecursionlimit(10**5)
input = sys.stdin.readline


def solution(rows, columns, queries):
    answer = []
    table = [[0]*(columns+1) for _ in range(rows+1)]
    for i in range(1, rows+1):
        for j in range(1, columns+1):
            table[i][j] = (i-1)*columns + j

    for query in queries:
        n = (query[3]-query[1]+1)*2 + (query[2]-query[0]-1)*2
        tmp = table[query[0]][query[1]]
        small = tmp

        for i in range(query[0]+1, query[2]+1):
            table[i-1][query[1]] = table[i][query[1]]
            small = min(small, table[i][query[1]])
        for i in range(query[1]+1, query[3]+1):
            table[query[2]][i-1] = table[query[2]][i]
            small = min(small, table[query[2]][i])
        for i in range(query[2]-1, query[0]-1, -1):
            table[i+1][query[3]] = table[i][query[3]]
            small = min(small, table[i][query[3]])
        for i in range(query[3]-1, query[1]-1, -1):
            table[query[0]][i+1] = table[query[0]][i]
            small = min(small, table[query[0]][i])
        table[query[0]][query[1]+1] = tmp

        answer.append(small)

    return answer


print(solution(6, 6, [[2, 2, 5, 4], [3, 3, 6, 6], [5, 1, 6, 3]]))
