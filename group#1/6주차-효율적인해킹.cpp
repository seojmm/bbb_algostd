#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, a, b, tmp, curMax = 0;
vector<int> graph[10001];
int visited[10001];
vector<int> ans;

void dfs(int v){
    visited[v] = 1;

    for(int i=0; i<graph[v].size(); i++){
        if(!visited[graph[v][i]]){
            tmp++;
            dfs(graph[v][i]);
        }
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    tmp++;
    visited[v] = 1;
    int node;
    
    while(!q.empty()){
        node = q.front(); q.pop();
        for(int i=0; i<graph[node].size(); i++){
            if(!visited[graph[node][i]]){
                q.push(graph[node][i]);
                tmp++;
                visited[graph[node][i]] = 1;
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);

    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        graph[b].push_back(a);
    }

    // dfs
    // for(int i=1; i<=N; i++){
    //     memset(visited, 0, sizeof(visited));
    //     tmp = 0;
    //     dfs(i);
    //     if(curMax == tmp){
    //         ans.push_back(i);
    //     }
    //     else if(tmp > curMax){
    //         curMax = tmp;
    //         ans.clear();
    //         ans.push_back(i);
    //     }
    // }

    // bfs
    for(int i=1; i<=N; i++){
        memset(visited, 0, sizeof(visited));
        tmp = 0;
        bfs(i);
        if(curMax == tmp){
            ans.push_back(i);
        }
        else if(tmp > curMax){
            curMax = tmp;
            ans.clear();
            ans.push_back(i);
        }
    }

    for(int i=0; i<ans.size(); i++){
        printf("%d ", ans[i]);
    }
    printf("\n");


    return 0;
}