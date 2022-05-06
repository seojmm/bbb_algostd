// dfs를 2회 수행하거나 bfs를 2회 수행해도 되지만 이 문제는 탐색 범위도 작고, 2회만 탐색하면 되므로 반복문을 이용해 간단히 풀 수 있습니다.

#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 5
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool checkRoom(vector<string> room){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(room[i][j] == 'P'){
                for(int k=0; k<4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    if(nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;
                    if(room[nx][ny] == 'P') return false;
                    else if(room[nx][ny] == 'O'){
                        for(int l=0; l<4; l++){
                            int nnx = nx + dx[l];
                            int nny = ny + dy[l];
                            if(nnx < 0 || nnx >= SIZE || nny < 0 || nny >= SIZE) continue;
                            if(nnx == i && nny == j) continue;

                            if(room[nnx][nny] == 'P') return false;
                        }
                        
                    }
                }
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0; i<SIZE; i++){
        if(checkRoom(places[i])) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}

