# 파괴되지 않은 건물

def solution(board, skill):
    dp = [[0]*(len(board[0])+1) for i in range(len(board)+1)]
    for s in skill:
        type, x1, y1, x2, y2, degree = s
        x2+=1
        y2+=1
        if type == 1:
            degree *= -1
        dp[x1][y1] += degree
        dp[x2][y1] += -degree
        dp[x1][y2] += -degree
        dp[x2][y2] += degree
    for i in range(1, len(board)+1):
        for j in range(len(board[0])+1):
            dp[i][j]+=dp[i-1][j]
    for i in range(len(board)+1):
        for j in range(1, len(board[0])+1):
            dp[i][j] +=dp[i][j-1]
    ans = 0
    for i in range(len(dp)-1):
        for j in range(len(dp[0])-1):
            board[i][j] += dp[i][j]
            if board[i][j] > 0:
                ans+=1
    return ans