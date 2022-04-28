import sys

input = sys.stdin.readline

t = int(input())
while t:
    a1, a2, a3 = map(int, input().split())
    
    tmp = abs(a1 + a3 - 2*a2)

    if tmp % 3:
        print(1)
    else:
        print(0)
            


    t -= 1