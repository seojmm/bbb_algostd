# Dominant Character

for _ in range(int(input())):
    n = int(input())
    s = input()
    ans = -1
    for i in range(n-1):
        if s[i:i+2] == 'aa':
            ans = 2
            break
    if ans == 2:
        print(ans)
        continue
    for i in range(n-2):
        if s[i:i+3] == 'aba' or s[i:i+3] == 'aca':
            ans = 3
            break
    if ans == 3:
        print(ans)
        continue
    for i in range(n-3):
        if s[i:i+4] == 'abca' or s[i:i+4] == 'acba':
            ans = 4
            break
    if ans == 4:
        print(ans)
        continue
    for i in range(n-6):
        if s[i:i+7] == 'abbacca' or s[i:i+7] == 'accabba':
            ans = 7
            break
    if ans == 7:
        print(ans)
        continue
    print(-1)