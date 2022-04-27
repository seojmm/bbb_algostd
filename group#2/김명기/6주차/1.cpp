// 타겟 넘버
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    for (int i = 0; i < 1 << numbers.size(); i++)
    {
        int t = 0;
        for (int j = 0; j < numbers.size(); j++)
            t += (((i & (1 << j)) > 0) - 0.5f) * 2 * numbers[j];
        answer += t == target;
    }
    return answer;
}