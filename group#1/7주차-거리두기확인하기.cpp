// dfs를 2회 수행하거나 bfs를 2회 수행해도 되지만 이 문제는 탐색 범위도 작고, 2회만 탐색하면 되므로 반복문을 이용해 간단히 풀 수 있습니다.
// 거리두기를 지키지 않은 경우는
// 1. 맨해튼 거리가 1인 위치에 사람이 있을 경우
// 2. 맨해튼 거리가 2인 위치에 사람이 있는데, 그 사이에 빈 테이블이 있을 경우

#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 5 // 탐색 범위
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
                    
                    if(nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue; // 범위 검사
                    if(room[nx][ny] == 'P') return false; // 1번째 경우
                    else if(room[nx][ny] == 'O'){ // 빈 테이블이라면 한 칸 더 나아가기.
                        for(int l=0; l<4; l++){
                            int nnx = nx + dx[l];
                            int nny = ny + dy[l];
                            if(nnx < 0 || nnx >= SIZE || nny < 0 || nny >= SIZE) continue; // 범위 검사
                            if(nnx == i && nny == j) continue; // 기준 위치인 경우

                            if(room[nnx][nny] == 'P') return false; // 2번째 경우
                        }
                        
                    }
                    // room[nx][ny] == 'X' 라면 파티션. 파티션이 있으면 맨해튼 거리가 2라도 거리두기를 지킨 경우이므로 검사할 필요 없음.
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

