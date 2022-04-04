# 행렬 테두리 회전하기

def solution(rows, columns, queries):
    answer = []
    arr = [[0] * columns for i in range(rows)]
    for i in range(rows * columns):
        arr[i//columns][i % columns] = i+1
    for query in queries:
        x1, y1, x2, y2 = query
        x1 -= 1
        y1 -= 1
        x2 -= 1
        y2 -= 1
        brr = [[0] * columns for i in range(rows)]
        m = 987654321
        x = x1
        for y in range(y1, y2):
            brr[x][y+1] = arr[x][y]
            m = min(m, arr[x][y])
        y = y2
        for x in range(x1, x2):
            brr[x+1][y] = arr[x][y]
            m = min(m, arr[x][y])
        x = x2
        for y in range(y2, y1, -1):
            brr[x][y-1] = arr[x][y]
            m = min(m, arr[x][y])
        y = y1
        for x in range(x2, x1, -1):
            brr[x-1][y] = arr[x][y]
            m = min(m, arr[x][y])
        for i in range(rows):
            for j in range(columns):
                if brr[i][j] != 0:
                    arr[i][j] = brr[i][j]
        answer.append(m)
    return answer