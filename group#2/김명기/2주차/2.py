# K진수에서 소수 개수 구하기

def prime(n):
    if n == 1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n%i==0:
            return False
    return True

def solution(n, k):
    s = ''
    while n:
        s+=str(n%k)
        n//=k
    s=s[::-1]
    arr = s.split('0')
    cnt = 0
    for i in arr:
        try:
            cnt+=prime(int(i))
        except:
            pass
    return cnt