// Treelabeling

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
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1, vector<int>());
        vector<int> c(n + 1, -1);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        function<void(int, int, int)> dfs = [&](int x, int p, int ix)
        {
            c[x] = ix;
            for (auto i : g[x])
                if (i != p)
                    dfs(i, x, 1 - ix);
        };
        auto bin = [](int x)
        {
            vector<int> ret;
            while (x)
            {
                ret.push_back(x % 2);
                x /= 2;
            }
            return ret;
        };
        dfs(1, 0, 0);
        int w = 0, b = 0, s = 0;
        for (int i = 1; i <= n; i++)
            if (c[i])
                w += 1;
            else
                b += 1;
        if (w > b)
        {
            swap(w, b);
            for (int i = 1; i <= n; i++)
                c[i] = 1 - c[i];
        }
        vector<vector<int>> numbers({{}});
        vector<int> tmp;
        for (int i = 1; i <= n; i++)
        {
            if (tmp.size() == 0)
                tmp.push_back(i);
            else
            {
                if (bin(i).size() != bin(tmp[tmp.size() - 1]).size())
                {
                    numbers.push_back(tmp);
                    tmp = vector<int>({i});
                }
                else
                    tmp.push_back(i);
            }
        }
        if (tmp.size() > 0)
            numbers.push_back(tmp);
        vector<int> answer, ww, bb;
        auto www = bin(w);
        vector<bool> check(numbers.size(), false);
        for (int i = 0; i < www.size(); i++)
            if (www[i])
            {
                for (int j = 0; j < numbers[i + 1].size(); j++)
                    ww.push_back(numbers[i + 1][j]);
                check[i + 1] = true;
            }
        for (int i = 1; i < numbers.size(); i++)
            if (!check[i])
            {
                for (int j = 0; j < numbers[i].size(); j++)
                    bb.push_back(numbers[i][j]);
            }
        int wix = 0, bix = 0;
        for (int i = 1; i <= n; i++)
        {
            if (c[i] != s)
                answer.push_back(ww[wix++]);
            else
                answer.push_back(bb[bix++]);
        }
        for (auto i : answer)
            cout << i << " ";
        cout << endl;
    }
    return oOvOo;
}