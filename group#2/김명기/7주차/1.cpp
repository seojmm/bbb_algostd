// 전단지 돌리기
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
    int n, s, d, answer = 0;
    cin >> n >> s >> d;
    vector<vector<int>> g(100005);
    vector<int> dp(100005);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    function<int(int, int)> dfs = [&](int ix, int p)
    {
        for (auto i : g[ix])
            if (i != p)
                dp[ix] = max(dp[ix], dfs(i, ix));
        if (dp[ix] >= d)
            answer++;
        return dp[ix] + 1;
    };
    dfs(s, 0);
    cout << max(2 * answer - 2, 0) << endl;

    return oOvOo;
}