#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, a, ans, tmp = 0;
int graph[101][101];
int visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    // input
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &a);
            graph[i][j] = a;
        }
    }

    // 비의 양을 늘려가면서 매 수위마다 최대 안전영역을 탐색.
    for(int lvl=0; lvl<101; lvl++){
        queue<pair<int, int>> q;
        memset(visited, 0, sizeof(visited));
        tmp = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(graph[i][j] <= lvl || visited[i][j]) continue;

                q.push({i, j});
                visited[i][j] = 1;
                tmp++;
                while(!q.empty()){
                    pair<int, int> p = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nx = p.first + dx[k];
                        int ny = p.second + dy[k];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(visited[nx][ny]) continue;
                        if(graph[nx][ny] <= lvl) continue;

                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
        if(tmp == 0) break; // 안전영역의 개수가 0 -> 모두 잠겼음 -> 더 이상 수위를 높일 필요가 없다.
        ans = max(ans, tmp);
    }

    printf("%d\n", ans);

    return 0;
}