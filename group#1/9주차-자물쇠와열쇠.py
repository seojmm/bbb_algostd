#include <string>
#include <vector>

using namespace std;

vector<vector<int>> gKey;
int M, N;

void fit(int x, int y, vector<vector<int>> graph, vector<vector<int>> key){
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            graph[x+i][y+j] += key[i][j];
        }
    }
}

void unfit(int x, int y, vector<vector<int>> graph, vector<vector<int>> key){
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            graph[x+i][y+j] -= key[i][j];
        }
    }
}

void rotate(){
    vector<vector<int>> tmp;

    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            tmp[j][M-1-i] = gKey[i][j];
        }
    }

    gKey = tmp;
}

bool check(vector<vector<int>> graph){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(graph[i+M][j+M] != 1){
                return false;
            }
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    M = key.size();
    N = lock.size();
    vector<vector<int>> graph;
    gKey = key;

    // graph 중앙에 lock 배치
    for(int i=M; i<M+N; i++){
        for(int j=M; j<M+N; j++){
            graph[i][j] = lock[i-M][j-M];
        }
    }

    for(int i=0; i<4; i++){
        rotate();
        for(int x=0; x<M+N; x++){
            for(int y=0; y<M+N; y++){
                fit(x, y, graph, key);
                if(check(graph)){
                    return true;
                }
                unfit(x, y, graph, key);
            }
        }
    }

    


    return false;
}