# 신고 결과 받기

def solution(id_list, report, k):
    
    d = {}
    for i in id_list:
        d[i] = len(d)
    r = [[0] * len(d) for i in range(len(d))]
    for i in report:
        a,b = i.split()
        r[d[a]][d[b]] = 1
    l = len(d)
    answer = [0]*l
    tt = [False]*l
    for i in range(l):
        cnt = 0
        for j in range(l):
            cnt+=r[j][i]
        if cnt >= k:
            tt[d[id_list[i]]] = True
            
    for i in range(l):
        for j in range(l):
            if tt[j] and r[i][j]:
                answer[i]+=1
    
    return answer