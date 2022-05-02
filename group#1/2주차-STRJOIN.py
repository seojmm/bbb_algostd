import sys
import heapq

input = sys.stdin.readline

c = int(input())
while c:
    n = int(input())
    arr = list(map(int, input().rstrip().split()))
    heapq.heapify(arr)
    
    cnt = 0
    for i in range(n-1):
        x = heapq.heappop(arr)
        y = heapq.heappop(arr)
        
        cnt += x + y
        heapq.heappush(arr, x + y)
        
    print(cnt)
    
    c -= 1
