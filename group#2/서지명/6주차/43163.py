import sys
import collections


def isOnlyOneDiff(s1, s2):
    cnt = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            cnt += 1

    if cnt == 1:
        return True
    else:
        return False


def solution(begin, target, words):
    answer = 0
    tmp = 0
    visited = [False]*len(words)

    def dfs(depth, word):
        if target == word:
            return depth

        ret = sys.maxsize

        for i, v in enumerate(words):
            if isOnlyOneDiff(word, v) and not visited[i]:
                visited[i] = 1
                ret = min(ret, dfs(depth+1, v))
                visited[i] = 0
        
        return ret

    if target not in words:
        answer = 0
    else:
        answer = dfs(0, begin)

    return answer


print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))