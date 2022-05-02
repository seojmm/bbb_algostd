#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[200];
void solve(int temp, vector<vector<int>>& computers,int n){
    visited[temp]=true;
    queue<int> q;
    q.push(temp);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i]&&computers[cur][i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            solve(i,computers,n);
            ans++;
        }
    }
    return ans;
}
