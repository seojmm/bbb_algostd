// 아기 상어
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define endl '\n'
const int oOvOo = 0;
using ll = long long;
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, x, y, sz = 2, exp = 0, answer = 0;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 9)
            {
                x = i, y = j;
                g[i][j] = 0;
            }
        }
    while (true)
    {
        int distance = 0, mx = x, my = y, m = 987654321;
        vector<vector<int>> visited(n, vector<int>(n));
        queue<tuple<int, int, int>> q;
        q.push(tuple(x, y, distance));
        while (!q.empty())
        {
            auto [px, py, currentDistance] = q.front();
            q.pop();
            
            if (px < 0 || py < 0 || px == n || py == n || visited[px][py] || g[px][py] > sz)
                continue;
            visited[px][py] = true;
            if (g[px][py] && g[px][py] < sz)
            {
                if (m > currentDistance)
                {
                    m = currentDistance;
                    mx = px;
                    my = py;
                }
                else if (m == currentDistance)
                    if (px < mx || px == mx && py < my)
                        mx = px, my = py;
            }
            q.push(tuple(px + 1, py, currentDistance + 1));
            q.push(tuple(px - 1, py, currentDistance + 1));
            q.push(tuple(px, py + 1, currentDistance + 1));
            q.push(tuple(px, py - 1, currentDistance + 1));
        }
        if (m == 987654321)
            break;
        x = mx, y = my;
        g[x][y] = 0;
        if (sz == ++exp){
            sz++;
            exp = 0;
        }
        answer += m;
    }
    cout << answer << endl;
    return oOvOo;
}