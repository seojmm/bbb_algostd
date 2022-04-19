# 로또의 최고 순위와 최저 순위
def solution(lottos, win_nums):
    num_zeros = 0
    for i in lottos:
        if i == 0:
            num_zeros +=1
    lottos = [i for i in lottos if i]
    cnt = 0
    for i in lottos:
        if i in win_nums:
            cnt+=1
    t = [6,6,5,4,3,2,1]
    return [t[cnt+num_zeros], t[cnt]]