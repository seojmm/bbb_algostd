#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string name;
int arr[26];
int n;
int odd = -1;
string ans = "";

int main()
{
    cin >> name;
    for (int i = 0; i < name.length(); i++)
    {
        n = name[i] - 'A';
        arr[n]++;
    }

    // 홀수 2개 이상이면 return
    for (int i = 0; i < 26; i++)
    {
        if (!arr[i])
            continue;

        if (arr[i] % 2 == 1)
        {
            if (odd != -1)
            {
                printf("I'm Sorry Hansoo\n");
                return 0;
            }
            odd = i;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (!arr[i])
            continue;

        for (int j = 0; j < arr[i] / 2; j++)
        {
            ans += i + 'A';
        }
    }

    if (odd == -1)
    {
        cout << ans;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    else
    {
        cout << ans;
        ans += odd + 'A';
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    return 0;
}