#include <iostream>
using namespace std;

int N, add, sub, mul, divi = 0;
int A[12];
int MIN = 1000000000;
int MAX = -1000000000;

void dfs(int add, int sub, int mul, int divi, int x, int total){
    if(x == N){
        if(total < MIN) MIN = total;
        if(total > MAX) MAX = total;
    }

    if(add > 0) dfs(add-1, sub, mul, divi, x+1, total+A[x+1]);
    if(sub > 0) dfs(add, sub-1, mul, divi, x+1, total-A[x+1]);
    if(mul > 0) dfs(add, sub, mul-1, divi, x+1, total*A[x+1]);
    if(divi > 0) dfs(add, sub, mul, divi-1, x+1, total/A[x+1]);

}

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d %d %d %d", &add, &sub, &mul, &divi);
    dfs(add, sub, mul, divi, 1, A[1]);

    printf("%d\n%d\n", MAX, MIN);

    return 0;
}