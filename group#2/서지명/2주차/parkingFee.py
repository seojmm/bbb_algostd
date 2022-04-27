import collections

def solution(fees, records):
    answer = []
    total = collections.defaultdict(int)
    curIn = collections.defaultdict(int)
    for record in records:
        tmp = record.split()
        if tmp[2] == "IN":
            curTime = tmp[0]
            sp = curTime.split(":")
            tmpTime = 60*int(sp[0]) + int(sp[1])
            curIn[tmp[1]] = tmpTime
        else:
            curTime = tmp[0]
            sp = curTime.split(":")
            tmpTime = 60*int(sp[0]) + int(sp[1])
            total[tmp[1]] += tmpTime - int(curIn[tmp[1]])
            del curIn[tmp[1]]
    
    for key, value in curIn.items():
        total[key] += 1439 - value
    
    st = sorted(total)
    for name in st:
        f = 0
        t = total[name]
        if t > fees[0]:
            f += fees[1]
            t -= fees[0]
            if t % fees[2] > 0:
                f += (t//fees[2] + 1)*fees[3]
            else:
                f += (t//fees[2]) * fees[3]
        else:
            f = fees[1]
        
        answer.append(f)
    
    print(answer)
    
    return answer
