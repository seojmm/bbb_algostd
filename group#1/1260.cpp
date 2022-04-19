#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, V;
//int graph[1001][1001]; // 1
vector<int> v[1001]; // 2
vector<int> res_dfs;
vector<int> res_bfs;
int visited[1001];

void dfs(int start){
    if(v[start].size() == 0) return;
    
    visited[start] = 1;

    for(int i=0; i<v[start].size(); i++){
        if(visited[v[start][i]] == 0){
            res_dfs.push_back(v[start][i]);
            visited[v[start][i]] = 1;
            dfs(v[start][i]);
        }
    }

}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int x = q.front(); q.pop();
        if(v[x].size() == 0) continue;
        
        for(int i=0; i<v[x].size(); i++){
            if(visited[v[x][i]] == 0){
                visited[v[x][i]] = 1;
                q.push(v[x][i]);
                res_bfs.push_back(v[x][i]);
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &V);
    int a, b;
    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);

        // 1
        // graph[a][b] = 1;
        // graph[b][a] = 1;

        // 2
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        sort(v[i].begin(), v[i].end());
    }

    res_dfs.push_back(V);
    res_bfs.push_back(V);

    dfs(V);
    for(int i=0; i<res_dfs.size(); i++){
        printf("%d ", res_dfs[i]);
    }
    printf("\n");
    memset(visited, 0, sizeof(visited));
    bfs(V);
    for(int i=0; i<res_bfs.size(); i++){
        printf("%d ", res_bfs[i]);
    }
    printf("\n");

    return 0;
}