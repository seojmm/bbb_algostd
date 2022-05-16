// 구멍난 케이크 자르기
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
    int r, c;
    cin >> r >> c;
    int h, v;
    cin >> h;
    vector<int> hh(h);
    for (auto &i : hh)
        cin >> i;
    cin >> v;
    vector<int> vv(v);
    for (auto &i : vv)
        cin >> i;
    vv.push_back(-r);
    vv.push_back(r);
    hh.push_back(r);
    hh.push_back(-r);
    sort(hh.begin(), hh.end());
    sort(vv.begin(), vv.end());
    int answer = 0;
    for (int i = 0; i < hh.size() - 1; i++)
        for (int j = 0; j < vv.size() - 1; j++)
        {
            if (!(hh[i] >= -c && hh[i + 1] <= c && vv[j] >= -c && vv[j + 1] <= c))
                answer++;
            if (hh[i] < -c && hh[i + 1] > c && vv[j] >= -c && vv[j + 1] <= c)
                answer++;
            if (vv[j] < -c && vv[j + 1] > c && hh[i] >= -c && hh[i + 1] <= c)
                answer++;
        }
    cout << answer << endl;
    return oOvOo;
}