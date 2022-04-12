import sys
import collections

input = sys.stdin.readline

def solution(id_list, report, k):
    answer = [0]*len(id_list)
    dicSet = collections.defaultdict(list)

    for rep in report:
        tmpArr = rep.split()
        if not tmpArr[0] in dicSet[tmpArr[1]]:
            dicSet[tmpArr[1]].append(tmpArr[0])
    
    for key, value in dicSet.items():
        if len(value) >= k:
            for name in value:
                answer[id_list.index(name)] += 1


    return answer
