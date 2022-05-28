# 주사위 윷놀이
arr = list(map(int, input().split()))
path = [[0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0], [
    10, 13, 16, 19, 25, 30, 35, 40, 0], [20, 22, 24, 25, 30, 35, 40, 0], [30, 28, 27, 26, 25, 30, 35, 40, 0]]


def check(x1, y1, x2, y2):
    if path[x1][y1] == path[x2][y2] == 30:
        return x1 != 3 and y1 != 0 and x2 != 3 and y2 != 0
    return False


ans = 0
s = set()
for i in range(2**20):
    player = [[0, 0], [0, 0], [0, 0], [0, 0]]
    score = 0
    for j in range(0, 20, 2):
        current_player = bool(i & (1 << j))+bool(i & (2 << j))*2
        px, py = player[current_player]
        py = min(py + arr[j//2], len(path[px])-1)
        if px == 0 and py in [5, 10, 15]:
            px, py = py//5, 0
        for other_player in range(len(player)):
            if other_player == current_player:
                continue
            ox, oy = player[other_player]
            if ox == px and oy == py and path[px][py] or (path[px][py] == path[ox][oy] and path[px][py] in [25, 35, 40]) or check(px,py,ox,oy):
                score = -500
                break
        if score < 0:
            break
        score += path[px][py]
        player[current_player] = [px, py]
    ans = max(ans, score)
print(ans)
