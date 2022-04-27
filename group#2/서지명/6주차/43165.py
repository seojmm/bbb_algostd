import sys
sys.setrecursionlimit(10**5)


def solution(numbers, target):
    answer = 0
    def dfs(idx, cur):
        if len(numbers) == idx:
            if cur == target:
                return 1
            return 0
        
        ret = 0
        ret += dfs(idx+1, cur-numbers[idx])
        ret += dfs(idx+1, cur+numbers[idx])
        
        return ret
    
    answer = dfs(0, 0)

    return answer