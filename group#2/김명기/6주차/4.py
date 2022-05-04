import sys
sys.setrecursionlimit(10**6)

def solution(tickets):
    global answer
    answer = []
    s = set()
    d = {}
    rd = {}
    for i in tickets:
        for j in i:
            s.add(j)
    s = list(s)
    s.sort()
    for i in s:
        d[i] = len(d)
        rd[len(rd)] = i
    dd = {}
    for x, y in tickets:
        try:
            dd[(d[x], d[y])] += 1
        except:
            dd[(d[x], d[y])] = 1
    n = len(d)
    g = [[] for i in range(n)]
    for i in tickets:
        g[d[i[0]]].append(d[i[1]])

    def dfs(x, routes):
        global answer
        if sum(list(dd.values())) == 0:
            def cmp(a, b):
                for i, j in zip(a, b):
                    if i > j:
                        return True
                    elif i < j:
                        return False
                    else:
                        continue
                return True
            if cmp(answer, routes) or answer == []:
                answer = routes.copy()
            return

        for i in g[x]:
            if dd[(x, i)]:
                routes.append(i)
                dd[(x, i)] -= 1
                dfs(i, routes)
                routes.pop()
                dd[(x, i)] += 1
    dfs(d["ICN"], [d["ICN"]])

    return [rd[i] for i in answer]
