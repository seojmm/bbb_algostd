# 다단계 칫솔 판매

def solution(enroll, referral, seller, amount):
    d = {}
    for i in enroll:
        d[i] = len(d)
    g = [0] * len(enroll)
    for i, r in enumerate(referral):
        if r == '-':
            g[i] = -1
        else:
            g[i] = d[r]
    dp = [0] * len(enroll)
    sell = [[] for i in range(len(g))]
    for i,j in zip(seller, amount):
        sell[d[i]].append(j*100)
    
    for i in range(len(g)-1,-1,-1):
        p = g[i]
        for s in sell[i]:
            if s//10:
                sell[p].append(s//10)
            dp[i]+=s-s//10

    return dp