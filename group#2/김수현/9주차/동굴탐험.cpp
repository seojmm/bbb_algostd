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
