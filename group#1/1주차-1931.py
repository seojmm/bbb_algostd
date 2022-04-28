import sys
N = int(input())
table=[]

for i in range(N):
  table.append(tuple(map(int, sys.stdin.readline().split())))

table.sort(key=lambda x: (x[1], x[0]))
ans = 0
end = 0
for x, y in table:
  if x >= end:
    end = y
    ans += 1
  

print(ans)