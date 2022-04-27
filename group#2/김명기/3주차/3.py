# Dominant Character

for _ in range(int(input())):
    n = int(input())
    s = input()
    for i in ['aa', 'aba', 'aca', 'abca', 'acba', 'abbacca', 'accabba']:
        if i in s:
            print(len(i))
            break
    else:
        print(-1)