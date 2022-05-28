# 보석 쇼핑

def check(d, gems):
    for gem in gems:
        if d[gem] == 0:
            return False
    return True


def solution(gems):
    answer = []
    d = {}
    m = 987654321
    n = len(gems)
    s = set()
    for gem in gems:
        d[gem] = 0
    a, b = 0, 0
    while b < n:
        d[gems[b]] += 1
        s.add(gems[b])
        b += 1
        while len(s) == len(d):
            if m > b-a:
                m = b-a
                answer = [a+1, b]
            d[gems[a]] -= 1
            a += 1
            if d[gems[a-1]] == 0:
                s.remove(gems[a-1])
                break
    return answer


gems = eval(input())
print(solution(gems))
