#include <iostream>
#include <vector>
using namespace std;

long N, B, C, cnt = 0;
long A[1000001];

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%ld", &A[i]);
    }
    scanf("%ld %ld", &B, &C);

    cnt = N;

    for(int i=0; i<N; i++){
        A[i] -= B;
        if(A[i] > 0){
            if(A[i]%C == 0){
                cnt += (A[i]/C);
            }
            else{
                cnt += (A[i]/C + 1);
            }
        }
    }

    printf("%ld\n", cnt);

    return 0;
}