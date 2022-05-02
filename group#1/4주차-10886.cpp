#include <iostream>

using namespace std;

int N, x, y;
int tmp;

int main(){
    scanf("%d", &N);
    while(N--){
        scanf("%d", &tmp);
        if(tmp) x++;
        else y++;
    }
    if(x>y) printf("Junhee is cute!");
    else printf("Junhee is not cute!");

    return 0;
}