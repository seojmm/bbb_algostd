#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int N;
int dp[100001];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            if (dp[i] > dp[i - j * j] + 1)
            {
                dp[i] = dp[i - j * j] + 1;
            }
        }
    }

    printf("%d\n", dp[N]);

    return 0;
}