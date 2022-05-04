# 전단지 돌리기 숏코딩 1위
import sys
sys.setrecursionlimit(10**6)
n,s,d=map(int,input().split())
n+=1
g,p,a=[[]for i in range(n)],[0]*n,0
for i in range(n-2):
  x,y=map(int,input().split())
  g[x].append(y)
  g[y].append(x)
def o(j,u):
  global a
  for i in g[j]:
    if i!=u:
      p[j]=max(p[j],o(i,j))
  if p[j]>=d:
    a+=1
  return p[j]+1
o(s,0)
print(max(2*a-2,0))