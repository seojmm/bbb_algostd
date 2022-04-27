import sys
import collections

def solution(n, k):
    word = ''

    while n:
        word += str(n%k)
        n //= k
    
    word = word[::-1]

    li = word.split('0')
    lis = []

    for i in li:
        if len(i) > 0:
            lis.append(i)
    li = list(map(int, lis))

    answer = 0
    for i in li:
        isPrime = True
        if i < 2:
            continue
        for j in range(2, int(i**0.5) + 1):
            if i%j == 0:
                isPrime = False
                break
        
        if isPrime:
            answer += 1
    
    return answer