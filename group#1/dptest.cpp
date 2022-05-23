#include <iostream>

int dp[1001];

int main(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=4; i<=1000; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    //printf("%d\n", dp[N]);
    return 0;
}