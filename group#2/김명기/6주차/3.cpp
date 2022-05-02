// 단어 변환
#include <bits/stdc++.h>
using namespace std;

int solution(string begin, string target, vector<string> words)
{
    int answer = 987654321, n = words.size();
    vector<bool> v(n, false);
    auto f = [](string a, string b)
    {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                diff++;
        return diff == 1;
    };
    function<void(string, int)> dfs = [&](string s, int d)
    {
        if (s == target)
        {
            answer = min(answer, d);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (f(s, words[i]) && !v[i])
            {
                v[i] = true;
                dfs(words[i], d + 1);
                v[i] = false;
            }
        }
    };
    dfs(begin, 0);
    if (answer == 987654321)
        return 0;
    return answer;
}