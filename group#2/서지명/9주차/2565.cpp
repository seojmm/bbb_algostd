#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int dp[101];

int main(){
    v.push_back(make_pair(0, 0));

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());

    dp[1] = 1;

    for(int i=2; i<=n; i++){
        int tmp = 0;
        for(int j=0; j<i; j++){
            if(v[i].second > v[j].second){
                tmp = max(tmp, dp[j]);
            }
        }
        dp[i] = tmp + 1;    
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        cnt = max(cnt, dp[i]);
    }


    printf("%d\n", n-cnt);

    return 0;
}