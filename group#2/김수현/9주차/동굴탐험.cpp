#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
bool canvisit[200000],visited[200000],tried[200000];
vector<int> adj[200000];
int tonode[200000];
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    fill(canvisit,canvisit+200000,true);
    fill(tonode,tonode+200000,-1);
    for(int i=0;i<order.size();i++){
        tonode[order[i][0]]=order[i][1];
        canvisit[order[i][1]]=false;
        if(order[i][1]==0)return false;
    }
    for(int i=0;i<path.size();i++){
        adj[path[i][0]].push_back(path[i][1]);
        adj[path[i][1]].push_back(path[i][0]);
    }
    queue<int> q;
    q.push(0);
    visited[0]=true;
    tried[0]=true;
    int count=0;
    while(!q.empty()){
        count++;
        int cur = q.front();
        q.pop();
        if(tonode[cur]!=-1){
            if(tried[tonode[cur]]&&!visited[tonode[cur]]){
                visited[tonode[cur]]=true;
                q.push(tonode[cur]);
            }else{
                canvisit[tonode[cur]]=true;
            }
        }
        for(int i=0;i<adj[cur].size();i++){
            int next = adj[cur][i];
            if(!visited[next]){
                tried[next]=true;
                if(canvisit[next]){
                    visited[next]=true;
                    q.push(next);
                }
            }
        }
    }
    return (count==n);
}
//bfs를 이용해서 노드를 탐색하고 만약 먼저 방문되야 하는 노드를 후에 방문되어야 하는 노드보다 빨리 방문했다면 후에 방문되야 하는 노드를 갈 수 있는 노드라고 체크해둔다.
//후에 방문되어야 하는 노드를 먼저 방문했다면 방문은 했지만 가지 못한 노드라고 체크해둔 후, 그 노드의 선행 노드를 방문했을 때 큐에 넣어준다.
