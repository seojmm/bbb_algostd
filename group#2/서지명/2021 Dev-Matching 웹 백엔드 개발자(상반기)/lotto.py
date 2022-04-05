import sys
import collections
sys.setrecursionlimit(10**5)
input = sys.stdin.readline


def solution(lottos, win_nums):
    answer = []
    zeros = 0
    cnt = 0
    for i in range(len(lottos)):
        if lottos[i] == 0:
            zeros += 1
            continue

        if lottos[i] in win_nums:
            cnt += 1

    minMatch = cnt
    maxMatch = cnt + zeros

    if maxMatch < 2:
        answer.append(6)
    else:
        answer.append(7-maxMatch)

    if minMatch < 2:
        answer.append(6)
    else:
        answer.append(7-minMatch)

    return answer


print(solution([45, 4, 35, 20, 3, 9], [20, 9, 3, 45, 4, 35]))
