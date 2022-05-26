#include <iostream>
#include <vector>
using namespace std;

int N, L, tmp, cnt = 0;
int board[101][101];

bool checkCol(int idx){
    bool check[N] = {false, };

    for(int i=1; i<N; i++){
        if(abs(board[i][idx]-board[i-1][idx] >= 2)) return false;
        if(board[i][idx] < board[i-1][idx]){
            if(i + L - 1 >= N) return false;
            for(int j=i; j<i+L; j++){
                if(board[j][idx] != board[i][idx] || check[j]) return false;
                check[j] = true;
            }
            i += (L-1);
        }
        if(board[i][idx] > board[i-1][idx]){
            if(i - L < 0) return false;
            for(int j=i-1; j>=i-L; j--){
                if(board[j][idx] != board[i-1][idx] || check[j]) return false;
                check[j] = true;
            }
        }
    }

    return true;
}

bool checkRow(int idx){
    bool check[N] = {false, };

    for(int i=1; i<N; i++){
        if(abs(board[idx][i]-board[idx][i-1] >= 2)) return false;
        if(board[idx][i] < board[idx][i-1]){
            if(i + L - 1 >= N) return false;
            for(int j=i; j<i+L; j++){
                if(board[idx][j] != board[idx][i] || check[j]) return false;
                check[j] = true;
            }
            i += (L-1);
        }
        if(board[idx][i] > board[idx][i-1]){
            if(i - L < 0) return false;
            for(int j=i-1; j>=i-L; j--){
                if(board[idx][j] != board[idx][i-1] || check[j]) return false;
                check[j] = true;
            }
        }
    }

    return true;
}

int main(){
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &board[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        if(checkCol(i)) cnt++;
        if(checkRow(i)) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}