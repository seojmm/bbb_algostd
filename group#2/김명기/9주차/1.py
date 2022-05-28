# 수식최대화

from itertools import permutations


def func(expression, op, ix=0):
    if ix == len(op):
        return int(expression)
    tokens = expression.split(op[ix])
    values = [func(token, op, ix+1) for token in tokens]
    ans = values[0]
    for value in values[1:]:
        if op[ix] == '+':
            ans+=value
        if op[ix] == '-':
            ans-=value
        if op[ix] == '*':
            ans *= value
    return ans


def solution(expression):
    answer = 0
    for i in permutations('+-*'):
        answer = max(answer, abs(func(expression, i)))
    return answer