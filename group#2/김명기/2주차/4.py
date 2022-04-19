# 양궁 대회

ans = [0]*11
cnt = 0
cmp = []
diff =0

def g(arr, brr):
    a,b=0,0
    for i, v  in enumerate(zip(arr, brr)):
        aa,bb=v
        if aa + bb==0:
            continue
        if aa > bb:
            a+=10-i
        else:
            b+=10-i
    return a, b

def f(arr, n, ix=0):
    global ans, cnt, diff
    cnt+=1
    
    if ix == len(arr) or n == 0:
        if n > 0:
            return
        a, b = g(arr, cmp)
        
        if a>b:
            if diff == a-b and arr[::-1] > ans[::-1] or diff < a-b:
                ans = arr
                diff = a-b
        return
    for i in range(0, n+1):
        brr = arr.copy()
        brr[ix] = i
        f(brr, n-i, ix+1)

def solution(n, info):
    global cmp
    cmp = info
    f([0]*11, n)
    if ans == [0]*11:
        return [-1]
    return ans