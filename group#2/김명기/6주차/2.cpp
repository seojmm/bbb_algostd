// 네트워크
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> v(n, false);
    function<void(int)> f = [&](int ix)
    {
        if (v[ix])
            return;
        v[ix] = true;
        for (int i = 0; i < n; i++)
            if (computers[ix][i])
                f(i);
    };
    for (int i = 0; i < n; i++)
        if (!v[i])
        {
            answer++;
            f(i);
        }
    return answer;
}