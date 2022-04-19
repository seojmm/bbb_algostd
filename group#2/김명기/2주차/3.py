# 주차 요금 계산

import math
def solution(fees, records):
    result = []
    a,b,c,d = fees
    data = {}
    ans = {}
    seq = set()
    for record in records:
        x,y,z = record.split()
        h, m = map(int, x.split(":"))
        t = h*60+m
        if z == "IN":
            data[y] = t
            print(y, t)
        else:
            try:
                ans[y] += t - data[y]
            except:
                ans[y] = t - data[y]
            
            data[y] = -1
        seq.add(y)
    for u in data:
        if data[u] != -1:
            try:
                ans[u] += 23*60+59 - data[u]
            except:
                ans[u] = 23*60+59 - data[u]
            data[u] = -1
    ss = list(seq)
    ss.sort()
    for s in ss:
        result.append(b+max(math.ceil((ans[s]-a)/c),0)*d)
    return result