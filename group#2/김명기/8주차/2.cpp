// 늑대 사냥꾼
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define endl '\n'
const int oOvOo = 0;
using ll = long long;
using namespace std;

int arr[500][500];

struct cmp
{
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b)
    {
        int aa = get<2>(a), bb = get<2>(b);
        return aa < bb;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m, sx, sy, ex, ey;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            switch (s[j])
            {
            case '.':
                arr[i][j] = 1;
                break;
            case '+':
                arr[i][j] = 2;
                break;
            case 'V':
                arr[i][j] = 3;
                sx = i, sy = j;
                break;
            case 'J':
                ex = i, ey = j;
                arr[i][j] = 4;
                break;
            }
        }
    }
    vector<vector<bool>> v(n, vector<bool>(m, false));
    vector<vector<int>> d(n, vector<int>(m, 987654321));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 2)
            {
                v[i][j] = true;
                q.push(tuple(i, j, 0));
            }

    while (!q.empty())
    {
        auto [x, y, dist] = q.front();
        d[x][y] = dist;
        q.pop();
        if (x > 0)
            if (!v[x - 1][y])
            {
                v[x - 1][y] = true;
                q.push(tuple(x - 1, y, dist + 1));
            }
        if (x < n - 1)
            if (!v[x + 1][y])
            {
                v[x + 1][y] = true;
                q.push(tuple(x + 1, y, dist + 1));
            }
        if (y > 0)
            if (!v[x][y - 1])
            {
                v[x][y - 1] = true;
                q.push(tuple(x, y - 1, dist + 1));
            }
        if (y < m - 1)
            if (!v[x][y + 1])
            {
                v[x][y + 1] = true;
                q.push(tuple(x, y + 1, dist + 1));
            }
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;
    v = vector<vector<bool>>(n, vector<bool>(m, false));
    pq.push(tuple(sx, sy, d[sx][sy]));
    v[sx][sy] = true;
    int answer = 987654321;
    while (!pq.empty())
    {
        auto [x, y, dist] = pq.top();
        pq.pop();
        answer = min(answer, dist);
        if (x == ex && y == ey)
            break;
        if (x > 0)
            if (!v[x - 1][y])
            {
                v[x - 1][y] = true;
                pq.push(tuple(x - 1, y, d[x - 1][y]));
            }
        if (x < n - 1)
            if (!v[x + 1][y])
            {
                v[x + 1][y] = true;
                pq.push(tuple(x + 1, y, d[x + 1][y]));
            }
        if (y > 0)
            if (!v[x][y - 1])
            {
                v[x][y - 1] = true;
                pq.push(tuple(x, y - 1, d[x][y - 1]));
            }
        if (y < m - 1)
            if (!v[x][y + 1])
            {
                v[x][y + 1] = true;
                pq.push(tuple(x, y + 1, d[x][y + 1]));
            }
    }
    cout << answer << endl;

    return oOvOo;
}